#include<cstdio>
#include<iostream>
#include<cmath>
#include<math.h>
using namespace std;

//use your program to determine the fourth roots of 42, 121, 256, 587, 1240, and 16,256

int main(){

    double a1 = 42;
    double a2 = 121;
    double a3 = 256;
    double a4 = 587;
    double a5 = 1240;
    double a6 = 16256;

    double b1 = pow(a1,1.0/4.0);
    double b2 = pow(a2,1.0/4.0);
    double b3 = pow(a3,1.0/4.0);
    double b4 = pow(a4,1.0/4.0);
    double b5 = pow(a5,1.0/4.0);
    double b6 = pow(a6,1.0/4.0);

    cout << b1 << endl;    
    cout << b2 << endl;
    cout << b3 << endl;
    cout << b4 << endl;
    cout << b5 << endl;
    cout << b6 << endl;    

    return 0;
}

//this code is created by Lance Cai 832002117