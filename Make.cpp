#include "Make.h"

//Initializes every Part pointer to null
Make::Make()
{
    wheel = nullptr;
    engine = nullptr;
    hood = nullptr;
    exhaust = nullptr;
    lights = nullptr;
}

//Deletes every object and sets pointer to null if its not already null
Make::~Make()
{
    if(wheel != nullptr)
    {
        delete wheel;
        wheel = nullptr;
    }
    if(engine != nullptr)
    {
        delete engine;
        engine = nullptr;
    }
    if(hood != nullptr)
    {
        delete hood;
        hood = nullptr;
    }
    if(exhaust != nullptr)
    {
        delete exhaust;
        exhaust = nullptr;
    }
    if(lights != nullptr)
    {
        delete lights;
        lights = nullptr;
    }
}

//Add methods
void Make::addWheel()
{
        wheel = new Parts;
}

void Make::addEngine()
{
        engine = new Parts;
}

void Make::addHood()
{
        hood = new Parts;
}

void Make::addExhaust()
{
        exhaust = new Parts;
}

void Make::addLights()
{
        lights = new Parts;
}

/* Adds parts to the partsList vector only if they are pointing to an object. Then it returns the list*/
const vector<Parts*> Make::createList()
{
    vector<Parts*> partsList;
    if(wheel != nullptr)
        partsList.push_back(wheel);
    if(engine != nullptr)
        partsList.push_back(engine);
    if(hood != nullptr)
        partsList.push_back(hood);
    if(exhaust != nullptr)
        partsList.push_back(exhaust);
    if(lights != nullptr)
        partsList.push_back(lights);
    return partsList;
}
