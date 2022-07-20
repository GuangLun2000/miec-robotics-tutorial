#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int i;
    cout << "1" << endl;
    for (i=2; i <= 100; i++)
    {
        int j = 2;
        for (; j <= i; j++)
        {
            if (i%j == 0)
                break;
        }
        if (j>=sqrt(i)) //Reduced number of comparisons
        {
            cout << i << endl;
        }
    }
    cout << "\n "<< endl;
}
//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117