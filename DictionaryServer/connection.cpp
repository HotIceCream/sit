#include "connection.h"

void Connection::sendMessage(QTcpSocket *socket, int command, QString str){
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out<<(quint16)0<<(quint8)command;
    if (str!=""){
        out<<str;
    }
    out.device()->seek(0);
    out<<(quint16)(block.size()-sizeof(quint16));
    socket->write(block);
}

int Connection::readMessage(QTcpSocket *socket, QString &str){
    QDataStream in(socket);
    if (socket->bytesAvailable()<(int)sizeof(quint16)){
        qDebug()<<"bytes available < quint16";
        return -1;
    }
    quint16 blockSize;
    in>>blockSize;
    qDebug()<<"Block size"<<blockSize;
    quint8 command;
    in>>command;
    qDebug()<<"Command"<< command;

    in>>str;
    qDebug()<<"String from socket = "<<str;

    return command;
}
