#include<iostream>
using namespace std;

int main(){
    
    double g = 32;
    double AllD;
    double eachD;
    double temp;

    for (int i = 1; i < 11; i++)
    {
        temp = 0.5 * g * (i-1) * (i-1);
        AllD = 0.5 * g * i * i;
        eachD = AllD - temp;

        cout << i << " : Distance in the Current Time Interval = " << eachD << " ft " << endl;
        cout << i << " : Total Distance until now = " << AllD << " ft " << endl;
    }
    
    
    return 0;
}
//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117