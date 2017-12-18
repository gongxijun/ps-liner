//
// Created by xijun1 on 2017/11/30.
//

#include "ps/ps.h"
#include "env.h"
#include"liner.h"
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
#include "ValidateParam.h"
#include <stack>
using namespace std;

template<typename Val>
struct KVServerHandle {
    //void operator()() function
    void operator()(
            const ps::KVMeta &req_meta,
            const ps::KVPairs<Val> &req_data,
            ps::KVServer<Val> *server) {

        size_t n = req_data.keys.size();
        ps::KVPairs<Val> res;

        if (req_meta.push) {
            double m_grad_w = 0., m_grad_b = 0.;
            MergerParam mergerParam;
            size_t var_size =req_data.vals.size();
            CHECK_EQ(var_size,n) << "the size of re_data.keys is not equal re_data.vals' size";
            for (size_t i = 0; i < n; i += 2) {
                ps::Key key = req_data.keys[i];
                //std::cout << " n: " << n << "执行push操作，sum" << std::endl;
                if (i < 2) {
                    liner1.setWeight(req_data.vals[i]);
                    liner1.setBias(req_data.vals[i + 1]);
                    continue;
                }
                //求grad_w,grad_b的平均值
                m_grad_w += req_data.vals[i];
                m_grad_b += req_data.vals[i + 1];
            }
            mergerParam.init(m_grad_w,m_grad_b,n-2,req_meta);
            merger_params.insert(std::make_pair(req_meta.sender,mergerParam));
            LOG(INFO)<<"ps::sender : "<<req_meta.sender<<"  merger_params: size = "
                     <<merger_params.size()<<" ps::NumWorkers() : "
                     <<ps::NumWorkers()<<std::endl;

            //if(merger_params.size() == static_cast<size_t>(ps::NumWorkers()))
            {

                //求grad_w,grad_b的平均值
                double t_grad_w=0.0 , t_grad_b=0.0,t_batch=0;

                for(auto merger_it : merger_params){
                    LOG(INFO)<<"worker_id :"<<merger_it.first
                             <<"  grad_w : "<<merger_it.second.w
                             <<"  grad_b : "<<merger_it.second.b
                             <<" batich : "<<merger_it.second.batch
                             <<"  \n";
                    t_grad_w+=merger_it.second.w;
                    t_grad_b+=merger_it.second.b;
                    t_batch+= merger_it.second.batch;
                }
                //计算梯度
                t_grad_w /= t_batch;
                t_grad_b /= t_batch;
                liner1.backward(t_grad_w,t_grad_b);
                //保存那些
                for (auto merger_it : merger_params) {
                    server->Response(merger_it.second.req_meta);
                    std::cout<<"Debug: <-------> responId:  "<<req_meta.sender<<std::endl;
                }
                //清理缓存的数据
                merger_params.clear();
            }
            //server->Response(req_meta, res); //响应请求
        } else {
            res.keys = req_data.keys;
            res.vals.resize(2);
            //std::cout<<"执行pull操作,store"<<std::endl;
            LOG(INFO) << "pull_w: " << liner1.getWeight() << " pull_b: " << liner1.getBias() << std::endl;
            res.vals.push_back(liner1.getWeight());
            res.vals.push_back(liner1.getBias());
            server->Response(req_meta, res); //响应请求
        }

    }

    struct MergerParam{

        void init(double w , double b, size_t batch,ps::KVMeta req_meta){
            this->w = w;
            this->b = b;
            this->batch = batch;
            this->req_meta = req_meta;
        }
        double w ;
        double b;
        size_t batch;
        ps::KVMeta req_meta;

    };
    typedef  int WorkerId;
    liner::net::Liner liner1;
    //用來存放各個worker請求的參數
    std::unordered_map<WorkerId,MergerParam> merger_params;

};

void StartServer() {

    if (!ps::IsServer()) return;
    LOG(INFO) << "启动Server \n";
    auto server = new ps::KVServer<float>(0);
    server->set_request_handle(KVServerHandle<float>());
    ps::RegisterExitCallback([server]() { delete server; });

}

