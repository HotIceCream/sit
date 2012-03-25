#include "myserver.h"
#include "clientuser.h"

MyServer::MyServer(QObject *parent) :
    QTcpServer(parent)
{
    users=new QList<ClientUser*>();
}

void MyServer::removeUser(ClientUser *user)
{
    //users->indexOf(user);
    //delete user;
   // users->removeOne(user);
}

void printDictionary(QMap<QString, QString> *d){
    QMapIterator<QString, QString> i(*d);
    while(i.hasNext()){
        i.next();
        qDebug()<<"WORD "<<i.key()<<" DISCRIPTION "<<i.value();
    }
}

void MyServer::startServer(){
    qDebug("Start server");

    if (isListening()){
        qDebug()<<"close server";
        close();
    }
    loadFile();
    printDictionary(dictionary);

    if (!listen(QHostAddress::Any, nPort)){
        qDebug()<<"Unable to start Server:"<<errorString();
        close();
        return;
    }
    connect(this, SIGNAL(newConnection()),this,SLOT(slotNewConnection()));
    qDebug() << isListening() << "TCPSocket listen on port" << nPort;
}

void MyServer::stopServer(){
    qDebug()<<"Stop server";
}

void MyServer::slotNewConnection()
{
    qDebug()<<"New Connection";
}

void MyServer::incomingConnection(int socketfd){
    qDebug()<<"Incoming Connection";
    ClientUser *client = new ClientUser(this,socketfd,dictionary);
    users->push_back(client);
}

bool MyServer::loadFile(){
    QFile file(FILE_NAME);
    if (!file.open(QIODevice::ReadOnly)){
        return false;
    }
    dictionary = new QMap<QString, QString>();
    QTextStream out(&file);
    QString str;
    while ((str=out.readLine())!=NULL){
        (*dictionary)[str.mid(0, str.indexOf(" "))] = str.mid(str.indexOf(" ")+1);
        //qDebug()<<str.mid(0, str.indexOf(" "))<<str.mid(str.indexOf(" ")+1) ;
    }
    file.close();
    return true;
}


