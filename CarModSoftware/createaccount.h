/* This class allows the user to create a new user by collecting the inputted information and entering it into the database. It checks first to
 * see that the desired username isn't already used.*/
#ifndef CREATEACCOUNT_H
#define CREATEACCOUNT_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class CreateAccount;
}

class CreateAccount : public QDialog
{
    Q_OBJECT

public:
    explicit CreateAccount(QWidget *parent = 0);
    ~CreateAccount();

private slots:
    void on_okButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::CreateAccount *ui;
};

#endif // CREATEACCOUNT_H
