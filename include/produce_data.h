//
// Created by xijun1 on 2017/12/1.
//

#ifndef PSLITE_PRODUCE_DATA_H
#define PSLITE_PRODUCE_DATA_H

#include <my_sys.h>
#include<glog/logging.h>
#include<fstream>
#include"base.h"
#include "env.h"
namespace liner {


/**
 * 参数数据，我们定义一个目标函数f(x) = 2x + 5;
 */
    class Produce_data {

    public:
        Produce_data(){
            std::srand( ( unsigned ) time( NULL ) ) ;
        };
        Produce_data(int w , int b , int max_x,int file_max)
                :weight(w), bias(b) ,max_x(max_x),file_max(file_max){
        };
        ~Produce_data(){}
        std::pair<double ,double > getSrandX_Y(){
            double x = static_cast< double >( std::rand() % this->max_x );

            //增加noisy
            double y = (( x)*this->weight)+this->bias + (std::rand() / double(RAND_MAX))*NOSISY_FACTOR;

            return std::pair<double,double>(x,y);
        };
        int write(){
            Env env;
            env.initEnv();
            std::string file_path ;
            //std::cout<<"  this->file_max : "<<this->file_max;
            for(int i=0 ; i < env.ps_worker_num ; ++i ){
                file_path=env.data_file_path+'/'+env.data_file_pre.c_str()+'_'
                          +std::to_string(i);
                //@todo 文件类型
                file_path+="."+env.data_file_type;
                std::fstream out(file_path,std::ios_base::out);

                if(!out.is_open()){
                    std::cerr<<__FILE__<<": function:  "<<__func__<<
                             "   line: "<<__LINE__<<" file: {  "
                             <<file_path<<"  }  "<<" open failed !"<<std::endl;
                    return EXIT_FAILURE;
                }
                int raw_count=0; //每一行进行统计
#ifdef DEBUG
                std::cout<<"  this->file_max : "<<this->file_max;
#endif

                for( int data_num =0 ; data_num < this->file_max ; ++data_num){
                    std::pair<double ,double> kv = this->getSrandX_Y();
                    out<<kv.first<<env.data_divide_flag.at(0)<<kv.second;
#ifdef DEBUG
                    std::cout<<kv.first<<std::ends<<kv.second<<std::endl;
#endif
                    if((data_num == 0 || 0 != data_num%80) && ( data_num + 1 != this->file_max))
                        out<<env.data_divide_flag.at(1);
                    if((0 == data_num%80)&&(data_num!=0)){
                        out<<std::endl;
                        raw_count=0;
                    }
                    ++raw_count;
                }
                out.close();
            }
            return EXIT_SUCCESS;
        };

    private:

        int weight; //权重
        int bias ; //偏置
        int max_x; //最大范围
        int file_max ; //每个文件最大的数据量
    };

}
#endif //PSLITE_PRODUCE_DATA_H