void StartWorker() {

    int epoch = 1;
    int epoch_iter = 0;
    if (!ps::IsWorker()) return;
    LOG(INFO) << "启动Worker woker_id = " << ps::MyRank() << "\n";
    ps::KVWorker<float> kv(0);
//加载数据
    liner::Env env;
    env.initEnv();
    // init data
    std::string file_path = env.data_file_path + '/' + env.data_file_pre.c_str() + '_'
                            + std::to_string(ps::MyRank()) + "." + env.data_file_type;
    //定义网络
    liner::net::Liner liner1;
    //获取server节点的个数,动态分配数据
    std::string val =  CHECK_NOTNULL(ps::Environment::Get()->find("DMLC_NUM_SERVER"));
    int num_server_ = std::stoi(val);

    while (++epoch_iter <= epoch) {
        //epoch
        //打开文件读取数据

        std::fstream raw_read(file_path, std::ios_base::in);
        if(!raw_read.is_open()){
            LOG(ERROR)<<file_path<<" :  the feature data load open fails.";
            return ;
        }
        std::string raw_data;
        std::vector<double> t_x ,t_y;
        while (getline(raw_read, raw_data)) {
            //解析数据 a1 b1,a2 b2 格式
            vector<string> v_raw;
            boost::split(v_raw, raw_data, boost::is_any_of(env.data_divide_flag), boost::token_compress_on);
            uint64_t server_seq_len = std::numeric_limits<uint64_t>::max()/num_server_;
            for (vector<string>::iterator it = v_raw.begin(); it < v_raw.end(); it += 20) {
                //设置批次
                t_x.clear();
                t_y.clear();
                for(vector<string>::iterator sit = it ; sit<it+20 && sit<v_raw.end();sit+=2){
                    t_x.push_back(std::stod(*sit));
                    t_y.push_back(std::stod(*(sit + 1)));
                }
                std::vector<std::pair<double, double>> t_grad = liner1.forward(t_x, t_y);
                //数据转化
                std::vector<ps::Key> keys;
                ps::Key key = it - v_raw.begin();
                key = (server_seq_len*(key%num_server_ + 1) - key);
                std::vector<float> v_wb;
                for (auto it_p :t_grad) {
                    keys.push_back(key);
                    v_wb.push_back(static_cast<float >(it_p.first));
                    keys.push_back(key);
                    v_wb.push_back(static_cast<float>(it_p.second));
                }

                kv.Wait(kv.Push(keys, v_wb)); //等待执行完
                ps::Postoffice::Get()->Barrier(ps::kWorkerGroup);
                //Pull参数
                std::vector<float> rets;
                kv.Wait(kv.Pull(keys, &rets));

                //@TODO
                size_t rets_size = rets.size();
                liner1.setWeight(rets[rets_size - 2]);
                liner1.setBias(rets[rets_size - 1]);

                LOG(INFO) << "\nworker_id  :" << std::to_string(ps::MyRank()) << "  w: " << liner1.getWeight()
                          << "  b: " << liner1.getBias() << std::endl;
            }
        }
    }
    LOG(INFO) << "结束\n";
}



/*应该将环境变量改成配置文件*/

DEFINE_int32(num_worker ,0 , "the number of worker for run");
DEFINE_int32(num_server , 0 , "the number of server for run");
DEFINE_string(role , "worker" , "the character of program.");
DEFINE_int32(port , 8000 , "socket port with comunation each other");
DEFINE_string(ip,"127.0.0.1","the ip for scheduler");

using liner::ValidateParam;

int main(int argc, char *argv[]) {

    std::unordered_map<std::string, std::string> env;

    gflags::SetVersionString("1.0.0.0");
    std::string usage("This program run with param ,example:\n");

    usage+="use format:\n"+std::string(argv[0])+
           "  --num_worker 1\n"
                   "  --num_server 1\n"
                   "  --role worker\n"
                   "  --port 8000\n"
                   "  --ip 127.0.0.1\n"
                   "or -flagfile==config.ini";

    gflags::SetUsageMessage(usage);
    gflags::ParseCommandLineFlags(&argc,&argv,true);
    bool valid_ip = gflags::RegisterFlagValidator(&FLAGS_ip,&(ValidateParam::ValidateIP));
    bool valid_role = gflags::RegisterFlagValidator(&FLAGS_role,&(ValidateParam::ValidateRole));
    bool valid_server = gflags::RegisterFlagValidator(&FLAGS_num_server,&ValidateParam::ValidateServer);
    bool valid_worker = gflags::RegisterFlagValidator(&FLAGS_num_worker,&ValidateParam::ValidateWorker);
    bool valid_port = gflags::RegisterFlagValidator(&FLAGS_port,&ValidateParam::ValidatePort);
    bool flag = valid_ip && valid_port && valid_role && valid_server && valid_worker;

    if(!flag){
        //如果存在不合法参数,退出
        LOG(ERROR)<<"输入的参数不和法!\n";
        return EXIT_FAILURE;
    }
    liner::Env env_var;
    env_var.initEnv();
    if((FLAGS_num_server&FLAGS_num_worker)){
        env["DMLC_NUM_WORKER"] = std::to_string(FLAGS_num_worker);
        env["DMLC_NUM_SERVER"] = std::to_string(FLAGS_num_server);
    }else{
        env["DMLC_NUM_WORKER"] = env_var.ps_worker_num;
        env["DMLC_NUM_SERVER"] = env_var.ps_server_num;
    }

    LOG(INFO)<<"worker_num is "<<env["DMLC_NUM_WORKER"]
             <<"\t"<<"server_num is "
             <<env["DMLC_NUM_SERVER"]<<"\t";

    env["DMLC_ROLE"] = FLAGS_role;  //[worker,server,scheduler]
    env["PS_VERBOSE"] = "0";
    env["DMLC_PS_ROOT_URI"] = FLAGS_ip;
    env["DMLC_PS_ROOT_PORT"] = std::to_string(FLAGS_port);
    ps::Environment::Init(env);

    // setup server nodes
    StartServer();
    // start system
    ps::Start();
    // run worker nodes
    StartWorker();
    // stop system
    ps::Finalize();

    return 0;
}