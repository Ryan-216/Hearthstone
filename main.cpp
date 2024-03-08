#include "Hearthstone.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Hearthstone w;
    w.show();
    return a.exec();
}
