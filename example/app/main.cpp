#include <iostream>

#include "Top/config/version.h"
#include "Log.h"

using std::cout;
using std::endl;

int main()
{
    lm::log::InitForSize("log/app.log", lm::log::LOG_LEVEL_DEBUG, 1024 * 1024 * 10, 3);

    cout << "top app version: " << TOP_VERSION << endl;
    LOG_INFO("top app version: {}, {}-{}-{}",
             TOP_VERSION,
             TOP_VERSION_MAJOR,
             TOP_VERSION_MINOR,
             TOP_VERSION_PATCH);

    return 0;
}
