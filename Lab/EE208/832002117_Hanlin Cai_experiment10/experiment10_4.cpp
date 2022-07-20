#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// Given a string s, remove duplicate letters so that every letter appears once and only once.

char *removeDuplicate(char str[], int n)
{
    // Used as index in the modified string
    int index = 0;

    // Traverse through all characters
    for (int i = 0; i < n; i++)
    {

        // Check if str[i] is present before it
        int j;
        for (j = 0; j < i; j++)
        {
            if (str[i] == str[j])
                break;
        }
        // If not present, then add it to result.
        if (j == i)
        {
            str[index++] = str[i];
        }
    }

    return str;
}

int main()
{
    // char str[] = "bcabc";
    char str[] = "cbacdcbc";
    int n = sizeof(str) / sizeof(str[0]);
    cout << removeDuplicate(str, n);
    return 0;
}
// Experiment 10 - 4
// This code is created by Hanlin Cai
// MU  number : 20122161
// FZU number : 832002117