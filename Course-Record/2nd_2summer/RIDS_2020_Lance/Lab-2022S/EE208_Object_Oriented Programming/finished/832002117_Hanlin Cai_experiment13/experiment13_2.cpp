#include <iostream>
#include <math.h>
using namespace std;
float PI = 3.14159; // 这里用float直接定义即可

/*
Construct a class named Circle that has double-precision data members named radius.
*/

class Circle
{
protected:
    double radius;
    double perimeterData;
    double areaData;

public:
    void setData(double x);
    void perimeter();
    void area();
    void showData();
};

void Circle::setData(double x)
{
    radius = x;
}
void Circle::perimeter()
{
    perimeterData = 2 * PI * radius;
}
void Circle::area()
{
    areaData = PI * radius * radius;
}
void Circle::showData()
{
    cout << "Radius: " << radius << endl;
    cout << "Perimeter: " << perimeterData << endl;
    cout << "area: " << areaData << endl;
}

int main()
{
    Circle circle;
    double x;
    cout << "Please enter the radius: ";
    cin >> x;

    circle.setData(x);
    circle.perimeter();
    circle.area();
    circle.showData();

    return 0;
}
// Experiment 13 - 2
// This code is created by Hanlin Cai
// MU  number : 20122161
// FZU number : 832002117