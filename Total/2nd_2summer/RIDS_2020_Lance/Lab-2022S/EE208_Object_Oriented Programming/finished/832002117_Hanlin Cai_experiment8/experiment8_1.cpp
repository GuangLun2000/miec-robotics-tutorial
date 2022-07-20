#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// Write a program that reads and displays every line in a file

int main()
{
	string str;
	ifstream infile;
	infile.open("test.txt");

	while (1) {
		infile >> str;
		if (infile.eof()) { //Check whether the file is closed
			break;
		}
		cout << str << endl;
	}

	// Close the open file
	infile.close();
	return 0;
}
//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117