#include <iostream>
#include <string>
using namespace std;

// Enter a string and print whether the string is a palindrome.
// A palindrome is a string that reads the same backwards and forwards.

bool isPalRec(char str[],int s, int e)
{
	
	// Only 1 char
	if (s == e)
	return true;

    // Only 2 char
	// Check if first and last characters do not match
	if (str[s] != str[e])
	return false;

	// If there are more than 2 char, check if
	// middle substring is also palindrome or not
	if (s < e + 1) return isPalRec(str, s + 1, e - 1);

	return true;
}

bool isPalindrome(char str[])
{
	int n = strlen(str);
	if (n == 0) return true;
	
	return isPalRec(str, 0, n - 1);
}

int main()
{
    cout << "Please enter the char : ";
	char str[20];
    scanf("%s", str);

	if (isPalindrome(str))
	cout << "Yes";
	else
	cout << "No";

	return 0;
}
//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117