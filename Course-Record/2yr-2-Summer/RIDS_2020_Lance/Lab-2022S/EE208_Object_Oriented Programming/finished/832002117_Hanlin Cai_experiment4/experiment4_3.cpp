#include<iostream>
using namespace std;

int main(){
    int i = 0;
    double gallons;
    // cout << "Please input the" << i << "values of gallons : " << i << endl;

    while(i<10){
        cout << "Please input the " << i+1 << " values of gallons : " ;
        cin >> gallons;
        cout << "values of liters : " << gallons * 3.875 << endl;
        i++;
    }
    if (i==10)
    {
        cout << "--------------------------------OVER" << endl;
    }
    
    
    return 0;
}
//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117