/* Initializes base program elements and provides the user to options to log in or create an account.*/
#ifndef SYSTEM_H
#define SYSTEM_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include "userlist.h"
#include "projects.h"
#include "createaccount.h"

namespace Ui {
class System;
}

class System : public QMainWindow
{
    Q_OBJECT

public:
    explicit System(QWidget *parent = 0);
    ~System();
    QSqlDatabase mydb;
    void connClose();
    bool connOpen();
private slots:
    void on_buttonCreateAccount_clicked();

    void on_buttonLogIn_clicked();

    void on_buttonSkip_clicked();

private:
    Ui::System *ui;
    Projects* project;
    UserList list; //an object containg list of users; should be replaced with database
    CreateAccount newAccount;
};

#endif // SYSTEM_H
