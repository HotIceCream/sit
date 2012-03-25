/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created: Sat 24. Mar 23:36:01 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *editLogin;
    QHBoxLayout *horizontalLayout;
    QPushButton *buttonOk;
    QPushButton *buttonCancel;
    QPushButton *buttonMore;
    QGroupBox *groupMore;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLineEdit *editServer;
    QLabel *label_3;
    QLineEdit *editPort;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QString::fromUtf8("LoginDialog"));
        LoginDialog->resize(277, 263);
        verticalLayout = new QVBoxLayout(LoginDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(LoginDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        editLogin = new QLineEdit(groupBox);
        editLogin->setObjectName(QString::fromUtf8("editLogin"));

        horizontalLayout_2->addWidget(editLogin);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        buttonOk = new QPushButton(groupBox);
        buttonOk->setObjectName(QString::fromUtf8("buttonOk"));

        horizontalLayout->addWidget(buttonOk);

        buttonCancel = new QPushButton(groupBox);
        buttonCancel->setObjectName(QString::fromUtf8("buttonCancel"));

        horizontalLayout->addWidget(buttonCancel);

        buttonMore = new QPushButton(groupBox);
        buttonMore->setObjectName(QString::fromUtf8("buttonMore"));
        buttonMore->setCheckable(true);

        horizontalLayout->addWidget(buttonMore);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        verticalLayout->addWidget(groupBox);

        groupMore = new QGroupBox(LoginDialog);
        groupMore->setObjectName(QString::fromUtf8("groupMore"));
        groupMore->setEnabled(true);
        gridLayout_2 = new QGridLayout(groupMore);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_2 = new QLabel(groupMore);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        editServer = new QLineEdit(groupMore);
        editServer->setObjectName(QString::fromUtf8("editServer"));

        gridLayout_2->addWidget(editServer, 0, 1, 1, 1);

        label_3 = new QLabel(groupMore);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 1, 0, 1, 1);

        editPort = new QLineEdit(groupMore);
        editPort->setObjectName(QString::fromUtf8("editPort"));

        gridLayout_2->addWidget(editPort, 1, 1, 1, 1);


        verticalLayout->addWidget(groupMore);

        QWidget::setTabOrder(editLogin, buttonOk);
        QWidget::setTabOrder(buttonOk, buttonCancel);
        QWidget::setTabOrder(buttonCancel, buttonMore);
        QWidget::setTabOrder(buttonMore, editServer);
        QWidget::setTabOrder(editServer, editPort);

        retranslateUi(LoginDialog);
        QObject::connect(buttonMore, SIGNAL(toggled(bool)), groupMore, SLOT(setVisible(bool)));
        QObject::connect(buttonCancel, SIGNAL(clicked()), LoginDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "LoginForm", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("LoginDialog", "Connection", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("LoginDialog", "LOGIN", 0, QApplication::UnicodeUTF8));
        buttonOk->setText(QApplication::translate("LoginDialog", "OK", 0, QApplication::UnicodeUTF8));
        buttonCancel->setText(QApplication::translate("LoginDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        buttonMore->setText(QApplication::translate("LoginDialog", "More", 0, QApplication::UnicodeUTF8));
        groupMore->setTitle(QApplication::translate("LoginDialog", "More", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("LoginDialog", "Server", 0, QApplication::UnicodeUTF8));
        editServer->setText(QApplication::translate("LoginDialog", "127.0.0.1", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("LoginDialog", "Port", 0, QApplication::UnicodeUTF8));
        editPort->setText(QApplication::translate("LoginDialog", "6666", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
