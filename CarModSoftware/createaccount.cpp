#include "createaccount.h"
#include "ui_createaccount.h"

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

void CreateAccount::on_pushButton_clicked()
{
    /*if(anyEmpty())
    {
        //dialog box signifying error
    }*/
    /*if()//checks if Username exists
        ui->usernameError->setVisible(true);*/
}
