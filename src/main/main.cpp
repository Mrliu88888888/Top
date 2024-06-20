#include <iostream>

#include <SimpleIni.h>

#include "top/config/config.h"
#include "top/config/version.h"

#include "App.h"

#include "pcm.h"
#include "mnew.h"

struct Config
{
    explicit Config()
        : port(0)
    {}

    std::string ip;
    int         port;

    void print() const
    {
        using std::cout;
        using std::endl;

        cout << "ip  : " << ip << endl;
        cout << "port: " << port << endl;
    }

    static Config Parse(int argc, char* argv[])
    {
        Config conf;

        const auto filename = (2 == argc) ? argv[1] : "conf/top.ini";
        // if (!std::filesystem::exists(filename)) {
        //     std::cout << filename << " file not exists" << std::endl;
        //     return conf;
        // }

        CSimpleIniA ini;
        if (SI_OK == ini.LoadFile(filename)) {
            conf.ip   = ini.GetValue("", "ip", "127.0.0.1");
            conf.port = ini.GetLongValue("", "port", 0);
        }
        return conf;
    }
};

int main(int argc, char* argv[])
{
#ifdef _WIN32
    lm::app::AutoDump();

    lm::app::SetConsoleCharsetUTF8();
#endif   // _WIN32

    if (lm::app::SingleApp() != 0) {
        return 1;
    }

    if (!lm::app::ChangeWorkPath()) {
        return 2;
    }

    std::cout << "hello " << TOP_NAME << ": " << TOP_VERSION << std::endl;

    const auto conf = Config::Parse(argc, argv);
    conf.print();

#ifdef ENABLE_PCM
    pcm::run();
#endif

#ifdef ENABLE_MNEW
    mnew::run();
#endif

    return 0;
}
