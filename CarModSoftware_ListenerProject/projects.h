/* The "main page" of the application. Grabs all the information selected by the user, passing it to make and calculator to get the
 * overral price. It also checks the information to display the correct photo.*/
#ifndef PROJECTS_H
#define PROJECTS_H

#include <QMainWindow>
#include <iomanip>
#include "calculator.h"
#include "make.h"
#include "listener.h"
//#include <QCustomEvent>
using namespace std;

namespace Ui {
class Projects;
}

class Projects : public QMainWindow
{
    Q_OBJECT

public:
    explicit Projects(QWidget *parent = 0);
    ~Projects();
    void enableSelections();
    void disableSelections();

    Make getMake();
    * getUIPointer(){ return *ui};

private slots:
    void on_modelSelection_activated(const QString &arg1);

    void on_yearSelection_activated(const QString &arg1);

    void on_lightSelection_activated(const QString &arg1);

    void on_wheelSelection_activated(const QString &arg1);

    void on_hoodSelection_activated(const QString &arg1);

    void on_engineSelection_activated(const QString &arg1);

    void on_actionInclude_Tax_triggered(); //menubar option to incclude tax in total price calculations

    void eventUpdate(QEvent event);

private:
    Ui::Projects *ui;
    Calculator calculator;
    Make carChosen;
    bool includeTax;
};

#endif // PROJECTS_H
