#include <iostream>


#include "App.h"
#include "Conv.h"
#include "Log.h"

using std::cout;
using std::endl;

int main()
{
    lm::app::AutoDump();

    lm::app::SetConsoleCharsetUTF8();

    if (!lm::app::ChangeWorkPath()) {
        cout << "ChangeWorkPath failed..." << endl;
        return 1;
    }

    lm::log::Init("log/app.log", lm::log::LOG_LEVEL_DEBUG, 1024 * 1024 * 10, 3);

    {
        const auto res = lm::app::SingleApp();
        if (res != 0) {
            cout << "SingleApp: " << res << endl;
            LOG_ERROR("SingleApp: {}", res);
            return 2;
        }
    }

    return 0;
}
