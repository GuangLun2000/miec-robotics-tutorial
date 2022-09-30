#include<iostream>

# define PI 3.1415926
using namespace std;

class Circle {
private:
    double radius;
public:

    Circle(double r) {
        this->radius = r;
    }

    double perimeter() {
        return 2 * PI * this->radius;
    }

    double area() {
        return this->radius * this->radius * PI;
    }

    void setdata(double r) {
        this->radius = r;
    }

    void showdata() {
        cout << "radius:" << this->radius << "\nperimeter:" << this->perimeter() << "\narea:" << this->area();
    }


};

int main() {
    double r;
    cin >> r;
    Circle *circle = new Circle(r);
    circle->showdata();
}
