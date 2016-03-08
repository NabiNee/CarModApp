class Calculator{
private:
float total; //current total of the project
float budgetAmount; //max amount of project cost
public:
Calculator(); //initilaizes everything to 0
Calculator(float budget); //initializes calculator with budgetAmount = budget
float updateTotal(float); 
};
