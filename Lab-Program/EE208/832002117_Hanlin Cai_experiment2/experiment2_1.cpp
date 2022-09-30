#include<iostream>
using namespace std;

// Given a signed 32 - bit integer x, return x with its digits reversed

long reverse(int x) {
	
	//Judge the sign first
	int symbol = 1; 
	long remainder = 0, num = 0;
	if (x < 0) {
		symbol = -1; 
		x = -x;
	}

	while (x != 0)
	{
		remainder = x % 10;
		x /= 10;
		num = num * 10 + remainder;

	}

	return symbol * num;
}

int main()
{
	int num;
	cin >> num; //input the num
	cout << reverse(num);
	return 0;
}


//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117