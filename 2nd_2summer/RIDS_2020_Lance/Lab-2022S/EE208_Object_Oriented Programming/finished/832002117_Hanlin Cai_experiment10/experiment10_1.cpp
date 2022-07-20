#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// Write a C++ program that accepts a string from the user
// and then replaces all occurrences of the letter e with the letter x.

void replaceCharacter(char input[], char c1, char c2)
{
	// If the string is empty
	if (input[0] == '\0')
	{
		return;
	}

	// If the character at starting of the given string is equal to c1, replace it with c2
	if (input[0] == c1)
	{
		input[0] = c2;
	}

	// Getting the answer from recursion for the smaller problem
	return replaceCharacter(input + 1, c1, c2);
}

int main()
{
	cout << "Please enter the string: ";
	// char str[] = "abcdeeeee";
	char str[] = "";
	cin >> str;

	char c1 = 'e';
	char c2 = 'x';

	replaceCharacter(str, c1, c2);
	cout << "The return string is : " << str;

	return 0;
}
// Experiment 10 - 1
// This code is created by Hanlin Cai
// MU  number : 20122161
// FZU number : 832002117