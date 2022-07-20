#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// Read and Display the second character of each line in the file.

int main()
{
	string str;
    string str1;
	ifstream infile;
	infile.open("test.txt");

	while (1) {
		infile >> str;
		if (infile.eof()) { //Check whether the file is closed
			break;
		}
        str1 = str.substr(1,1);
		cout << str1 << endl;
	}

	// Close the open file
	infile.close();
	return 0;
}
//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117