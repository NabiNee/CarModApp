class Calculator{
private:
float total; //current total of the project
float budgetAmount; //max amount of project cost
public:
Calculator(){ //initilaizes everything to 0
  total = 0;
  budgetAmount = 0;
}
Calculator(float budget){ //initializes calculator with budgetAmount = budget
  total = 0;
  budgetAmount = budget;
}
float updateTotal(float){ //updates the amount total using listeners?
}
};
