/* The calculator class is a singleton class that contains the current total cost of the project. It has functions to
 * calculate to the cost and tax, to update based on the budget, and various get methods to grab the private data members.*/
#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "make.h"
#include "parts.h"

class Calculator
{
private:
    Calculator(); //initializes everything to 0
    static Calculator* instance;
    float total; //current total of the project
    float budgetAmount; //max amount of project cost
    float grandTotal; //includes tax
    float taxTotal; //the tax from the total
public:
    static Calculator* Instance(); //creates an instance of Calculator
    void updateTotal(Make); //updates total by using the Make data memeber in project
    void updateTaxTotal(); //calculates amount of tax
    void calculateGrandTotal(); //calculates total plus tax
    void updateBudget(); //Updates budget to show how much more can be spent

    //get methods
    float getTotal();
    float getTaxTotal();
    float getGrandTotal();
};

#endif
