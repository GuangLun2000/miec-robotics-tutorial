#include<iostream>

using namespace std;

class sphere {
private:
    double radius;
public:
    sphere() {
        this->radius = 1;
    }

    sphere(double radius) {
        this->radius = radius;
    }

    void showdata() {
        cout << "this sphere's radius = " << radius << endl;
    }

    void setdata(double radius) {
        this->radius = radius;
    }

    void surfacearea() {
        double area = 4 * 3.14 * radius * radius;
        cout << "this sphere's surfacearea = " << area << endl;
    }

    void volume() {
        double vol = 4.0 / 3 * 3.14 * radius * radius * radius;
        cout << "this sphere's volume = " << vol << endl;
    }
};

int main() {
    cout << "Create a sphere object with a default radius of 1" << endl;
    sphere A;
    A.showdata();
    A.surfacearea();
    A.volume();
    cout << endl;
    cout << "Set the radius to 100" << endl;
    A.setdata(100);
    A.showdata();
    A.surfacearea();
    A.volume();
    cout << endl;
    cout << "Create a sphere object with a radius of 5.2" << endl;
    sphere B(5.2);
    B.showdata();
    B.surfacearea();
    B.volume();
    return 0;
}
