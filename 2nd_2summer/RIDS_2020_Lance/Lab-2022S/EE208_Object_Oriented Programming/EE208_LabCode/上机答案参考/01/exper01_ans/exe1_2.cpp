/*
Design, write, compile, and run a C++ program that calculates and displays the velocity of water 
flowing out of the tube shown in Figure 2.19. The velocity of water flowing into the tube is 1 ft/sec, 
the input tube radius is 0.75 , and the output tube radius is 0.5 .
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    double rin = 0.75;                      //the input tube radius
    double rout = 0.5;                      //the output tube radius
    int vin = 1;                            //The velocity of water flowing
    double vout = vin * pow(rin / rout, 2); //the velocity of water flowing out
    cout << vout << endl;
    return 0;
}