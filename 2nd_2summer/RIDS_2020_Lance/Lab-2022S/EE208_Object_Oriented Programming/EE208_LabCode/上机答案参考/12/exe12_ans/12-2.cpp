#include<iostream>

using namespace std;

class Box {

private:
    double m_a;//立方体边长
public:
    //seta(double a)（设置立方体边长）
    void seta(double a) {
        m_a = a;
    }

    //getvolume()（计算体积）
    double getvolume() {
        return m_a * m_a * m_a;
    }

    //getarea()（计算表面积）
    double getarea() {
        return m_a * m_a * 6;
    }

    //函数Display()，用来输出计算的结果。
    void display() {
        cout << "Volume: " << getvolume() << endl;
        cout << "Area: " << getarea() << endl;
    }

};


int main() {
    Box box;
    //将box的边长设置成2.5
    box.seta(2.5);
    //展示体积和表面积的计算结果
    box.display();
}


