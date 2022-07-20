#include<iostream>
using namespace std;

bool isPerfect(int num)
{
	int sum = 1;

	// Find all divisors and add them
	for (int i=2; i*i<=num; i++)
	{
		if (num%i==0)
		{
			if(i*i!=num)
				sum = sum + i + num/i;
			else
				sum=sum+i;
		}
	}
	// If sum of divisors is equal to
	// n, then n is a perfect number
	if (sum == num && num != 1)
		return true;

	return false;
}

int main()
{
    int num;
    cout << "Please enter the number: ";
    cin >> num;
    if (isPerfect(num))
    {
        cout << "true";
    } else {
        cout << "false";
    }
    


	return 0;
}
//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117