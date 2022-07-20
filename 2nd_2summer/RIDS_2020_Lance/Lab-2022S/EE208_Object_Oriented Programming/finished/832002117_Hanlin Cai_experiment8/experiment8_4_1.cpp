#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

// Accept data for a number of cities from the keyboard && Store the data in a file.

int main() {
	char* p = new char[100];
	ofstream outfile;
	outfile.open("file.txt", ios::out | ios::app);//输入文件的路径

    cout << "Writing to the file : ";
    cout << "--------------------------------" << endl;

	cin.getline(p, 100); 
	outfile << p<< endl;
	outfile.close();  //调用close（）函数关闭文件
	delete[] p;
	return 0;
}
//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117