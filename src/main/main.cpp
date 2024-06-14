#include <iostream>

#include "top/config/config.h"
#include "top/config/version.h"

#include "App.h"

#include "pcm.h"

int main(int argc, char* argv[])
{
    lm::app::AutoDump();

    if (lm::app::SingleApp() != 0) {
        return 1;
    }

    lm::app::SetConsoleCharsetUTF8();

    if (!lm::app::ChangeWorkPath()) {
        return 2;
    }

    std::cout << "hello " << TOP_NAME << ": " << TOP_VERSION << std::endl;

    pcm::run();

    return 0;
}
