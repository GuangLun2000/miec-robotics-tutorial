#include <iostream>
using namespace std;

/*
The capit() function should capitalize the two letters 
and return the capitalized values to the calling function through its pointer arguments.
*/

void capit(string& str)
{
	int length = str.length();

	for (int i = 0; i < length; i++) {
		if (str[i] >= 'a' && str[i] <= 'z')
			// Convert lowercase to uppercase
			str[i] = str[i] - 32;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			// Convert uppercase to lowercase
			str[i] = str[i] + 32;
	}
}

int main()
{
    cout << "Please enter the string: ";
	string str = "";
    cin >> str;

    string str2 = str;    
	capit(str);

    cout << "Input: " << str2 << endl;
	cout << "Output: " << str;
	return 0;
}
// Homework 10 - 1
// This code is created by Hanlin Cai
// MU  number : 20122161
// FZU number : 832002117