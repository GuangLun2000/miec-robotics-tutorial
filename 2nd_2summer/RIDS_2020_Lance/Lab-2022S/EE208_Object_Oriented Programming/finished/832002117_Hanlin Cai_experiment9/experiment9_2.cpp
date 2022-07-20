#include<iostream>
#include<string>
#include<vector>
#include<cctype>
using namespace std;

// Counts the number of words in a string.

int countWords(string s)
{
	int count = 1;
	for(int i = 0; i <= s.size(); i++){
		if(s[i] == ' '){
			count ++;
		}
	}

	return count;
}

int main() {
	cout << "Please enter the string : ";
	string str;
    getline(std::cin, str);
    // cout << " " <<endl;
	cout << "Count : "<< countWords(str);
	return 0;
}
//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117