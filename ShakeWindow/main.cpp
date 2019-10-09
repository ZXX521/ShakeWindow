#include "shakewindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ShakeWindow w;
    w.show();

    w.SetInterval(10);
    w.SetDuration(100);
    w.SetSpace(3);
    w.ShakeOnce();

    return a.exec();
}
