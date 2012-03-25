#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QDialog>
#include <QtNetwork>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();
    
private slots:
    void connected();
    void readyRead();
    void onConnectionError(QAbstractSocket::SocketError);
    void onStateChanged(QAbstractSocket::SocketState state);

    void on_buttonOk_clicked();

private:
    Ui::LoginDialog *ui;
    QTcpSocket *socket;
};

#endif // LOGINFORM_H
