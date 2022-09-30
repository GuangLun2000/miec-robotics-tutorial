#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// Read the file created in a., sort the data alphabetically by city name, and display the data.

struct City {
    // int id;
    string city_name;
}info[8];

// int n;

bool cmp(City p1, City p2) {
    return p1.city_name < p2.city_name;
}

int main()
{
	// string str;
	// ifstream infile;
	// infile.open("test.txt");
	ifstream in( "file.txt" , ios::in);

	if (!in.is_open())
    {
        cout <<  "Error: opening file fail"  << endl;
        exit (1);
    }

	int i = 0;
    while (!in.eof() && i < 8)
    {
        in >> info[i].city_name;
        i++;
    }
    
	sort(info, info+8, cmp);

    for (int i = 0; i < 8; i++) {
        cout  << info[i].city_name << endl;

	}

	// Close the open file
	in.close();
	return 0;

}
//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117