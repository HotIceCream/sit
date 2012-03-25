#include "clientuser.h"
#include "connection.h"
#include "myserver.h"

ClientUser::ClientUser(QObject *parent) :QObject(parent)
{
}

ClientUser::ClientUser(const ClientUser &user) :QObject()
{
    this->server = user.server;
    this->dictionary=user.dictionary;
    this->socket=user.socket;
}

ClientUser::ClientUser(MyServer *server, int socketfd, QMap<QString, QString> *d):QObject()
{
    this->server = server;
    this->dictionary = d;
    socket=new QTcpSocket();
    socket->setSocketDescriptor(socketfd);
    //this->setSocketDescriptor(socketfd);
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
   // connect(this, SIGNAL(destroyed()), this, SLOT(userDisconnected()));
    connect(socket, SIGNAL(disconnected()), this,SLOT(userDisconnected()));

}

ClientUser &ClientUser::operator =(const ClientUser &user)
{
    this->server = user.server;
    this->dictionary=user.dictionary;
    this->socket=user.socket;
}

void ClientUser::readyRead()
{
    qDebug()<<"ReadyRead";
    QString result;
    switch(Connection::readMessage(socket,result)){
    case Connection::SEND_LOGIN:
        qDebug()<<"User login = "<<result;
        this->userLogin = result;
        Connection::sendMessage(socket,Connection::AUTH_SECCESSFULL,NULL);
        break;
    case Connection::SEARCH_WORD:
        qDebug()<<"User search word = "<<result;
        if (dictionary->contains(result)){
            Connection::sendMessage(socket, Connection::SEARCH_RESULT, dictionary->value(result,""));
        } else {
            Connection::sendMessage(socket,Connection::SEARCH_ERROR, "Word not found");
        }
    }

}

void ClientUser::userDisconnected()
{
    qDebug()<<"Client "+userLogin+" was disconnected";
    server->removeUser(this);

}


