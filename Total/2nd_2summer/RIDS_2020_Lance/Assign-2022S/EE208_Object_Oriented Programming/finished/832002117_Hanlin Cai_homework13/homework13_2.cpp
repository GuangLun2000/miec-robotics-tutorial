#include <iostream>
using namespace std;

struct Factory
{
    char name[20];
    int age;
    int ssnumber;
    int hourWage;
    int workYears;

};

int main()
{
    Factory fac[50];
    cout << "Name: " << fac[25].name << endl;
    cout << "Work Year: " << fac[25].workYears << endl;
    
    fac[30].workYears = 1;
    fac[30].hourWage = 0;
    cout << "Hour Wage: " << fac[30].hourWage << endl;

    // The Loop:
    for (int i = 0; i <50 ; i++){
        for (int j = 0; j < 50; j++)
        {
            if (fac[i].workYears > j)
            {
                fac[i].hourWage += 50;
            }
        }
    }
    
    cout << "Hour Wage: " << fac[30].hourWage << endl;

    return 0;
}
// Homework 12 - 2
// This code is created by Hanlin Cai
// MU  number : 20122161
// FZU number : 832002117