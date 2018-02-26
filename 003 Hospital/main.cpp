#include <iostream>
#include <cstdlib>
#include "pro_functions.h"


int main(int argc, char *argv[])
{

    Load_file(argc, argv);
    goto_hospital(atoi(argv[5]));

    return 0;
}
