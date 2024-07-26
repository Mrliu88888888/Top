#include <qguiapplication.h>
#include <qqmlapplicationengine.h>
#include <qprocess.h>

int main(int argc, char* argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setAttribute(Qt::AA_UseSoftwareOpenGL);

    QGuiApplication app(argc, argv);

    app.setOrganizationName("TopStudio");
    app.setOrganizationDomain("TopStudio");
    app.setApplicationName("Top");

    QQmlApplicationEngine engine("qrc:/qml/WeChat.qml");
    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    const auto code = app.exec();
    if (code == 100) {
        QProcess::startDetached(app.applicationFilePath(), app.arguments());
    }
    return code;
}
