#include <iostream>
#include <string>
using namespace std;

// The program should determine how many times the character is contained in the string.

int count(string str, char c)
{
	int res = 0;
	for (int i=0;i<str.length();i++){
		if (str[i] == c) res++;
    }
	return res;
}

int main()
{
    cout << "Please enter the string : ";
	string str;
    cin >> str;

    cout << "Please enter the character : ";
	char c;
    cin >> c;

	cout << "Times : " << count(str, c) << endl;
	return 0;
}
//Experiment 9 - 1
//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117