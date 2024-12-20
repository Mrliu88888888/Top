#include <iostream>

#include <SimpleIni.h>

#include "Top/config/config.h"
#include "Top/config/version.h"

#include "App.h"

// #include "pcm.h"
// #include "mnew.h"
#include "connpool.h"

struct Config
{
    explicit Config();

    void print() const;

    std::string ip;
    int         port;

    static Config Parse(int argc, char* argv[]);
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

#ifdef ENABLE_CONNPOOL
    connpool::run();
#endif

    return 0;
}

Config::Config()
    : port(0)
{}

void Config::print() const
{
    using std::cout;
    using std::endl;

    cout << "ip  : " << ip << endl;
    cout << "port: " << port << endl;
}

Config Config::Parse(int argc, char* argv[])
{
    Config      conf;
    const auto  filename = (2 == argc) ? argv[1] : "conf/top.ini";
    CSimpleIniA ini;
    if (SI_OK == ini.LoadFile(filename)) {
        conf.ip   = ini.GetValue("", "ip", "127.0.0.1");
        conf.port = ini.GetLongValue("", "port", 0);
    }
    return conf;
}
