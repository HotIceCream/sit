#ifndef CLIENTUSER_H
#define CLIENTUSER_H

#include <QtNetwork>

class MyServer;

class ClientUser : QObject
{
    Q_OBJECT
public:
    explicit ClientUser(QObject *parent = 0);
    ClientUser(const ClientUser&);
    ClientUser(MyServer *server, int socketfd, QMap<QString, QString> *d);
    QString userLogin;
    ClientUser& operator=(const ClientUser&);
private:
    QTcpSocket *socket;
    MyServer *server;
    QMap<QString, QString> *dictionary;
    QByteArray* getListUsers();
signals:

public slots:
    void readyRead();
    void userDisconnected();
};

#endif // CLIENTUSER_H
