#include <math.h>
#include<iostream>
using namespace std;

// 1 feet = 12 inch

int main() {
	double L;
	double S;
	double I;
	double d;
	double c;
	//double base;
	//double height;
	
	//base = 2;
	//height = 4;
	S = 20000;
	d = 8 * 12;
	//c = height / 2;
	c = 3;
	
	//I = (base * pow(height, 3)) / 12;
	I = 21.4;
	
	L = (S * I) / (d * c);

	cout << "L = " << L << " (lbs)" << endl;

	return 0;
}



//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117