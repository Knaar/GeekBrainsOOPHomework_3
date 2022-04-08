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

class PassengerCar :virtual public Car
{
public:
    PassengerCar(string _Company, string _Model):Car(_Company,_Model){
        cout << "PassengerCar"<<endl;
    }
};

class Bus :virtual public Car
{
public:
    Bus(string _Company, string _Model) :Car(_Company, _Model) {
        cout << "Bus" << endl;
    }
};
class Minivan :Bus, PassengerCar
{
public:
    Minivan(string _Company, string _Model) :PassengerCar(_Company, _Model),Bus(_Company, _Model), Car(_Company, _Model) {
        cout << "Minivan" << endl;
    }
};
    
    /*3 Task*/
class Fraction
{
public:
    int SomeKindOfCounter;

    Fraction(int _numerator) : SomeKindOfCounter(_numerator) {}

    int GetCounter() const { return SomeKindOfCounter; }

   
    //Method of the class
    Fraction operator+(const Fraction &obj2)
    {
        return Fraction(this->SomeKindOfCounter + obj2.GetCounter());
    }
    /*Пробовал объявить метод в классе Car, и вызвать его для объекта Minivan. У меня ничего не вышло.Как в таких ситуациях быть?*/

    //friend
    friend Fraction operator - (const Fraction& d1, const Fraction& d2);

    friend Fraction& operator++(Fraction& d);
    friend Fraction& operator--(Fraction& d);
    friend Fraction& operator+=(Fraction& left, const Fraction& right);
    friend Fraction& operator-=(Fraction& left, const Fraction& right);
    friend bool operator==(const Fraction& left, const Fraction& right);
 

    

};
    //Classic Function
Fraction operator*(const Fraction& d1, const Fraction& d2)
{
    return Fraction(d1.GetCounter() * d2.GetCounter());
}
//  /
Fraction operator/(const Fraction& d1, const Fraction& d2)
{
    return Fraction(d1.GetCounter() / d2.GetCounter());
}
//friend function
//  -
 Fraction operator - (const Fraction& d1, const Fraction& d2)
{
     return Fraction(d1.SomeKindOfCounter - d2.SomeKindOfCounter);
}
 // ++
 Fraction& operator++(Fraction& d1)
 {
     d1.SomeKindOfCounter++;
     return d1;
 }
 // --
 Fraction& operator--(Fraction& d)
 {
     d.SomeKindOfCounter--;
     return d;
 }
 // +=
 Fraction& operator+=(Fraction& left, const Fraction& right)
 {
     left.SomeKindOfCounter += right.SomeKindOfCounter;
     return left;
 }
 // -=
 Fraction& operator-=(Fraction& left, const Fraction& right)
 {
      left.SomeKindOfCounter -= right.SomeKindOfCounter;
      return left;
 }
 // ==
 bool operator==(const Fraction& left, const Fraction& right)
 {
     return left.SomeKindOfCounter == right.SomeKindOfCounter;
 }
    
    /*4 Task*/
 enum ERank {
     Ace = 1,
     Two = 2,
     Tree = 3,
     Four = 4,
     Six = 6,
     Seven = 7,
     Eigh = 8,
     Nine = 9,
     Ten = 10,
     Jack = 10,
     Queen = 10,
     King = 10
 };
 enum ESuit { Hearts, Diamonds, Clubs, Spades };
 class Card
 {
 
 public:
     ERank Rank;
     ESuit Suit;
     bool FrontSide;

     Card(ERank r, ESuit s) :Rank(r), Suit(s) { FrontSide = true; }
     
     void Flip();
     int GetValue() const;
 };
 int Card::GetValue()const
 {
     return Rank;
 }
 void Card::Flip() {
     FrontSide = !FrontSide;
 }

 


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
     cout << "================" << endl;
     PassengerCar PCar1("Kia", "Rio");
     PCar1.CarInfo();
     cout << "================" << endl;
     Bus B1("Icarus", "Long");
     B1.CarInfo();
     cout << "================" << endl;
     Minivan M1("Mercedes", "A180");
     //M1.CarInfo();
     cout << endl;


     int numerator = 5;
     int denominator = 4;

     Fraction Obj1(numerator);
     Fraction Obj2(denominator);

     Fraction Summ1_1 = Obj1 + Obj2;
     cout << " +  :" << Summ1_1.GetCounter() << endl;

     Fraction Summ1_2 = Obj1 * Obj2;
     cout << " *  :" << Summ1_2.GetCounter() << endl;

     Fraction Summ1_3 = operator/(Obj1, Obj2);
     cout << " /  :" << Summ1_3.GetCounter() << endl;

     Fraction Summ1_4 = operator-(Obj1, Obj2);
     cout << " -  :" << Summ1_4.GetCounter() << endl;

     Fraction Summ2_1 = operator++(Obj1);
     cout << " ++ :" << Summ2_1.GetCounter() << endl;
     
     Fraction Summ2_2 = operator--(Obj2);
     cout << " -- :" << Summ2_2.GetCounter() << endl;

     Fraction Summ3_1 = operator+=(Obj1, Obj2);
     cout << " += :" << Summ3_1.GetCounter() << endl;

     Fraction Summ3_2 = operator-=(Obj1, Obj2);
     cout << " -= :" << Summ3_2.GetCounter() << endl;

     cout << boolalpha<<(Obj1==Obj2)<<endl<<endl;

     
  
     Card f(Ace,Clubs);
     cout << f.GetValue();
    
     
 }


