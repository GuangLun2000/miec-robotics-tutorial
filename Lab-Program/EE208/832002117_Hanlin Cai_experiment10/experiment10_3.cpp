#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// There is a programming language with only four operations and one variable X...

int count(string str)
{
	int res = 0;
	string temp = "";
	int length = str.length();
	for (int i = 0; i < str.length() - 2; i++)
	{
		temp = str.substr(i, i + 2);
		if (temp == "X++")
			res++;
		if (temp == '++X')
			res++;
		if (temp == 'X--')
			res--;
		if (temp == '--X')
			res--;
	}

	return res;
}

int main()
{

	string str;

	cout << "Please enter the string : ";
	cin >> str;

	int res = count(str);

	cout << "Result : " << res << endl;
	return 0;
}
// Experiment 10 - 3
// This code is created by Hanlin Cai
// MU  number : 20122161
// FZU number : 832002117