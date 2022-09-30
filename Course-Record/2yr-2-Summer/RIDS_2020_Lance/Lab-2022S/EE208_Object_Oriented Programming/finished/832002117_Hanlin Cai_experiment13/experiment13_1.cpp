#include <iostream>
#include <math.h>
using namespace std;
float PI = 3.14159; // 这里用float直接定义即可

/*
Construct a class named sphere that has a double-precision data member named radius.
*/

class sphere
{
private:
    double radius;
    double surface;
    double volumeData;

public:
    void construct()
    {
        radius = 1;
        surface = 1;
        volumeData = 1;
    };

    void setData(double x);
    void showData();
    void surfaceArea();
    void volume();
};

void sphere::showData()
{
    cout << "Radius: " << radius << endl;
}
void sphere::setData(double x)
{
    radius = x;
}

void sphere::surfaceArea()
{
    // surface = 4 * PI * pow(radius,2);
    surface = 4 * PI * radius * radius;
    cout << "Surface Area: " << surface << endl;
}

void sphere::volume()
{
    volumeData = (4 / 3) * PI * pow(radius, 3);
    cout << "Volume: " << volumeData << endl;
}

int main()
{
    sphere sphere1;
    double x;
    cout << "Please enter the radius: ";
    cin >> x;

    sphere1.setData(x);
    sphere1.showData();
    sphere1.surfaceArea();
    sphere1.volume();

    return 0;
}
// Experiment 13 - 1
// This code is created by Hanlin Cai
// MU  number : 20122161
// FZU number : 832002117