#include "dlcalmenu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DLCalMenu w;
    w.show();

    return a.exec();
}
