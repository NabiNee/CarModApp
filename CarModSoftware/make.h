/* The make class will contain all the parts used in the mod. It has a function to create and return a vector of all
   the parts used.*/
#ifndef MAKE_H
#define MAKE_H

#include "parts.h"
#include <vector>
#include <QString>
using namespace std;

class Make
{
private:
    Parts wheel;
    Parts engine;
    Parts hood;
    Parts spoilers;
    Parts lights;
public:
    Make();
    ~Make();
    const vector<Parts> createList(); //Creates a vector of all the parts used

    //Functions for adding parts
    void addWheel(QString);
    void addEngine(QString);
    void addHood(QString);
    void addExhaust(QString);
    void addLights(QString);
};

#endif // MAKE_H
