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
            Liner(){
                //使用默认参数初始化
                this->weight=0.0;
                this->bias=0.0;
                this->learining_rate=0.01;
            }
            Liner(int w ,int b,double learning_rate):weight(w),
                                                     bias(b),
                                                     learining_rate(learning_rate){};
            ~Liner(){};

            std::vector<std::pair<double,double>>
            forward(std::vector<double> x ,std::vector<double> y){
               //计算w*x +b ;
               std::vector<double> pred_y;
               typedef typename std::vector<double>::iterator v_iter;
               for(v_iter  ite = x.begin(); ite<x.end();ite++){
                   pred_y.push_back(this->weight * (*ite) + this->bias);
                   DLOG(INFO)<<"pred_x: "<<*ite<<"  pred_y: "<<this->weight * (*ite) + this->bias<<std::endl;
               }
               //计算偏差 绝对值偏差
               CHECK_EQ(pred_y.size(), static_cast<unsigned long>(y.size()));
               std::vector<double> loss;
               for(int i=0 ; i < pred_y.size() ; i++ ){

                   loss.push_back(std::fabs(pred_y[i] - y[i]));
               }
               //计算梯度
               CHECK_EQ(loss.size(),x.size())<<"loss size is not equal x";
               std::vector<std::pair<double, double>> grad;
               grad.push_back( { this->weight , this->bias } );  //首先放置w,b到里面
               //std::vector<double> grad_b(loss.size());
               for(int i=0; i< loss.size(); i++){
                   //loss[i]*x[i];   //w的梯度 loss * w' * w;
                   //grad_b[i]=loss[i];
                   grad.push_back({((pred_y[i] - y[i]))*x[i],(pred_y[i] - y[i])});
               }
                return grad;
            }
            //update 权重 w,b
            void backward(double grad_w , double grad_b){
                //std::cout<<" gw "<<grad_w<<"  gb "<<grad_b<<std::endl;
                this->weight += ( -1 * this->learining_rate * grad_w );
                this->bias += ( -1 * this->learining_rate * grad_b );
                //std::cout<<"this->weight: "<<this->weight<<" ab :"<<this->bias<<std::endl;
            }

            void setWeight(double w){
                this->weight =w;
            }

            void setBias(double b){
                this->bias = b;
            }
            double getWeight(){
                return this->weight;
            }
            double getBias(){
                return this->bias;
            }

            void setRate(double r){
                this->learining_rate = r;
            }

        private:
            double  weight;
            double  bias;
            double  learining_rate ;
        };
    }
}

#endif //PSLITE_LINER_H
