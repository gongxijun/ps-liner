//
// Created by xijun1 on 2017/12/3.
//

#ifndef PSLITE_LINER_H
#define PSLITE_LINER_H
#include<cmath>
#include "base.h"
namespace liner{
    namespace net{

        class Liner{
        public:
            Liner();
            Liner(int w ,int b,double learning_rate);
            ~Liner();

            std::vector<std::pair<double,double>>
            forward(std::vector<double> x ,std::vector<double> y);
            //update 权重 w,b
            void backward(double grad_w , double grad_b);
            void setWeight(double w);

            void setBias(double b);
            double getWeight();
            double getBias();
            void setRate(double r);

        private:
            double  weight;
            double  bias;
            double  learining_rate ;
        };
    }
}

#endif //PSLITE_LINER_H
