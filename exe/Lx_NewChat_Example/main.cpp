#include "Lx_NewChat.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Q_INIT_RESOURCE(NewChat);
    Lx_NewChat w;
    w.show();
    return a.exec();
}
