#include <math.h>
#include<iostream>
using namespace std;

// Vout_a = 2.25 ft/sec
// Vout_b = 2.66667 ft/sec
// I had manually check the values, and it's correct.

int main() {
	double Vout1;
	double Vout2;
	double Vin1 = 1;
	double Rout1 = 0.5;
	double Rin1 = 0.75;
	double Vin2 = 1.5;
	double Rout2 = 0.75;
	double Rin2 = 1;

	Vout1 = Vin1 * pow(Rin1 / Rout1, 2);
	Vout2 = Vin2 * pow(Rin2 / Rout2, 2);
	
	cout << "Vout_a = " << Vout1 << " ft/sec" << endl;
	cout << "Vout_b = " << Vout2 << " ft/sec" << endl;

	return 0;
}

//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117