#include <qapplication.h>
#include <qwidget.h>
#include <qtextcodec.h>
#include <qresource.h>
#include <qicon.h>
#include <qfile.h>
#include <qdir.h>
#include <qcommandlineparser.h>
#include <qcommandlineoption.h>
#include <qmessagebox.h>

#include "Top/config/config.h"
#include "Top/config/version.h"

struct Config
{
    explicit Config()
        : isTest(false)
        , nTest(0)
    {}

    bool    isTest;
    int     nTest;
    QString strTest;

    static Config Parse();
};

/*
 *                        _oo0oo_
 *                       o8888888o
 *                       88" . "88
 *                       (| -_- |)
 *                       0\  =  /0
 *                     ___/`---'\___
 *                   .' \\|     |// '.
 *                  / \\|||  :  |||// \
 *                 / _||||| -:- |||||- \
 *                |   | \\\  - /// |   |
 *                | \_|  ''\---/''  |_/ |
 *                \  .-\__  '-'  ___/-. /
 *              ___'. .'  /--.--\  `. .'___
 *           ."" '<  `.___\_<|>_/___.' >' "".
 *          | | :  `- \`.;`\ _ /`;.`/ - ` : | |
 *          \  \ `_.   \_ __\ /__ _/   .-` /  /
 *      =====`-.____`.___ \_____/___.-`___.-'=====
 *                        `=---='
 *
 *
 *      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 *            佛祖保佑       永不宕机     永无BUG
 */
int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    app.setApplicationName(TOP_NAME);
    app.setApplicationVersion(TOP_VERSION);

    // 切换工作目录
    if (!QDir::setCurrent(app.applicationDirPath())) {
        return 2;
    }

    // 加载资源
    if (QResource::registerResource("rcc/app.rcc")) {
        // 设置LOGO
        app.setWindowIcon(QIcon(":/res/logo.png"));

        // 加载QSS样式
        QFile f(":/res/qss/Aqua.qss");
        if (f.open(QIODevice::ReadOnly)) {
            app.setStyleSheet(f.readAll());
            f.close();
        }
    }

    const auto conf = Config::Parse();

    QWidget w;
    w.show();

    return app.exec();
}


Config Config::Parse()
{
    Config conf;

    QCommandLineParser parser;
    QCommandLineOption optHelp(QStringList() << "h"
                                             << "help",
                               "显示帮助");
    QCommandLineOption optBoolTest(QStringList() << "b"
                                                 << "bool",
                                   "test bool arg");
    QCommandLineOption optNumberTest(QStringList() << "n"
                                                   << "number",
                                     "test int arg",
                                     "0");
    QCommandLineOption optStringTest(QStringList() << "s"
                                                   << "string",
                                     "test string arg",
                                     "");

    parser.addOption(optHelp);
    parser.addOption(optBoolTest);
    parser.addOption(optNumberTest);
    parser.addOption(optStringTest);

    parser.process(*qApp);
    if (parser.isSet(optHelp)) {
        parser.showHelp(1);
    }

    conf.isTest  = parser.isSet(optBoolTest);
    conf.nTest   = parser.value(optNumberTest).toInt();
    conf.strTest = parser.value(optStringTest);

    return conf;
}
