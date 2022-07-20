/*
Using this formula, write a program that calculates and displays the value of π,
using 2, 3, and 4 terms of the series
*/

#include <bits/stdc++.h>
using namespace std;

double figurePi(int t)
{
    double res = 0; //store results
    for (int j = 1, i = 1; j <= t; j++, i += 2)
    {
        if (j % 2)
        {
            res += 1.0 / i; //i represents the current denominator
        }
        else
        {
            res += -1.0 / i;
        }
    }
    return 4 * res;
}

int main()
{
    cout << figurePi(2) << endl;
    cout << figurePi(3) << endl;
    cout << figurePi(4) << endl;
    return 0;
}