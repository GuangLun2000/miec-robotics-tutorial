#include<stdio.h>
#include<iostream>
using namespace std;

//The velocity of water flowing into the tube is 1 ft/sec
//The input tube radius is 0.75
//And the output tube radius is 0.5

int main(){
    float Vout;
    float Vin;
    float Rout;
    float Rin;
    
    Vin = 1; 
    Rin = 0.75;
    Rout = 0.5;

    float temp = (Rin/Rout);
    Vout = Vin * temp *temp;
    cout << "Vout = " << Vout << endl;
    return 0;
}


//this code is created by Lance Cai 832002117