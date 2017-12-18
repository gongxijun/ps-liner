//
// Created by xijun1 on 2017/12/1.
//

#include "produce_data.h"


using liner::Produce_data;

int main(int argc , char * argv[] ){

    Produce_data* produce_data = new Produce_data(2,5,20,300);
    produce_data->write();
    return EXIT_SUCCESS;
}