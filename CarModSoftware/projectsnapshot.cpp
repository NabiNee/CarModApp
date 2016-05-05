#include "projectsnapshot.h"
#include "ui_projectsnapshot.h"

ProjectSnapshot::ProjectSnapshot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProjectSnapshot)
{
    ui->setupUi(this);
}

ProjectSnapshot::~ProjectSnapshot()
{
    delete ui;
}

void ProjectSnapshot::passData(QString car, QString modL, QString modW, QString modH, QString modE, float price)
{
    ui->labelCar->setText(car);
    ui->labelML->setText(modL);
    ui->labelMW->setText(modW);
    ui->labelMH->setText(modH);
    ui->labelME->setText(modE);
    ui->labelPrice->setText("$" + QString::number(price));
}
