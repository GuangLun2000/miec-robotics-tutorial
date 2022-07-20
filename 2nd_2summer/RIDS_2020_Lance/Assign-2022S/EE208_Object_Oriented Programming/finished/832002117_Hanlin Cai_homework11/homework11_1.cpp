#include <iostream>
using namespace std;

/*
Construct a class named Savings containing three floating-point data members
named balance, rate, and interest and a constructor that initializes each data member to 0. 
*/

class savings {
    protected:
    float interest ,balance ,rate;

    public:
    void init(float balance, float rate, float interest);
    void setValue(float i, float j);
    float calculate();
    void getInterest();
    
};

void savings::init(float balance, float rate, float interest) {
    balance = 0;
    rate = 0;
    interest = 0;
}

void savings::setValue(float i, float j) {
    balance = i;
    rate = j;
}

float savings::calculate() {
    interest = this->balance * this->rate;
    return interest;
}

void savings::getInterest() {
    cout << "Interest: " << interest << endl;
}


int main() {

    savings user1;
    // savings user2;

    cout << "Please input the balance: " ;
    float balance;
    cin>> balance;
    
    cout << "Please enter the rate: ";
    float rate;
    cin >> rate;
    
    user1.setValue(balance,rate);
    // user1.setValue(1000 , 0.1);

    user1.calculate();
    user1.getInterest();

    return 0;
}
// Homework 11 - 1
// This code is created by Hanlin Cai
// MU  number : 20122161
// FZU number : 832002117