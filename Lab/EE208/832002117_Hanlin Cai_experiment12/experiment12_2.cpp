#include <iostream>
using namespace std;

/*
Design a cube class box, it can calculate and output the volume and surface area of the cube.
*/

class Box{
    protected:
    double m_a;
    double volume;
    double area;

    public:
    void set(double x);
    void getVolume();
    void getArea();
    void display();
};

void Box::set(double x) {
    m_a = x;

}

void Box::getVolume() {
    volume = m_a * m_a * m_a;
    // cout << "Volume: " << volume << endl;
}

void Box::getArea() {
    area = m_a * 6;
    // cout << "Area: " << area << endl;
}

void Box::display() {
    cout << "Volume: " << volume << endl;
    cout << "Area: " << area << endl;
}



int main() {
    Box Box1;
    double x;
    cout << "Please enter the edge: ";
    cin >> x;

    Box1.set(x);
    Box1.getVolume();Box1.getArea();
    Box1.display();

    return 0;
}
// Experiment 12 - 2
// This code is created by Hanlin Cai
// MU  number : 20122161
// FZU number : 832002117