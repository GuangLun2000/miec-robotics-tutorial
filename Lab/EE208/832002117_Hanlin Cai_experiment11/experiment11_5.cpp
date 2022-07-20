#include <iostream>
using namespace std;

/*
Next, have your program sum the numbers and store the result in a pointer-accessed location. 
Finally, have your program display the contents of all locations, again using pointer notation.
*/

int main()
{
    double array[10];
    int i;
    double *p = array;
    double res = 0.0;

    cout << "Input: ";
    for (i = 0; i < 10; i++)
    {
        cin >> *(p + i);
        // *res += array[i];
        res += *(p + i);
    }
    double *pp = &res;

    cout << "Result: "; 
    cout << *pp << endl;
    cout << "Array: ";
    for (p = array; p < (array + 10); p++)
    {
        cout << *p << " "; 
        // p - array[0] - array[10]
    }
    cout << endl;

    return 0;
}
// Homework 11 - 5
// This code is created by Hanlin Cai
// MU  number : 20122161
// FZU number : 832002117