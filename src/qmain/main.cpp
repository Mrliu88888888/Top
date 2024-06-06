#include "top/config/config.h"
#include "top/config/version.h"
#include <qapplication.h>
#include <qwidget.h>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    app.setApplicationName(TOP_NAME);
    app.setApplicationVersion(TOP_VERSION);

    QWidget w;
    w.show();

    return app.exec();
}
