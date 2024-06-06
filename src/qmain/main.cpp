#include <qapplication.h>
#include <qwidget.h>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    app.setApplicationName("Top");

    QWidget w;
    w.show();

    return app.exec();
}
