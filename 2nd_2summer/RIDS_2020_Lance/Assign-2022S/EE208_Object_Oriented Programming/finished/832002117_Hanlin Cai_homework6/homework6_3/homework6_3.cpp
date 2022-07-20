#include <iostream>
using namespace std;

/**
 * @brief Using Euclid’s algorithm, replace the stub function written for Exercise 9
 * with an actual function that determines and returns the GCD of its two integer arguments.
 */

int gcd(int a, int b)
{
    // Recursive function
	return b == 0 ? a : gcd(b, a % b);
}

int main()
{
	int a = 0, b = 0;
    cout << "Please enter the two numbers: ";
    cin >> a >> b;
	cout << "GCD of " << a << " and " << b << " is " << gcd(a, b);
	return 0;
}
//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117