#include <iostream>
using namespace std;

//Given an integer n, return true if it is a power of two. Otherwise, return false.

bool is2n(int dest)
{
	if (dest & (dest - 1)) //using the bit operation
		return false;
	else
		return true;
}

int main()
{
	if (is2n(1024))//true
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
}

//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117