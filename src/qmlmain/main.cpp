#include <qguiapplication.h>
#include <qqmlapplicationengine.h>
#include <qprocess.h>

int main(int argc, char* argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine("qrc:/qml/WeChat.qml");

    const auto code = app.exec();
    if (code == 100) {
        QProcess::startDetached(app.applicationFilePath(), app.arguments());
    }
    return code;
}
