/*
Write a C++ program to calculate the circumference of a circle having a radius of 3.3 inches. 
The formula for determining the circumference, c, of a circle is c = 2πr, where r is the radius and π equals 3.1416.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    double r = 3.3;        //radius
    double pi = 3.1416;    //π
    double c = 2 * pi * r; //circle
    cout << c << endl;
    return 0;
}