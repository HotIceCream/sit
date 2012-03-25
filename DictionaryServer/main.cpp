#include <QtCore/QCoreApplication>
#include "myserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MyServer *server = new MyServer();
    server->startServer();

    return a.exec();
}
