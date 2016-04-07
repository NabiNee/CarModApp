class Projects{
private:
Listener l;
Calculator calculator;
Car car;

public:
Projects();
User& saveProject(); //Saves project by returning updated user with project to the DB handler
}
