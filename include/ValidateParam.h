//
// Created by xijun1 on 2017/12/7.
//

#ifndef LINER_VALIDATEPARAM_H
#define LINER_VALIDATEPARAM_H

#include <string>
#include "glog/logging.h"

namespace  liner {

    class ValidateParam {

    public:
        enum {worker,server,scheduler};

        static bool ValidatePort(const char* flagname, std::int32_t port);

        static bool ValidateRole(const char * flagname,const std::string &role);
        static bool ValidateIP(const char* flagname, const std::string  &ip);

        static bool ValidateWorker(const char * flagname , std::int32_t worker_id);

        static bool ValidateServer(const char * flagname , std::int32_t server_id);
    };
}


#endif //LINER_VALIDATEPARAM_H
