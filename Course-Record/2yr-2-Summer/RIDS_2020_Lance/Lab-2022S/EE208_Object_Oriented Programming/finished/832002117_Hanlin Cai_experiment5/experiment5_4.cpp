#include<iostream>
using namespace std;

int magicNumber(int a, int b, int temp) {
    int sum = 0;
    for (int i = 0; i < b; i++)
    {   
        sum += a;
        a = (a*10) + temp;
    }
    return sum;

}

int main(){

    int a;
    cout << "Please enter the first number: ";
    cin >> a;
    const int temp = a ;
    int b;
    cout << "Please enter the second number: "; 
    cin >> b;
    int c = magicNumber(a, b ,temp);
    cout << c << endl;
    return 0;
}
//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117