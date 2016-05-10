#ifndef LISTENER_H
#define LISTENER_H

#include <qevent.h>
#include <QActionEvent>
//#include <QCustomEvent>
#include <QWidget>
#include "make.h"
#include "parts.h"
#include <QMainWindow>
#include <iomanip>
#include "calculator.h"

class Listener
{
private:
    explicit Listener(QWidget *parent = 0);
    ~Listener();

    Ui::Projects *ui;

    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
protected:

public:
    void notifyOfUpdate();
};


#endif // LISTENER_H
