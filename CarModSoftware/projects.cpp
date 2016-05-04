#include "projects.h"
#include "ui_projects.h"

Projects::Projects(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Projects)
{
    includeTax = false;
    ui->setupUi(this);
}

Projects::~Projects()
{
    delete ui;
}

void Projects::on_modelSelection_activated(const QString &arg1)
{
    if(arg1 == "-Select Car Model-")
        disableSelections();
    else
    {
        ui->yearSelection->setEnabled(true);
        ui->label_2->setEnabled(true);
    }
}

void Projects::on_yearSelection_activated(const QString &arg1)
{
    if(arg1 == "-Select Year-")
    {
        disableSelections();
        ui->yearSelection->setEnabled(true);
    }
    else
        enableSelections();
}

/* If option to show taxes is selected, will initialze project's, includeTax variable to true to
 * insure that the calcualtor always displays total with tax.*/
void Projects::on_actionInclude_Tax_triggered()
{
    if(ui->actionInclude_Tax->isChecked()) //case where option is selected
    {
        includeTax = true;
        calculator.updateTaxTotal();
        calculator.calculateGrandTotal();
        ui->calcDisplay->setNum(calculator.getGrandTotal()); //refreshes calculator to display current total with tax
    }
    else
        includeTax = false;
        ui->calcDisplay->setNum(calculator.getTotal());
}

void Projects::on_lightSelection_activated(const QString &arg1)
{
    carChosen.addLights(arg1); //sends light option to make to change object to appropriate object
    calculator.updateTotal(carChosen);
    if(includeTax == true) //Will display total with taxes only if option is selected
    {
        calculator.updateTaxTotal();
        calculator.calculateGrandTotal();
        ui->calcDisplay->setNum(calculator.getGrandTotal());
        return;
    }
    ui->calcDisplay->setNum(calculator.getTotal());
}

void Projects::on_wheelSelection_activated(const QString &arg1)
{
    carChosen.addWheel(arg1); //sends wheel option to make to change object to appropriate object
    calculator.updateTotal(carChosen);
    if(includeTax == true) //Will display total with taxes only if option is selected
    {
        calculator.updateTaxTotal();
        calculator.calculateGrandTotal();
        ui->calcDisplay->setNum(calculator.getGrandTotal());
        return;
    }
    ui->calcDisplay->setNum(calculator.getTotal());
}

void Projects::on_hoodSelection_activated(const QString &arg1)
{
    carChosen.addHood(arg1); //sends wheel option to make to change object to appropriate object
    calculator.updateTotal(carChosen);
    if(includeTax == true) //Will display total with taxes only if option is selected
    {
        calculator.updateTaxTotal();
        calculator.calculateGrandTotal();
        ui->calcDisplay->setNum(calculator.getGrandTotal());
        return;
    }
    ui->calcDisplay->setNum(calculator.getTotal());
}

void Projects::on_engineSelection_activated(const QString &arg1)
{
    carChosen.addEngine(arg1); //sends wheel option to make to change object to appropriate object
    calculator.updateTotal(carChosen);
    if(includeTax == true) //Will display total with taxes only if option is selected
    {
        calculator.updateTaxTotal();
        calculator.calculateGrandTotal();
        ui->calcDisplay->setNum(calculator.getGrandTotal());
        return;
    }
    ui->calcDisplay->setNum(calculator.getTotal());
}

void Projects::enableSelections()
{
    ui->yearSelection->setEnabled(true);
    ui->label_2->setEnabled(true);
    ui->lightSelection->setEnabled(true);
    ui->label_3->setEnabled(true);
    ui->wheelSelection->setEnabled(true);
    ui->label_4->setEnabled(true);
    ui->hoodSelection->setEnabled(true);
    ui->label_5->setEnabled(true);
    ui->engineSelection->setEnabled(true);
    ui->label_6->setEnabled(true);
}

void Projects::disableSelections()
{
    ui->yearSelection->setEnabled(false);
    ui->label_2->setEnabled(false);
    ui->lightSelection->setEnabled(false);
    ui->label_3->setEnabled(false);
    ui->wheelSelection->setEnabled(false);
    ui->label_4->setEnabled(false);
    ui->hoodSelection->setEnabled(false);
    ui->label_5->setEnabled(false);
    ui->engineSelection->setEnabled(false);
    ui->label_6->setEnabled(false);
}
