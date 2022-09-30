#include <iostream>
using namespace std;

/*
Starting with any positive integer, replace the number
by the sum of the squares of its digits. Repeat the process until the number equals 1
(where it will stay), or it loops endlessly in a cycle which does not include 1
*/

int numSquareSum(int n)
{
	int squareSum = 0;
	while (n)
	{
		squareSum += (n % 10) * (n % 10);
		n /= 10;
	}
	return squareSum;
}

// method return true if n is Happy number
bool isHappynumber(int n)
{
	int slow, fast;

	// initialize slow and fast by n
	slow = fast = n;
	do
	{
		// move slow number by one iteration
		slow = numSquareSum(slow);

		// move fast number by two iteration
		fast = numSquareSum(numSquareSum(fast));

	} while (slow != fast);

	// if both number meet at 1, then return true
	return (slow == 1);
}

// Driver code to test above methods
int main()
{
	int n = 13;
	if (isHappynumber(n))
		cout << n << " is a Happy number\n";
	else
		cout << n << " is not a Happy number\n";
}

//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117