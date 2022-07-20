#include <iostream>
#include <string>
using namespace std;

// The program should determine how many times the character is contained in the string.

int count(string str1, string str2)
{
	int res = 0;
	int length = str1.length();
	for (int i = 0; i < ( str2.length()-str1.length() ); i++)
	{
		string temp = str2.substr(i,i+length);
		if (temp == str1)
			res++;
	}
	return res;
}

int main()
{

	string str1;
	string str2;

	cout << "Please enter the character : ";
	cin >> str1;

	cout << "Please enter the string : ";
	cin >> str2;

	int res = count(str1, str2);

	cout << "Times : " << res << endl;
	return 0;
}
// Experiment 10 - 2
// This code is created by Hanlin Cai
// MU  number : 20122161
// FZU number : 832002117