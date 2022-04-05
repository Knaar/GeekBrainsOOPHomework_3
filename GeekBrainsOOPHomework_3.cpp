#include <iostream>
#include <cmath>
#include <string>
using namespace std;

    /* 1.Task */

//abstract class is a class that has no implementation
class Figure 
{
protected:
    float Area;
    float FirstValue;
    float SecondValue;
public:
    Figure(float _FirstV, float _SecondV) {
        
        this->FirstValue = _FirstV;
        this->SecondValue = _SecondV;
    }
    virtual float FArea() = 0;
    virtual void GetInfo() { printf("Fist Value: %.0f, Second Value: %.0f, Area: %.0f\n", FirstValue, SecondValue, FArea()); }
};

//Parallelogram
class Parallelogram :public Figure
{
public:
    Parallelogram(float _FirstV, float _SecondV):Figure(_FirstV,_SecondV){}
    float FArea() override
    {
        this->Area = FirstValue * SecondValue;
        return Area;
    }
};

//Rectagle lol
class Rectagle :public Parallelogram
{
public:
    Rectagle(float _FirstV, float _SecondV):Parallelogram(_FirstV, _SecondV){}
    
};

//Square
class Square :public Parallelogram
{
public:
    Square(float OnlyOneVal):Parallelogram(OnlyOneVal,OnlyOneVal){}
    float FArea() override
    {
        this->Area = FirstValue * FirstValue;
        return Area;
    }
};

//Rhombus
class Rhombus :public Parallelogram
{
public:
    Rhombus(float _FirstV, float _SecondV) :Parallelogram(_FirstV, _SecondV) {}
};

//Circle
class Circle :public Figure
{
public:
    Circle(float _FirstV,float _SecondV=3.14):Figure(_FirstV,3.14){}
    float FArea() override
    {
        this->Area = FirstValue * pow(SecondValue,2);
        return Area;
    }
    virtual void GetInfo() override { printf("Fist Value: %.0f, Second Value: %.2f, Area: %.2f\n", FirstValue, SecondValue, FArea()); }
};


    /*2.Task*/

 class Car
{
public:
    string Company;
    string Model;

    Car(string _Company, string _Model) {
        this->Company = _Company;
        this->Model = _Model;
        cout << "Car"<<endl;
    }
    void CarInfo() { printf("Company: %s, Model : %s\n", Company.c_str(), Model.c_str()); }
    
};

class PassengerCar : public Car
{
public:
    PassengerCar(string _Company, string _Model):Car(_Company,_Model){
        cout << "PassengerCar"<<endl;
    }
};

class Bus : public Car
{
public:
    Bus(string _Company, string _Model) :Car(_Company, _Model) {
        cout << "Bus" << endl;
    }
};
class Minivan :Bus, PassengerCar
{
public:
    Minivan(string _Company, string _Model) :PassengerCar(_Company, _Model),Bus(_Company, _Model) {
        cout << "Minivan" << endl;
    }
};


/*3 Task*/
class Fraction
{
public:
    int numerator;
    int denominator;

    Fraction(int _numerator, int _denominator) {
        this->numerator = _numerator;
        this->denominator = _denominator;
    }

    friend Fraction operator+ (const Fraction n, const Fraction d) {

    }


};





int main()
{
    
    
    Circle C1(3);
    Rectagle R1(4, 4);
    Square S1(5);
    Rhombus Rh1(8, 8);
    
    
   
    C1.GetInfo();
    R1.GetInfo();
    S1.GetInfo();
    Rh1.GetInfo();

    Car Car1("Ford", "Mustang");
    Car1.CarInfo();
    cout << "================"<<endl;
    PassengerCar PCar1("Kia", "Rio");
    PCar1.CarInfo();
    cout << "================" << endl;
    Bus B1("Icarus", "Long");
    B1.CarInfo();
    cout << "================" << endl;
    Minivan M1("Mercedes","A180");
    //M1.CarInfo();


    unsigned int  numerator{3}, denominator{7};
    if (denominator!=0)
    {
        Fraction obj1(numerator, denominator);
    }
}

