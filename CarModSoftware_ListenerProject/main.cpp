#include "system.h"
#include <QApplication>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    System w;
    w.show();

    return a.exec();
}
