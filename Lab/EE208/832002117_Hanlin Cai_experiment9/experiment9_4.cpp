#include<iostream>
#include<string>
#include<vector>
#include<cctype>
using namespace std;

// Count the number of occurrences of each letter of the input string, case – insensitive.

int main()
{
	string line; 
	getline(cin, line);
	vector<int> ivec(26,0); //count == 0;

	for (auto& c : line) // Use references to modify the values of characters in line
	{
		c = toupper(c);
		static_cast<int>(c);
		if (c >= 65 && c <= 90) //'A' = 65 'Z' = 90
			ivec[c - 65] += 1; 
            // Use the ASCII subscripts for 'A' and 'Z'

	}

	for (auto i = 0; i < 26; i++)

        if (ivec[i] > 0)
        {
            cout << "The number of " << static_cast<char>(i + 65 + 32) <<" is " << ivec[i] << endl;
        }
    
}
//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117