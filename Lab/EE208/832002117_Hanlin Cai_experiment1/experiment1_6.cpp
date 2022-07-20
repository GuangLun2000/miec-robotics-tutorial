#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//Given an integer x, return true if x is palindrome integer.
//An integer is a palindrome when it reads the same backward as forward.
//For example, 121 is palindrome while 123 is not.

int main() {
	string a;
	cin >> a;
	string b = a;
	reverse(b.begin(), b.end());

	if (a == b) cout << a << " is a palindrome" << endl;
	else cout << a << " is not a palindrome" << endl;
	
    return 0;
}

//this code is created by Lance Cai 832002117