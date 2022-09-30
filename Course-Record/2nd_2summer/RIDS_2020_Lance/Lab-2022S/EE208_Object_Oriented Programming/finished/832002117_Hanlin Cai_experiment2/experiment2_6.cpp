#include <iostream>
using namespace std;

// Returns floor of square root of integer
int floorSqrt(int x)
{
	// Base cases
	if (x == 0 || x == 1)
		return x;

	// Starting from 1, try all numbers until
	// i*i is greater than or equal to x.
	int i = 1, flag = 1;
	while (flag <= x)
	{
		i++;
		flag = i * i;
	}
	return i - 1;
}

// Driver program
int main()
{
	int x = 15;//the output = 3
	cout << floorSqrt(x) << endl;
	return 0;
}

//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117