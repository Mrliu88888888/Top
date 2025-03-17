#include <iostream>

#include "Top/config/version.h"
#include "Log.h"

using std::cout;
using std::endl;

int main()
{
    lm::log::Init("log/app.log", spdlog::level::level_enum::info, 1);

    cout << "top app version: " << TOP_VERSION << endl;
    LOG_INFO("top app version: {}, {}-{}-{}",
             TOP_VERSION,
             TOP_VERSION_MAJOR,
             TOP_VERSION_MINOR,
             TOP_VERSION_PATCH);

    return 0;
}
