#include <iostream>

#include "top/config/version.h"
#include "App.h"
#include "Conv.h"
#include "Log.h"

using std::cout;
using std::endl;

int main()
{
#ifdef _WIN32
    lm::app::AutoDump();

    lm::app::SetConsoleCharsetUTF8();
#endif   // _WIN32

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

    cout << "top app version: " << TOP_VERSION << endl;
    LOG_INFO("top app version: {}, {}-{}-{}",
             TOP_VERSION,
             TOP_VERSION_MAJOR,
             TOP_VERSION_MINOR,
             TOP_VERSION_PATCH);

    return 0;
}
