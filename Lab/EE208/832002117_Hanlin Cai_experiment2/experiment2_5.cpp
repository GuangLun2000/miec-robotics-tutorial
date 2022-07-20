#include <string>
#include <iostream>
using namespace std;

//Implement a method to perform basic string compression using the counts of repeated characters.

void printRepeated(string str)
{
	int n = str.length();
	for (int i = 0; i < n; i++) {

		// Count occurrences of current character
		int count = 1;
		while (i < n - 1 && str[i] == str[i + 1]) {
			count++;
			i++;
		}

		// Print character and its count
		cout << str[i] << count;
	}
}

int main()
{
	string str = "abbccd"; //a1b2c2d1

	//Input: "aabcccccaaa"
	//Output: "a2b1c5a3"

	printRepeated(str);
	return 0;
}
//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117