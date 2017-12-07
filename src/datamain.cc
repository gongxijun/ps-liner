//
// Created by xijun1 on 2017/12/1.
//

#include "produce_data.h"



int _main(int argc , char * argv[] ){
    liner::Produce_data produce_data(2,5,20,300);
    produce_data.write();
    return EXIT_SUCCESS;
}