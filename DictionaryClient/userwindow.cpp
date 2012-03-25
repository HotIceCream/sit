#include "userwindow.h"
#include "ui_userwindow.h"
#include "QListWidgetItem"
#include "QMessageBox"
UserWindow::UserWindow(QTcpSocket *socket,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserWindow)
{
    ui->setupUi(this);
    this->socket=socket;
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(socket, SIGNAL(destroyed()), this, SLOT(socketDestroyed()));
    //Connection::sendMessage(socket, Connection::LIST_USERS_REQUEST, "");
    cursor=QTextCursor(ui->textHistory->textCursor());
}

UserWindow::~UserWindow()
{
    socket->close();
    delete ui;
}

void UserWindow::readyRead()
{
    qDebug()<<"ReadyRead";
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
    switch(Connection::readMessage(socket,result)){
    case Connection::LIST_USERS_RESULT:

        break;
    case Connection::SEARCH_ERROR:
        qDebug()<<"SEARCH_ERROR";

        textFormat.setForeground(QBrush(Qt::red));
        cursor.insertText(result, textFormat);
        cursor.insertBlock();
        break;
    case Connection::SEARCH_RESULT:
        qDebug()<<"SEARCH_RESULT";
        textFormat.setForeground(QBrush(Qt::blue));
        cursor.insertText(result, textFormat);
        cursor.insertBlock();
        break;
    }

}

void UserWindow::socketDestroyed()
{
    //QMessageBox::information(this,"Connection lost", "Connection lost");
}

void UserWindow::on_buttonSearch_clicked()
{
    if (ui->editSearch->text()==""){
        QMessageBox::information(this,"Error", "Search query must be not empty");
        return;
    }
    textFormat.setForeground(QBrush(Qt::black));
    cursor.insertText("SEARCH: "+ ui->editSearch->text()+"\nRESULT: ",textFormat);
    Connection::sendMessage(socket, Connection::SEARCH_WORD, ui->editSearch->text());
}
