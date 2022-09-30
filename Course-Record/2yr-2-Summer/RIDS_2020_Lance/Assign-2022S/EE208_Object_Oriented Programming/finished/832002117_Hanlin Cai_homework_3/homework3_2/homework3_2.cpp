#include<iostream>
#include <math.h>
using namespace std;

/*
E is the voltage of the battery in volts.
R is the value of the resistor in ohms.
C is the value of the capacitor in farads.
t is the time in seconds after the switch is closed.
e is Euler’s number, which is 2.71828 (rounded to five decimal places).
*/

int main(){
    double battery;//E
    double resistor;
    double capacitor;
    double time;
    double Euler = 2.71828;
    double current;
    cout << "Please input related circuit parameters : " << endl;
    cout << "voltage = ";
    cin >> battery;
    cout << "R = ";
    cin >> resistor;
    cout << "RC = ";
    cin >> capacitor;
    cout << "t = ";
    cin >> time;
    current = (battery/resistor) * pow(Euler,-(time/(resistor * capacitor)));
    cout << "Current = " << current << endl;

    return 0;
}

//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117