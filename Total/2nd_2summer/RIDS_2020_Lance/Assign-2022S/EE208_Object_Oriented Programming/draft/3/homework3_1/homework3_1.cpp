#include<iostream>
using namespace std;

int main(){
    double x1;
    double x2;
    double y1;
    double y2;
    cout << "Please input the coordinates of first points :";
    cin >> x1 >> y1;
    cout << "Please input the coordinates of second points :";
    cin >> x2 >> y2;
    double x3 = (x1 + x2)/2;
    double y3 = (y1 + y2)/2;
    cout << "The coordinate of the midpoint is : (" << x3 << "," << y3 << ")";


    return 0;
}


//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117