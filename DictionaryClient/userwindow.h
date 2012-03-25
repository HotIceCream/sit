#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include "../DictionaryServer/connection.h"
#include "QTextCursor"
namespace Ui {
class UserWindow;
}

class UserWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserWindow(QTcpSocket* ,QWidget *parent = 0);
    ~UserWindow();

private:
    Ui::UserWindow *ui;
    QTcpSocket *socket;
    QTextCursor cursor;
    QTextCharFormat textFormat;
private slots:
    void readyRead();
    void socketDestroyed();
    void on_buttonSearch_clicked();
};
#endif // USERWINDOW_H
