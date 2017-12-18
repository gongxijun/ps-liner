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
        Produce_data();
        Produce_data(int w , int b , int max_x,int file_max);
        ~Produce_data();
        std::pair<double ,double > getSrandX_Y();
        int write();

    private:

        int weight; //权重
        int bias ; //偏置
        int max_x; //最大范围
        int file_max ; //每个文件最大的数据量
    };

}// namespace liner
#endif //PSLITE_PRODUCE_DATA_H
