//Author: Rookie118
//Program's Propose: A medical center's simulation
//Completion time: 2017-11-08

#include <iostream>
#include <cstdlib>
#include "pro_functions.h"


int main(int argc, char *argv[])
{

    Load_file(argc, argv);  //读取Ailments,Doctors,Patients和reatments文本文件
    goto_hospital(atoi(argv[5]));  //开始进行诊断

    return 0;
}
