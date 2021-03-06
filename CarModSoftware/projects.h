/* The "main page" of the application. Grabs all the information selected by the user, passing it to make and calculator to get the
 * overral price. It also checks the information to display the correct photo.*/
#ifndef PROJECTS_H
#define PROJECTS_H

#include <QMainWindow>
#include <iomanip>
#include "calculator.h"
#include "make.h"
#include "projectsnapshot.h"

using namespace std;

namespace Ui {
class Projects;
}

class Projects : public QMainWindow
{
    Q_OBJECT

public:
    static Projects* Instance();
    ~Projects();
    void enableSelections();
    void disableSelections();
    void setPhoto(int); //display the appropriate photos

private slots:
    void on_modelSelection_activated(const QString &arg1);

    void on_yearSelection_activated(const QString &arg1);

    void on_lightSelection_activated(const QString &arg1);

    void on_wheelSelection_activated(const QString &arg1);

    void on_hoodSelection_activated(const QString &arg1);

    void on_engineSelection_activated(const QString &arg1);

    void on_actionInclude_Tax_triggered(); //menubar option to include tax in total price calculations

    void on_actionSet_Budget_triggered();

    void on_finishButton_clicked();

private:
    explicit Projects(QWidget *parent = 0);
    static Projects* instance;
    Ui::Projects *ui;
    Calculator* calculator;
    ProjectSnapshot pSnapshot;
    Make carChosen;
    bool includeTax; //If set to true, it calculates price with taxes. Default set to false

    //Store individual photos of car and mods selected
    QPixmap car;
    QPixmap lights;
    QPixmap hood;
    QPixmap wheel;
};

#endif // PROJECTS_H
