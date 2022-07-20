#include <iostream>
using namespace std;

struct Inventory 
{ 
    char description[50];
    int prodnum; 
    int quantity; 
    double price; 
};

int main()
{
    Inventory arr[100];
    arr[83].prodnum = 4355;
    cout << "Prodnum: " << arr[83].prodnum << endl;
    cout << "Price: " << arr[15].price << endl;

    return 0;
}
// Homework 13 - 1
// This code is created by Hanlin Cai
// MU  number : 20122161
// FZU number : 832002117