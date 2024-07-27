#include <qguiapplication.h>
#include <qqmlapplicationengine.h>
#include <qqmlcontext.h>
#include <qprocess.h>
#include <qtimer.h>
#include <qdebug.h>
#include "ChatListModel.h"

int main(int argc, char* argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setAttribute(Qt::AA_UseSoftwareOpenGL);

    QGuiApplication app(argc, argv);

    app.setOrganizationName("TopStudio");
    app.setOrganizationDomain("TopStudio");
    app.setApplicationName("Top");

    ChatListModel chatListModel;
    chatListModel.addChat("小孟同学", "居居 居居");

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("chatListModel", &chatListModel);
    engine.load("qrc:/qml/WeChat.qml");
    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    qDebug() << "&chatListModel: " << &chatListModel;
    QTimer tmr;
    QObject::connect(
        &tmr, &QTimer::timeout, [&chatListModel]() { chatListModel.addChat("jane", "hello"); });
    tmr.start(1000 * 10);

    const auto code = app.exec();
    if (code == 100) {
        QProcess::startDetached(app.applicationFilePath(), app.arguments());
    }
    return code;
}
