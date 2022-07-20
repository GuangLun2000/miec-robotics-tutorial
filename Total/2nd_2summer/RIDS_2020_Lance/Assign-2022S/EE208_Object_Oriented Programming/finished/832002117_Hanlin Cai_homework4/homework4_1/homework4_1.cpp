#include<iostream>
using namespace std;

int main(){

    cout << "Please input working time : ";
    double hours;
    cin >> hours;
    
    if(hours < 0)
    {
        cout << "The time can not be negative, please reinput working time." << endl;
    }
    if(0<= hours && hours <= 40){
        cout << "Wages = " << hours * 12 << endl;
    }
    if(hours > 40){
        cout << "Wages = " << 480 + ((hours-40) * 17) << endl;
    }

    return 0;
}
//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117