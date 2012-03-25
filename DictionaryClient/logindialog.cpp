#include "logindialog.h"
#include "ui_logindialog.h"
#include "../DictionaryServer/connection.h"
#include "userwindow.h"
#include <QMessageBox>
LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    ui->groupMore->hide();
    layout()->setSizeConstraint(QLayout::SetFixedSize);
    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(readyRead()),this, SLOT(readyRead()));
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(onConnectionError(QAbstractSocket::SocketError)));
    connect(socket, SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this , SLOT(onStateChanged(QAbstractSocket::SocketState)));
}

LoginDialog::~LoginDialog()
{
    delete ui;
}
void LoginDialog::on_buttonOk_clicked()
{
    if (ui->editLogin->text()==""){
        QMessageBox::information(this, tr("Login error"), tr("Login must be not empty"));
        return;
    }
    qDebug()<<"start connection";
   // ui->loginButton->setEnabled(false);
    if (socket->isOpen()){
        socket->close();
    }
    socket->connectToHost(ui->editServer->text(), ui->editPort->text().toInt());
}

void LoginDialog::connected()
{
    qDebug()<<"Connected";
//    QByteArray block;
//    QDataStream out(&block, QIODevice::WriteOnly);
//    out << (quint16)0 << (quint8)Connection::SEND_LOGIN << ui->editLogin->text();
//    out.device()->seek(0);
//    out<< (quint16)(block.size()-sizeof(quint16));
//    socket->write(block);
    if (ui->editLogin->text()==""){
        QMessageBox::information(this,"Error", "login must be not empty");
        return;
    }
    Connection::sendMessage(socket, Connection::SEND_LOGIN, (ui->editLogin->text()));

}

void LoginDialog::readyRead()
{
    qDebug()<<"readyRead";
//    QDataStream in(socket);
//    if (socket->bytesAvailable()<(int)sizeof(quint16)){
//        qDebug()<<"bytes available < quint16";
//        return;
//    }
//    quint16 blockSize;
//    in>>blockSize;
//    qDebug()<<"Block size"<<blockSize;
//    quint8 command;
//    in>>command;
//    qDebug()<<"Command"<< command;
    QString result;
    switch(Connection::readMessage(socket, result)){
    case Connection::AUTH_SECCESSFULL:
        UserWindow *userswindow = new UserWindow(socket);
        this->hide();
        disconnect(socket, SIGNAL(readyRead()),this, SLOT(readyRead()));
        disconnect(socket, SIGNAL(connected()), this, SLOT(connected()));
        disconnect(socket, SIGNAL(error(QAbstractSocket::SocketError)),
                this, SLOT(onConnectionError(QAbstractSocket::SocketError)));
        disconnect(socket, SIGNAL(stateChanged(QAbstractSocket::SocketState)),
                this , SLOT(onStateChanged(QAbstractSocket::SocketState)));
        userswindow->show();
        break;
    }

}

void LoginDialog::onConnectionError(QAbstractSocket::SocketError error)
{
    qDebug()<<"onConnectionError";
    ui->buttonOk->setEnabled(true);
    QMessageBox::information(this, tr("Error"), tr("Error while connection"));

}

void LoginDialog::onStateChanged(QAbstractSocket::SocketState state)
{
    qDebug()<<"OnstateChenged";
}

