#include <qguiapplication.h>
#include <qqmlapplicationengine.h>
#include <qqmlcontext.h>
#include <qdir.h>
#include <qtextcodec.h>
#include <qprocess.h>
#include <qresource.h>
#include <qicon.h>
#include <qsharedmemory.h>
#include <qdebug.h>
#include "Top/config/config.h"
#include "Top/config/version.h"

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
    qputenv("QT_OPENGL", "angle");

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    app.setOrganizationName("白日做Meng技术无限公司");
    app.setApplicationName(TOP_NAME "UI");
    app.setApplicationVersion(TOP_VERSION);
    app.setWindowIcon(QIcon(":/res/TopUI.png"));

    QSharedMemory sharedMemory(app.applicationName() + app.applicationVersion());
    if (!sharedMemory.create(1, QSharedMemory::ReadWrite)) {
        qDebug() << "SingleApp";
        return 1;
    }

    if (!QDir::setCurrent(app.applicationDirPath())) {
        qDebug() << "WorkingDirectory";
        return 2;
    }

    if (!QResource::registerResource("rcc/qml.rcc")) {
        qDebug() << "registerResource qml.rcc failed";
        return 3;
    }

    QQmlApplicationEngine engine;
    engine.load("qrc:/qml/App.qml");
    if (engine.rootObjects().isEmpty()) {
        qDebug() << "QQmlApplicationEngine rootObjects isEmpty";
        return -1;
    }
    const auto code = app.exec();
    qDebug() << "detach shared memory:" << sharedMemory.detach();

    switch (code) {
    case 10: QProcess::startDetached(app.applicationFilePath(), app.arguments()); break;
    }
    return code;
}
