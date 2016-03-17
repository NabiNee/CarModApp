const float TAX = 0.08;
public class Calculator : Projects
{
private:
float total; //current total of the project
float budgetAmount; //max amount of project cost
float grandTotal; //includes tax and shipping
float taxTotal; //the tax from the total
public:
Calculator(){ //initilaizes everything to 0
  total = 0;
  budgetAmount = 0;
}
Calculator(float budget){ //initializes calculator with budgetAmount = budget
  total = 0;
  budgetAmount = budget;
}
void updateTotal(){ //updates the amount total by grabbing vector (?) from project class
  for(int counter = 0; counter < Project:: carPart.size(); counter ++)
  {
    total += Project::carParts.price;
  }
}
void updateTaxTotal()
{
  taxTotal = total * TAX;
}
void calculateGrandTotal()
{
  grandTotal = (total * TAX) + total;
}
void updateBudget(){ // updating budget
  budgetAmount = budgetAmount - total;
}
  float budget(){ //returns the budget in red if it's passed the budget amount
      if (budgetAmount > 0){
        return budgetAmount;
      }
        else{
            return budgetAmount; //in some red color
        }
    }
  }
float getTotal{
  return total;
}
float getTaxTotal{
  return taxTotal;
}
float getGrandTotal{
  return grandTotal;
}
};
