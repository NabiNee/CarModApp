/* The make class will contain all the parts used in the mod. It has a function to create and return a vector of all
  the parts used. */
#ifndef MAKE_H
#define MAKE_H

#include "Parts.h"
#include <vector>
using namespace std;

class Make
{
private:
    Parts* wheel;
    Parts* engine;
    Parts* hood;
    Parts* exhaust;
    Parts* lights;
public:
    Make(); //Initiliazes every pointer to null
    ~Make(); //Deletes objects and reinitializes every pointer to null
    
    //Functions for adding parts
    void addWheel();
    void addEngine();
    void addHood();
    void addExhaust();
    void addLights();
    
    const vector<Parts*> createList(); //Creates a vector of all the parts used
};

#endif // MAKE_H
