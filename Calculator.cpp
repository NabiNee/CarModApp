#include "Calculator.h"

const float TAX = 0.08;

//Initiates all variables to 0
Calculator::Calculator()
{
    total = 0;
    budgetAmount = 0;
    grandTotal = 0;
    taxTotal = 0;

}

//Initializes budgetAmount to budget, everything else to 0
Calculator::Calculator(float budget) //initializes calculator with budgetAmount = budget
{
    total = 0;
    budgetAmount = budget;
    grandTotal = 0;
    taxTotal = 0;
}

/*Updates the amount total by calling the create list function from Make in order to get a vector.
  Then it'll go through the vector to update total.*/
void Calculator::updateTotal(Make model)
{
    vector<Parts*> list = model.createList(); //Grabs vector from model
    for(int i = 0; i < list.size(); i++)
        total = total + list[i]->getPrice();
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
      return grandTotal;
}
