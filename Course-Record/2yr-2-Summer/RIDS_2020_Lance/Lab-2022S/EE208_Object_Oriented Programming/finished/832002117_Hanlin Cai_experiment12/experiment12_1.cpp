#include <iostream>
#include <math.h>
using namespace std;

/*
It is required to input the information of three sides of the triangle
to determine whether the triangle is formed, if not, output the error information,
and if so, call the output function to output the information.
*/

class Tri {
    private:
    double tri1;
    double tri2;
    double tri3;
    double perimeter;
    double area;
    double temp;

    public:
    bool Validate(double i, double j, double k);
    void init(double i, double j, double k);
    void calc();
};

bool Tri::Validate(double i, double j, double k) {
	if((i>0) && (j>0) && (k>0)) {
		if((i+j)<=k) return 0;
		if((i+k)<=j) return 0;
		if((k+j)<=i) return 0;

		return 1;
	} else {
		return 0;
	}
}

void Tri::init(double i, double j, double k) {
    tri1 = i;
    tri2 = j;
    tri3 = k;
    cout<< "The 3 edge: " <<tri1<<" "<<tri2<<" "<<tri3 <<endl;
}

void Tri::calc() {
    perimeter = tri1 + tri2 + tri3;
    cout << "Perimeter: " << perimeter << endl;
    temp = perimeter/2;
    double area = sqrt( temp*(temp-tri1)*(temp-tri2)*(temp-tri3) );
    cout << "Area: " << area << endl;
}

int main() {
    Tri triangle1;
    double i, j, k;
    cout << "Please enter the three sides of the triangle: ";
    cin >> i >> j >> k;

    if(triangle1.Validate(i, j, k)){
		triangle1.init(i, j, k);
        triangle1.calc();
    } else {
		cout << "No Triangle!" << endl;
    }
    
    
    return 0;   
}
// Experiment 12 - 1
// This code is created by Hanlin Cai
// MU  number : 20122161
// FZU number : 832002117