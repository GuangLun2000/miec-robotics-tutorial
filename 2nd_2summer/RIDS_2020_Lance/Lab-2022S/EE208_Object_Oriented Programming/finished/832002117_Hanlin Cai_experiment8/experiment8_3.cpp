#include <iostream>  
#include <assert.h>
#include <vector>
#include <fstream>
using namespace std;

// Reads the specified line of the TXT file

int CountLines(string filename)
{
	ifstream ReadFile;
	int count = 0;
	string tmp;
	ReadFile.open(filename.c_str());
    //ios::in , indicates that a file is read only
    
    if (ReadFile.fail())
	{
		return 0;
	}
	else
	{
		while (getline(ReadFile, tmp, '\n'))
		{
			count++;
		}
		ReadFile.close();
		return count;
	}
}

string ReadLine(string filename, int line)
{
	int lines, i = 0;
	string temp;
	fstream file;
	file.open(filename.c_str());
	lines = CountLines(filename);

	if (line <= 0)
	{
		return "Error : Input error, cannot be 0 or negative!";
	}
	if (file.fail())
	{
		return "Error : The file does not exist!";
	}
	if (line > lines)
	{
		return "Error : The input num exceeds the file length!";
	}
	while (getline(file, temp) && i < line - 1)
	{
		i++;
	}
	file.close();
	return temp;
}

int main()
{
    string filename = "test.txt";
	// int line = 100;
    cout << "Please enter the line number : ";
    int line;
    cin >> line;

	string tmp = ReadLine(filename, line);
	cout << tmp << endl;
	
	// printf("Done!\n");
	return 0;

}
//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117