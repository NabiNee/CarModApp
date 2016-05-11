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

void ProjectSnapshot::passData(QString mModel, QString modL, QString modW, QString modH, QString modE, float price, QPixmap car, QPixmap lights, QPixmap wheel, QPixmap hood)
{
    ui->labelCar->setText(mModel);
    ui->labelML->setText(modL);
    ui->labelMW->setText(modW);
    ui->labelMH->setText(modH);
    ui->labelME->setText(modE);
    ui->labelPrice->setText("$" + QString::number(price));
    ui->baseLayer->setPixmap(car);
    ui->lightsLayer->setPixmap(lights);
    ui->wheelLayer->setPixmap(wheel);
    ui->hoodLayer->setPixmap(hood);
}
