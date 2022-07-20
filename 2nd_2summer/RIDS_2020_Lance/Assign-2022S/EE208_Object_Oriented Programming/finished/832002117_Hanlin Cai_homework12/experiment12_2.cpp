#include <iostream>
using namespace std;


class Cartesian{
    protected:
    double x, y;

    public:
    void constructor(){
        x = 0;
        y = 0;
    }
    void showData();
    void setData();
    void assignmentFunc(Cartesian num1, Cartesian num2);

};

void Cartesian::setData(){
    cout << "Please enter the x and y: ";
    cin >> x;
    cin >> y;
    cout << "The Cartesian coordinates are: ";
    cout << x << " " << y << endl;
    return;
}

void Cartesian::assignmentFunc(Cartesian num1, Cartesian num2){
    num2 = num1;
    num2.showData();
    
    return;
}

void Cartesian::showData(){
    cout << "The Cartesian coordinates are: ";
    cout << x << " " << y << endl;
    return;
}

int main(){
    Cartesian c1,c2;
    c1.setData();
    cout << "-----------------------------------" << endl;
    c2.assignmentFunc(c1,c2);
    
    return 0;
}

// Homework 12 - 2
// This code is created by Hanlin Cai
// MU  number : 20122161
// FZU number : 832002117