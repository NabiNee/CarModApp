#include "projects.h"
#include "ui_projects.h"

Projects* Projects::instance = 0;

Projects* Projects::Instance()
{
    if(instance == 0)
        instance = new Projects();
    return instance;
}

Projects::Projects(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Projects)
{
    calculator = Calculator::Instance();
    includeTax = false;
    ui->setupUi(this);
}

Projects::~Projects()
{
    delete ui;
}

/* User selects model. If none is chosen, all other selections are disabled. Once one is selected, only year is enabled.*/
void Projects::on_modelSelection_activated(const QString &arg1)
{
    if(arg1 == "-Select Car Model-")
    {
        disableSelections();
        QPixmap pic(":/Photos/defaultcar.png");
        ui->baseLayer->setPixmap(pic); //Sets or resets photo to default photo
    }
    else
    {
        ui->yearSelection->setEnabled(true);
        ui->label_2->setEnabled(true);
    }
}

/* After year is selected, it enables all other options, and displays base photo.*/
void Projects::on_yearSelection_activated(const QString &arg1)
{
    if(arg1 == "-Select Year-")
    {
        disableSelections();
        ui->yearSelection->setEnabled(true);
    }
    else{
        car.load(":/CarPhotos/honda civic si 2006.png");
        enableSelections();
        ui->baseLayer->setPixmap(car);
    }
}

/* Reads user's selected lights mod. Send info to Make class, which will search for the light selection from the file
 * and set appropriate price. Projects then calls setPhoto.*/
void Projects::on_lightSelection_activated(const QString &arg1)
{
    carChosen.addLights(arg1); //sends light option to Make to change object's information to what it should now be
    calculator->updateTotal(carChosen); //Calculates new total
    if(includeTax == true) //Will calculate and display total with taxes only if option is selected
    {
        calculator->updateTaxTotal();
        calculator->calculateGrandTotal();
        ui->calcDisplay->setNum(calculator->getGrandTotal());;
    }
    else //Otherwise display raw price
        ui->calcDisplay->setNum(calculator->getTotal());
    setPhoto(100 + ui->lightSelection->currentIndex()); //send light selection to user
}

/* Reads user's selected hood mod. Send info to Make class, which will search for the hood selection from the file
 * and set appropriate price. Projects then calls setPhoto.*/
void Projects::on_hoodSelection_activated(const QString &arg1)
{
    carChosen.addHood(arg1); //sends hood option to make to change object to appropriate object
    calculator->updateTotal(carChosen);
    if(includeTax == true) //Will display total with taxes only if option is selected
    {
        calculator->updateTaxTotal();
        calculator->calculateGrandTotal();
        ui->calcDisplay->setNum(calculator->getGrandTotal());
    }
    else
        ui->calcDisplay->setNum(calculator->getTotal());
    setPhoto(200 + ui->hoodSelection->currentIndex());
}

/* Reads user's selected wheels mod. Send info to Make class, which will search for the wheel selection from the file
 * and set appropriate price. Projects then calls setPhoto.*/
void Projects::on_wheelSelection_activated(const QString &arg1)
{
    carChosen.addWheel(arg1); //sends wheel option to make to change object to appropriate object
    calculator->updateTotal(carChosen);
    if(includeTax == true) //Will display total with taxes only if option is selected
    {
        calculator->updateTaxTotal();
        calculator->calculateGrandTotal();
        ui->calcDisplay->setNum(calculator->getGrandTotal());
    }
    else
        ui->calcDisplay->setNum(calculator->getTotal());
    setPhoto(300 + ui->wheelSelection->currentIndex());
}

/* Reads user's selected engine mod. Send info to Make class, which will search for the engine selection from the file
 * and set appropriate price.*/
void Projects::on_engineSelection_activated(const QString &arg1)
{
    carChosen.addEngine(arg1); //sends engine option to make to change object to appropriate object
    calculator->updateTotal(carChosen);
    if(includeTax == true) //Will display total with taxes only if option is selected
    {
        calculator->updateTaxTotal();
        calculator->calculateGrandTotal();
        ui->calcDisplay->setNum(calculator->getGrandTotal());
    }
    else
        ui->calcDisplay->setNum(calculator->getTotal());
}

/* Sets photo based on what selection is. Numbers ranged from 101- 199 are light mods. 201-299 are hood mods. 301-399 are wheel mods. Base
 * hundred classes clear appropriate pictures. Uses switch statement to handle changes.*/
void Projects::setPhoto(int selection)
{
    switch(selection)
    {
        // Light Cases
    case 100:
        lights.load(0); //sets lights pixmap to empty
        ui->lightsLayer->clear(); //clears lights image
        break;
    case 101:
    {
        lights.load(":/CarPhotos/light mod 1.png"); //sets lights to selected mod
        ui->lightsLayer->setPixmap(lights); //displays lights in the appropriate layer
        break;
    }
    case 102:
    {
        lights.load(":/CarPhotos/light mod 2.png");
        ui->lightsLayer->setPixmap(lights);
        break;
    }
        // Hood Cases
    case 200:
        hood.load(0);
        ui->hoodLayer->clear();
        break;
    case 201:
    {
        hood.load(":/CarPhotos/hood mod 1.png");
        ui->hoodLayer->setPixmap(hood);
        break;
    }
        //Wheel Cases
    case 300:
        wheel.load(0);
        ui->wheelLayer->clear();
        break;
    case 301:
    {
        wheel.load(":/CarPhotos/wheel mod 1.png");
        ui->wheelLayer->setPixmap(wheel);
        break;
    }
    case 302:
    {
        wheel.load(":/CarPhotos/wheel mod 2.png");
        ui->wheelLayer->setPixmap(wheel);
        break;
    }
    default:
        break;
    }
    return;
}

/* If option to show taxes is selected, will initialze project's includeTax variable to true to
 * insure that the calcualtor always displays total with tax.*/
void Projects::on_actionInclude_Tax_triggered()
{
    if(ui->actionInclude_Tax->isChecked()) //case where option is selected
    {
        includeTax = true;
        calculator->updateTaxTotal();
        calculator->calculateGrandTotal();
        ui->calcDisplay->setNum(calculator->getGrandTotal()); //refreshes calculator to display current total with tax
    }
    else
    {
        includeTax = false;
        ui->calcDisplay->setNum(calculator->getTotal());
    }
}

/* Sets the project to calculate budget.*/
void Projects::on_actionSet_Budget_triggered()
{
    //Do something
}

/* Passes relevant data to pSnapshot, then runs it.*/
void Projects::on_finishButton_clicked()
{
    QString mModel = ui->yearSelection->currentText() + " " + ui->modelSelection->currentText();
    pSnapshot.passData(mModel,ui->lightSelection->currentText(),ui->wheelSelection->currentText(),ui->hoodSelection->currentText(),
                       ui->engineSelection->currentText(),ui->calcDisplay->text().toFloat(), car, lights, wheel, hood);
    pSnapshot.exec();
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
    ui->finishButton->setEnabled(true);
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

