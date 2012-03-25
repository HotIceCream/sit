#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <QMap>
#define FILE_NAME "file.txt"

class ClientUser;
class MyServer : public QTcpServer
{
    Q_OBJECT
public:
    MyServer(QObject *parent=0);

    void removeUser(ClientUser *user);
    void startServer();
    void stopServer();
protected:
    void incomingConnection(int socketfd);
private:
    QList<ClientUser*> *users;
    QMap<QString, QString> *dictionary;
    int const static nPort=6666;
    bool loadFile();



private slots:
    void slotNewConnection();
};

#endif // MYSERVER_H
