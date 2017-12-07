//
// Created by xijun1 on 2017/12/7.
//

#include "ValidateParam.h"

using  liner::ValidateParam;

bool ValidateParam::ValidateIP(const char *flagname , const std::string  &ip) {

    //解析ip
    CHECK_GT(ip.size(),0)<<flagname<<"  "<<ip<<" : ip can not be empty.\n";

    int cnt_comma=0 ,begin=0,ind=0;

    for(;ind < ip.size() ; ind++){

        if(('.' == ip.at( ind ) || ( ind + 1 == ip.size() )) && begin != ind){

            int range = std::stoi(ip.substr( begin , ind + 1 ));

            if(range<0 || range>255){
                LOG(ERROR)<<flagname<<"  ip is valid , value（0 ， 255） ip : "<<ip.c_str()<<"\n";
            }

            begin = ind+1;
            ++cnt_comma;

        }
    }

    return  cnt_comma > 2 ? true: false;
}

bool ValidateParam::ValidatePort(const char *flagname, std::int32_t port){

    if(port > 0 && port <32768)  return true;
    LOG(ERROR)<< flagname<<"  is more than range( 0 , 32768)  port is :"<<port<<"\n";
    return false;

}

bool ValidateParam::ValidateRole(const char *flagname,const std::string  &role) {

      CHECK_GT(role.size(),0);
       //判断,统一转换成小写字母
      std::string p_role = const_cast<std::string &>(role);
       std::transform(p_role.begin(), p_role.end(), p_role.begin(), ::tolower);
       if(p_role == "worker"
          || p_role == "server"
          || p_role == "scheduler")
            return true;
    LOG(ERROR)<<flagname<<" must be among in [worker server scheduler] role : "
              <<role<<" \n";
    return false;
}

bool ValidateParam::ValidateServer(const char *flagname, std::int32_t server_id) {
    if(server_id>0) return true;
    LOG(ERROR)<<flagname<<" is valid ,it must in (0 , ~ ] server_id "
       <<server_id<<"\n";
    return false;
}

bool ValidateParam::ValidateWorker(const char *flagname, std::int32_t worker_id) {
    if(worker_id>0) return true;
    LOG(ERROR)<<flagname<<" is valid ,it must in (0 , ~ ] server_id "
              <<worker_id<<"\n";
    return false;
}
