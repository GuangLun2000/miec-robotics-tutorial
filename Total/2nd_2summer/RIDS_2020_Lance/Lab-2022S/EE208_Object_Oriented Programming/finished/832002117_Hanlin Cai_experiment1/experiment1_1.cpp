#include<stdio.h>
#include<iostream>
using namespace std;

// W, performed by a piston engine providing a force of 1000 N
// over a distance of 15 centimeters

int main(){
    int force;
    float distance;
    force = 1000;
    distance = 0.15;
    float W = force*distance;
    cout <<"W = "<< W << endl;

    return 0;
}

//this code is created by Lance Cai 832002117