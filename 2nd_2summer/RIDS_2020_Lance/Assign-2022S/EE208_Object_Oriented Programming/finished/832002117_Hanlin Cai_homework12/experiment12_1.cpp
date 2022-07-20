#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int Euclid(int a, int b)
{
    // Euclid finds the greatest common divisor.
    int r;
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

class fraction
{
private:
    int num;
    int den;

public:
    fraction(int n = 0, int d = 1) : num(n), den(d) { simplify(); };
    fraction(double d);                                     // double类型转化fraction 类外详细定义
    fraction(const string str);                             // string类型转化fraction 类外详细定义
    fraction(const fraction &f) : num(f.num), den(f.den){}; //复制构造函数 Copy constructor

    void simplify();
    void display();

    friend fraction operator+(fraction a, fraction b);
    friend fraction operator-(fraction a, fraction b);
    friend fraction operator*(fraction a, fraction b);
    friend fraction operator/(fraction a, fraction b);

    friend istream &operator>>(istream &in, fraction &f);
    friend ostream &operator<<(ostream &out, fraction &f);
};

fraction::fraction(double d) : num(d), den(1)
{
    // num是整形，d为double故这里强制类型转化num取了d的整数部分 get the integer part
    d = d - num;
    while (int(d * 10) != 0)
    {
        num = num * 10 + int(d * 10);
        den = den * 10;
        d = d * 10 - int(d * 10);
    };
    simplify();
}

fraction::fraction(const string str) : num(0), den(1)
{
    char buf[200];
    int i = str.find('/');
    str.copy(buf, i, 0); // string.copy函数（指向存放位置的指针，复制函数的个数，从第几位开始复制）
    buf[i] = 0;
    num = atoi(buf);
    int j = str.length() - i - 1;
    str.copy(buf, j, i + 1);
    buf[j] = 0;
    den = atoi(buf);
    simplify();
}

void fraction::simplify()
{
    //欧几里得算法找到最大公约数 get greatest common divisor
    int n, d, r, s = 1; // s为符号位
    if (den < 0)
        s = -s, den = -den;
    if (num < 0)
        s = -s, num = -num;
    int t = Euclid(num, den);
    num = s * num / t;
    den = den / t;
}

void fraction::display()
{
    if (den != 0)
    {
        cout << num << "/" << den << endl;
    }
    else
        cout << "the den must not be 0" << endl;
}

fraction operator*(fraction a, fraction b)
{
    fraction c;
    c.den = a.den * b.den;
    c.num = a.num * b.num;
    c.simplify();
    return c;
}

fraction operator/(fraction a, fraction b)
{
    fraction c;
    c.den = a.den * b.num;
    c.num = a.num * b.den;
    c.simplify();
    return c;
}

fraction operator+(fraction a, fraction b)
{
    fraction c;
    int r = Euclid(a.den, b.den);
    c.num = a.num * (b.den / r) + b.num * (a.den / r);
    c.den = a.den * b.den / r;
    c.simplify();
    return c;
}

fraction operator-(fraction a, fraction b)
{
    fraction c;
    int r = Euclid(a.den, b.den);
    c.num = a.num * (b.den / r) - b.num * (a.den / r);
    c.den = a.den * b.den / r;
    c.simplify();
    return c;
}

istream &operator>>(istream &in, fraction &f)
// input f in the form of a/b, where b cannot be zero. Also,
// if b is negative, the Fraction will change b to be positive.
// So, again, 1/-3 will be changed to -1/3
{
    char temp;
    in >> f.num >> temp >> f.den;
    if (f.den < 0)
    {
        f.num *= -1;
        f.den *= -1;
    }
    return in; // enables cascading eg cout << a << b;
}

ostream &operator<<(ostream &out, fraction &f)
// output a Fraction f in form of a/b
{
    out << f.num << " / " << f.den;
    return out; // enables cascading eg cout << a << b;
}

int main()
{
    int x, y;
    cout << "Please enter the value of num and den 1st: ";
    cin >> x >> y;
    fraction a(x, y);
    a.display();
    cout << "Please enter the value of num and den 2nd: ";
    cin >> x >> y;
    fraction b(x, y);
    b.display();

    cout << "--------------------------------" << endl;
    fraction c;

    c = a + b;
    cout << "a + b = ";
    c.display();
    c = a - b;
    cout << "a - b = ";
    c.display();

    c = a * b;
    cout << "a * b = ";
    c.display();
    c = a / b;
    cout << "a / b = ";
    c.display();

    return 0;
}

// Homework 12 - 1
// This code is created by Hanlin Cai
// MU  number : 20122161
// FZU number : 832002117