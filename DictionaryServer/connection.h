#ifndef CONNECTION_H
#define CONNECTION_H
#include "QByteArray"
#include <QtNetwork>
namespace Connection{
    const static int SEND_LOGIN = 0x01;
    const static int AUTH_FAILD=0x02;
    const static int AUTH_SECCESSFULL=0x03;
    const static int LIST_USERS_REQUEST=0x04;
    const static int LIST_USERS_RESULT=0x05;
    const static int SEARCH_WORD=0x06;
    const static int SEARCH_RESULT=0x07;
    const static int SEARCH_ERROR=0x08;

    void sendMessage(QTcpSocket *socket, int command, QString str);

    int readMessage(QTcpSocket *socket, QString &str);
}



#endif // CONNECTION_H
