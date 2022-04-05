#include <iostream>

//interface contains only firtual functions
class IFigure 
{
public:
    virtual void FigureArea() = 0;
};
//abstract clas is a class that has no implementation
class Figure
{
public:
    int Area;
};





int main()
{
    std::cout << "Hello World!\n";
}

