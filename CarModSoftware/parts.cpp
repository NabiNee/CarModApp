#include "parts.h"

Parts::Parts()
{
    price = 0.0;
}

float Parts::getPrice()
{
    return price;
}

void Parts::calculate(QString partNeeded)
{
    if(partNeeded == "None")
        price = 0;
    QString check;
    QFile fin (":/PartInfo/Parts.txt");
    fin.open(QIODevice::ReadOnly);
    QTextStream file(&fin);
    do
    {
        check = file.readLine();
        if(check == partNeeded)
        {
            price = file.readLine().toFloat();
            break;
        }
    }while(!check.isNull());
    fin.close();
}
