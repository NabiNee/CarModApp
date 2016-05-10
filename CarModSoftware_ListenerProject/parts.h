/* The parts class contains all the information of a part. While mainly used for grabbing the price, the IDs are important
 * when determining what parts go with what models.*/
#ifndef PARTS_H
#define PARTS_H

#include <QFile>
#include <QTextStream>
#include <QString>
using namespace std;

class Parts
{
protected:
    int ID;
    float price;
public:
    Parts();
    float getPrice();
    void calculate(QString);
};

#endif // PARTS_H
