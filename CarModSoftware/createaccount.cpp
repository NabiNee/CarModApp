#include "createaccount.h"
#include "ui_createaccount.h"
#include <QMessageBox>
#include "system.h"

CreateAccount::CreateAccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateAccount)
{
    project = Projects::Instance();
    ui->setupUi(this);

   /* System conn;

     if(!conn.connOpen())
        ui->status2->setText("Failed to open the database");
    else
        ui->status2->setText("Connected....");*/

    ui->usernameError->setVisible(false);
}

CreateAccount::~CreateAccount()
{
    delete ui;
}

void CreateAccount::on_pushButton_clicked()
{
    System conn;
    QString FirstName, LastName, UserName, Password;
    FirstName=ui->enterFN->text();
    LastName=ui->enteredLN->text();
    UserName=ui->enteredUsername->text();
    Password=ui->enteredPW->text();

    if(!conn.connOpen()){

        qDebug()<<"Failed to open the database";
        return;
    }

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("insert into Users (FirstName, LastName, Password, UserName) values('"+FirstName+"','"+LastName+"','"+Password+"','"+UserName+"')");

    if(qry.exec())
    {
        QMessageBox::critical(this,tr("Save"),tr("Saved"));
        conn.connClose();
        project->show();
        this->close();

    }
    else
    {
         QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }



}
