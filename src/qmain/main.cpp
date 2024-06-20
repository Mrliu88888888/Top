#include <qapplication.h>
#include <qwidget.h>
#include <qtextcodec.h>

#include "top/config/config.h"
#include "top/config/version.h"

#include "App.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    app.setApplicationName(TOP_NAME);
    app.setApplicationVersion(TOP_VERSION);

#ifdef _WIN32
    lm::app::AutoDump();
#endif   // _WIN32

    if (lm::app::SingleApp() != 0) {
        return 1;
    }

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    if (!lm::app::ChangeWorkPath()) {
        return 2;
    }

    QWidget w;
    w.show();

    return app.exec();
}
