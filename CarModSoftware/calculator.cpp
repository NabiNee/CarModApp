#include "calculator.h"

const float TAX = 0.08;
Calculator* Calculator::instance = 0; //sets initial instance to 0, meaning there is no calculator created

//Initiates all variables to 0
Calculator::Calculator()
{
    total = 0;
    budgetAmount = 0;
    grandTotal = 0;
    taxTotal = 0;

}

//If there is no instance of calculator already, creates one and returns it. Otherwise, return the one already created.
Calculator* Calculator::Instance()
{
    if(instance == 0)
        instance = new Calculator();
    return instance;
}

/*Updates the amount total by calling the create list function from Make in order to get a vector.
  Then it'll go through the vector to update total.*/
void Calculator::updateTotal(Make model)
{
    total = 0; //total reset to 0 to account for any change in parts
    vector<Parts> list = model.createList(); //Grabs vector from model
    for(int i = 0; i < list.size(); i++)
        total = total + list[i].getPrice();
}

void Calculator::updateTaxTotal()
{
    taxTotal = total * TAX;
}

void Calculator::calculateGrandTotal()
{
    grandTotal = (total * TAX) + total;
}

 // Updates budget to show how much more can be spent
void Calculator::updateBudget()
{
    budgetAmount = budgetAmount - total;
}

float Calculator::getTotal()
{
      return total;
}

float Calculator::getTaxTotal()
{
      return taxTotal;
}

float Calculator::getGrandTotal()
{
      return QString::number(grandTotal,'f',2).toFloat();//returns tax total with a set precision of two
}
