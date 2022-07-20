#include <iostream>
#include <string>
using namespace std;

/*
240.5,300.0,189.6,310.6, 280.7, 216.9, 199.4, 160.3, 177.4, 192.3
10.3,15.6,8.7,14, 16.3, 15.7, 14.9, 10.7, 8.3, 8.4

mpg[0] = miles[0] / gallons[0]
*/

void arrayMultiply(double firstArray[], double secondArray[], double targetArray[], int size)
{
    double *firstPtr = firstArray;
    double *secondPtr = secondArray;
    double *tragetPtr = targetArray;

    while (firstPtr <= &firstArray[size - 1])
    {
        // multiply the first two array elements,
        *tragetPtr = (*firstPtr) / (*secondPtr);

        // point to the next location.
        *firstPtr++;
        *secondPtr++;
        *tragetPtr++;
    }
}

int main()
{
    double miles[10] = {240.5,300.0,189.6,310.6, 280.7, 216.9, 199.4, 160.3, 177.4, 192.3};
    double gallons[10] = {10.3,15.6,8.7,14, 16.3, 15.7, 14.9, 10.7, 8.3, 8.4 };
    double mpg[10];

    arrayMultiply(miles, gallons, mpg, 10);

    cout << "The conents of 2 arrays multiply together is : " << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << mpg[i] << " ";
    }

    return 0;
}

// Homework 11 - 1
// This code is created by Hanlin Cai
// MU  number : 20122161
// FZU number : 832002117