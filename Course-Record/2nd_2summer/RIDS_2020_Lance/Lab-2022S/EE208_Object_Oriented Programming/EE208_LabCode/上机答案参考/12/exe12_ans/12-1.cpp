#include<iostream>
#include<math.h>

using namespace std;

class Tri {
    double a, b, c;  //定义三角形的三边
public:
    Tri(double x, double y, double z) //构造函数，初始化三边
    {
        a = x;
        b = y;
        c = z;
    }

    double getperimeter()  //返回三角形的周长
    { return (a + b + c); }

    double getarea()  //返回三角形的面积
    {
        double s = getperimeter() / 2;
        double area = sqrt(s * (s - a) * (s - b) * (s - c));
        return area;
    }

    void output() //输出三角形的参数
    {
        cout << "三角形的边长:" << a << ' ' << b << ' ' << c << endl;
        cout << "三角形的周长:" << getperimeter() << endl;
        cout << "三角形的面积:" << getarea() << endl << endl;
    }

};//三角形类的定义结束，定义了三角形的各种属性和可实施的操作

int main() {
    double x, y, z;
    cin >> x >> y >> z;
    Tri tri(x, y, z);

    if (x + y > z && y + z > x && x + z > y)
        tri.output();  //输出这两个三角形的参数
    else
        cout << "不构成三角形!" << endl;

}

