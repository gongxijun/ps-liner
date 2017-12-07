//
// Created by xijun1 on 2017/12/3.
//

#ifndef PSLITE_ENV_H
#define PSLITE_ENV_H
#include<boost/property_tree/ptree.hpp>
#include<boost/property_tree/ini_parser.hpp>
#include "base.h"
namespace liner {
    /**
     * 环境变量结构体
     */
    struct Env {
        void initEnv(std::string env_path = "/Users/sina/github/liner/etc/env.conf") {
            //搜索配置文件路径
            boost::property_tree::ptree ptr;
            boost::property_tree::ini_parser::read_ini(env_path, ptr);
            std::string name;

            for (auto &v : ptr) {
                std::cout << v.first << std::endl;
                for (auto &s : v.second) {
                    name = v.first + "_" + s.first; //组合数据名
                    //映射
                    if (name == "ps_worker_num") {
                        this->ps_worker_num = std::stoi(s.second.data().c_str());
                    } else if (name == "ps_server_num") {
                        this->ps_server_num = std::stoi(s.second.data().c_str());
                    } else if (name == "data_file_type") {
                        this->data_file_type = s.second.data();
                    } else if (name == "data_divide_flag") {
                        this->data_divide_flag = s.second.data();
                    } else if (name == "data_file_path") {
                        this->data_file_path = s.second.data();
                    } else if (name == "data_file_pre") {
                        this->data_file_pre = s.second.data();
                    }
                    std::cout << s.first << "    : " << s.second.data() << std::endl;
                }
            }
        }

        int ps_worker_num;
        int ps_server_num;
        std::string data_file_type; //文件保存方式
        std::string data_divide_flag; //内容分隔符号
        std::string data_file_pre; //内容文件前缀
        std::string data_file_path; //文件保存路径

    };
}
#endif //PSLITE_ENV_H
