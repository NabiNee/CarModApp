#include "make.h"

Make::Make()
{
}

Make::~Make()
{
}

//Add methods. They send part name to Parts class to set each Part object's price.
void Make::addWheel(QString partChosen)
{
        wheel.calculate(partChosen);
}

void Make::addEngine(QString partChosen)
{
        engine.calculate(partChosen);
}

void Make::addHood(QString partChosen)
{
        hood.calculate(partChosen);
}

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
