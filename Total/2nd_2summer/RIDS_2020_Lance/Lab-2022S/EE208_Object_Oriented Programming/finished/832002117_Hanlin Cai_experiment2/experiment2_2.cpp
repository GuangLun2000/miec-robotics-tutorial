#include <iostream>
#include <climits>
using namespace std;

int IsUgly(int num)
{
	while (num % 2 == 0)
	{
		num /= 2;
	}
	while (num % 3 == 0)
	{
		num /= 3;
	}
	while (num % 5 == 0)
	{
		num /= 5;
	}

	if (num == 1)
		return 1; //It is an ugly number
	else
		return 0; //It is not an ugly number
}

int main()
{
	int number;
	cout << "Input a number : ";
	cin >> number;
	int temp = IsUgly(number);
	if (temp == 1) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}


	return 0;
}

//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117