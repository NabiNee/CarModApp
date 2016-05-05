#include "system.h"
#include "ui_system.h"
#include <QString>

System::System(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::System)
{
    project = Projects::Instance();
    ui->setupUi(this);


   if(!connOpen())
       ui->status->setText("Failed to open the database");
   else
       ui->status->setText("Connected....");

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

}

/*Grabs username and password inputted, then sends it to UserList to check if it exists. If they
 * dont, it reveals error message;otherwise it goes to the next form. */
void System::on_buttonLogIn_clicked()
{
    QString username, password;
    username=ui->enterUN->text();
    password=ui->enterPW->text();
    ui->loginError->setVisible(true);

    if(!connOpen()){

        qDebug()<<"Failed to open the database";
        return;
    }
    connOpen();
    QSqlQuery qry;
    qry.prepare("select * from Users where username='"+username +"' and password='"+password +"'");

    if(qry.exec())
    {
        int count=0;
        while(qry.next())
        {
            count++;
        }
        if(count==1){
            ui->status->setText("Login Successful");
            connClose();
            project->show();
            this->close();
        }
        if(count>1)
            ui->status->setText("Username or Password already exsists");
        if(count<1)
            ui->status->setText("Invalid Username or Password");

    }
}

void System::on_buttonSkip_clicked()
{
    project->show();
    this->close();
}

void System::connClose()
{
    mydb.close();
    mydb.removeDatabase(QSqlDatabase::defaultConnection);
}
bool System::connOpen()
{
    mydb=QSqlDatabase::addDatabase("QSQLITE");
   mydb.setDatabaseName("C:/Users/Lovey/Documents/Database/UserAccount.sqlite");

   if(!mydb.open()){
       qDebug()<<("Failed to open the database");
       return false;
   }

   else{
       qDebug()<<("Connected....");
       return true;
   }
}
