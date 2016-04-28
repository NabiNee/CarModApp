#include "make.h"

Make::Make()
{

}

Make::~Make()
{

}

//Add methods
void Make::addWheel(QString partChosen)
{
        wheel.calculate(partChosen);
}

/*void Make::addEngine()
{
        engine = new Parts;
}

void Make::addHood()
{
        hood = new Parts;
}*/

void Make::addLights(QString partChosen)
{
        lights.calculate(partChosen);
}

/* Adds parts to the partsList vector only if they are pointing to an object. Then it returns the list*/
const vector<Parts> Make::createList()
{
    vector<Parts> partsList;
    partsList.push_back(wheel);
    partsList.push_back(engine);
    partsList.push_back(hood);
    partsList.push_back(lights);
    return partsList;
}