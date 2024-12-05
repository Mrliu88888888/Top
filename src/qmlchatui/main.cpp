#include <qguiapplication.h>
#include <qqmlapplicationengine.h>
#include <qqmlcontext.h>
#include <qprocess.h>
#include <qtimer.h>
#include <qdebug.h>
#include "ChatListModel/ChatListModel.h"
#include "FpsItem/FpsItem.h"

int main(int argc, char* argv[])
{
    qputenv("QT_OPENGL", "angle");

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    app.setOrganizationName("TopStudio");
    app.setOrganizationDomain("TopStudio");
    app.setApplicationName("Top");

    ChatListModel chatListModel;
    for (int i = 0; i < 100; ++i) {
        chatListModel.addChat("小孟同学", "居居 居居");
    }

    qmlRegisterType<FpsItem>("Top", 1, 0, "FpsItem");

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
