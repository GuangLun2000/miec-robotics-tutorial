#include<iostream>
#include<cmath>

using namespace std;

// 定义数学常数pi
#define pi 3.1415926

// 创建抽象基类Area
class Area {
public:
    virtual double getarea() = 0;
};

// 创建抽象基类Volume
class Volume {
public:
    virtual double getvolume() = 0;
};

// 创建基类Circle圆类
class Circle : public Area {
public:
    friend class Cylinder;

    friend class Cone;

    friend class Sphere;

    Circle() {}

    Circle(double r_) { r = r_; }

    virtual double getarea() { return pi * r * r; }

private:
    double r;
};

// 创建圆柱类
class Cylinder : public Circle, public Volume {
public:
    Cylinder() : Circle() {}

    Cylinder(double r_, double h_) : Circle(r_) { h = h_; }

    virtual double getarea() { return 2 * pi * r * r + 2 * pi * r * h; }

    virtual double getvolume() { return pi * r * r * h; }

private:
    double h;
};

// 创建圆锥类
class Cone : public Circle, public Volume {
public:
    Cone() : Circle() {}

    Cone(double r_, double h_) : Circle(r_) { h = h_; }

    virtual double getarea() { return pi * r * r + 2 * pi * r * sqrt(h * h + r * r) / 2; }

    virtual double getvolume() { return pi * r * r * h / 3; }

private:
    double h;
};

// 创建球类
class Sphere : public Circle, public Volume {
public:
    Sphere() : Circle() {}

    Sphere(double r_) : Circle(r_) {}

    virtual double getarea() { return 4 * pi * r * r; }

    virtual double getvolume() { return 4 * pi * r * r * r / 3; }
};

int main() {
    Circle circle(2);
    cout << "创建一个圆对象" << endl;
    cout << "半径 ：2.0" << endl;
    cout << "面积 ：" << circle.getarea() << endl << endl;

    Cylinder cylinder(2, 3);
    cout << "创建一个圆柱对象" << endl;
    cout << "半径 ：2.0" << endl;
    cout << "高度 ：3.0" << endl;
    cout << "面积 ：" << cylinder.getarea() << endl;
    cout << "体积 ：" << cylinder.getvolume() << endl << endl;

    Cone cone(2, 3);
    cout << "创建一个圆锥对象" << endl;
    cout << "半径 ：2.0" << endl;
    cout << "高度 ：3.0" << endl;
    cout << "面积 ：" << cone.getarea() << endl;
    cout << "体积 ：" << cone.getvolume() << endl << endl;

    Sphere sphere(2);
    cout << "创建一个球对象" << endl;
    cout << "半径 ：2.0" << endl;
    cout << "面积 ：" << sphere.getarea() << endl;
    cout << "体积 ：" << sphere.getvolume() << endl << endl;
    return 0;
}

