#include <iostream>
#include <math.h>
#define pi 3.1415926
using namespace std;

/*
Define an abstract class Shape, including a pure virtual function perimeter, whose function is to calculate the perimeter of the graph.
Reasonably use polymorphism to realize the perimeter function to calculate the perimeter of triangles, rectangles, and circles.
*/

class Shape
{
public:
    virtual double area() = 0; // 声明area函数为纯虚函数 Declare the area function to be pure virtual.
};

class Circle : public Shape
{ //派生类圆
public:
    Circle(double r) : r(r) {}
    virtual double area()
    {
        return pi * r * r;
    }

private:
    double r;
};

class Rectangle : public Shape
{ //派生类矩形
public:
    Rectangle(double x, double y) : x(x), y(y) {}
    virtual double area() //派生类的同名函数自动成为虚函数,virtual可加可不加
    {
        return x * y;
    }

private:
    double x, y;
};

class Triangle : public Shape
{ //派生类三角形
public:
    Triangle(double x, double y, double z) : x(x), y(y), z(z) {}
    virtual double area() //已知三角形三边,利用 海伦公式 计算面积
    {
        double p = (x + y + z) / 2;
        return sqrt(p * (p - x) * (p - y) * (p - z));
    }

private:
    double x, y, z;
};

int main()
{
    Circle Cir(1);
    Rectangle Rec(2, 4);
    Triangle Tri(3, 4, 5);

    Shape *index = &Cir;                              //定义指向抽象基类对象Shape的指针变量index,指向Circle类对象Cri
    cout << "Circle area: " << index->area() << endl; //调用Circle类对象Cri的area函数并输出
    index = &Rec;                                     //让index指向Rectangle类对象Rec
    cout << "Rectangle area: " << index->area() << endl;
    index = &Tri;
    cout << "Triangle area: " << index->area() << endl;
    // cout << "area sum= " << Cir.area() + Rec.area() + Tri.area() << endl; //静态关联算总面积
    return 0;
}

// Experiment 14 - 2
// This code is created by Hanlin Cai
// MU  number : 20122161
// FZU number : 832002117