#include "createaccount.h"
#include "ui_createaccount.h"
#include "system.h"

CreateAccount::CreateAccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateAccount)
{
    ui->setupUi(this);
    ui->usernameError->setVisible(false);
}

CreateAccount::~CreateAccount()
{
    delete ui;
}

/* Checks the information inputted and inputs it into the database if they are valid. If not, it displays an error.*/
void CreateAccount::on_okButton_clicked()
{
    System conn;
    QString FirstName, LastName, UserName, Password;

    //Grabs information inputted
    FirstName=ui->enterFN->text();
    LastName=ui->enteredLN->text();
    UserName=ui->enteredUsername->text();
    Password=ui->enteredPW->text();

    if(!conn.connOpen()) //If database can't be opened, it returns.
        return;
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("insert into Users (FirstName, LastName, Password, UserName) values('"+FirstName+"','"+LastName+"','"+Password+"','"+UserName+"')");

    if(qry.exec())
    {
        QMessageBox::critical(this,tr("Save"),tr("Saved"));
        conn.connClose();

    }
    else
    {
         QMessageBox::critical(this,tr("Error::"),qry.lastError().text());
    }
}

void CreateAccount::on_cancelButton_clicked()
{
    this->close();
}
