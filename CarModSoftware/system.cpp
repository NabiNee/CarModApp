#include "system.h"
#include "ui_system.h"
#include <QString>

System::System(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::System)
{
    ui->setupUi(this);
    ui->loginError->setVisible(false);
}

System::~System()
{
    delete ui;
}

void System::on_buttonCreateAccount_clicked()
{
    newAccount.exec();
    this->close();
    project.show();
}

/*Grabs username and password inputted, then sends it to UserList to check if it exists. If they
 * dont, it reveals error message;otherwise it goes to the next form. */

void System::on_buttonLogIn_clicked()
{
    QString userName, password;
    bool unPwExist;
    userName = ui->enterUN->text(); //grabs user name inputted
    password = ui->enterPW->text(); //grabs password inputted
    unPwExist = list.checkCredentials(userName.toStdString(),password.toStdString()); //.toStdString converts qString to string
    if(unPwExist == false) //if username/password don't exist, show error message
            ui->loginError->setVisible(true);
    else
    {
        this->close();
        project.show();
    }
}

void System::on_buttonSkip_clicked()
{
    project.show();
    this->close();
}
