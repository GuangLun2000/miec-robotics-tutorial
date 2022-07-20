#include<iostream>

using namespace std;

class Rectangle {
public:
    //perimeter()计算长方形的周长
    double perimeter() { return 2 * (m_length + m_width); }

    //getarea()计算长方形面积
    double getarea() { return m_length * m_width; }

    //setwidth()和GetWidth()用来设置和得到m_width的值
    void setwidth(double w) { m_width = w; }

    double getwidth() { return m_width; }

    //setlength()和GetLength()用来设置和得到m_length的值
    void setlength(double l) { m_length = l; }

    double getlength() { return m_length; }

    //set_()函数应验证m_length和m_width均为0.0到20.0之间的浮点数。
    bool set_() {
        bool n = 1;
        if (0 > m_length || 20 < m_length) {
            cout << "length is not in 0.0 - 20.0" << endl;
            n = 0;
        }
        if (0 > m_width || 20 < m_width) {
            cout << "width is not in 0.0 - 20.0" << endl;
            n = 0;
        }
        if (n)
            cout << "length and width are both in 0.0 - 20.0" << endl;
        return n;
    }

private:
    //两个成员变量m_length和m_width，其默认值为1
    double m_length = 1;
    double m_width = 1;
};

int main() {
    Rectangle rec;
    cout << "Length : " << rec.getlength() << "    " << "Width : " << rec.getwidth() << endl;
    rec.set_();
    cout << endl << endl;

    rec.setlength(5.2);
    rec.setwidth(4);
    cout << "Length : " << rec.getlength() << "    " << "Width : " << rec.getwidth() << endl;
    rec.set_();
    cout << endl << endl;

    rec.setwidth(25);
    cout << "Length : " << rec.getlength() << "    " << "Width : " << rec.getwidth() << endl;
    rec.set_();
    cout << endl << endl;

}


