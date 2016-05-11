#include "parts.h"

Parts::Parts()
{
    price = 0.0;
}

float Parts::getPrice()
{
    return price;
}

/* Searches text file for partNeeded. If found, it sets data member price to what it should be.*/
void Parts::calculate(QString partNeeded)
{
    if(partNeeded == "None") //If user didn't selecet a part or reverts back to none
        price = 0.0;
    QString check;
    QFile fin (":/PartInfo/Parts.txt");
    fin.open(QIODevice::ReadOnly);
    QTextStream file(&fin);
    do
    {
        check = file.readLine();
        if(check == partNeeded) //If the part is found in the file
        {
            price = file.readLine().toFloat();
            break;
        }
    }while(!check.isNull());
    fin.close();
}
