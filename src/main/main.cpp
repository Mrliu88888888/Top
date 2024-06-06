#include "top/config/config.h"
#include "top/config/version.h"
#include <iostream>

int main(int argc, char* argv[])
{
    std::cout << "hello " << TOP_NAME << ": " << TOP_VERSION << std::endl;
    return 0;
}
