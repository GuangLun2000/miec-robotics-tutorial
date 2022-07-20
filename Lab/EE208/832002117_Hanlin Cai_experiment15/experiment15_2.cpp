#include <iostream>
using namespace std;

struct Fraction{
    int num;
    int den;
    int temp;
};

Fraction multiply(Fraction f1, Fraction f2){
    Fraction res;
    res.num = f1.num * f2.num;
    res.den = f1.den * f2.den;
    return res;
}

void PrintFraction(Fraction pFraction)
{
    cout << "Product: " << pFraction.num << "/" << pFraction.den;
}

int main()
{
    Fraction f1,f2;
    cout << "Enter the numerator and denominator of the first fraction: ";
    cin >> f1.num >> f1.den;
    cout << "Enter the numerator and denominator of the second fraction: ";
    cin >> f2.num >> f2.den;
    Fraction product;
    product = multiply(f1,f2);

    PrintFraction(product);

    // product.temp = (int)product.num / (int)product.den;
    // cout << endl;
    // cout << "Product: " << product.temp << i << endl;

    return 0;
}
// Experiment 15 - 2
// This code is created by Hanlin Cai
// MU  number : 20122161
// FZU number : 832002117