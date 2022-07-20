#include<iostream>
using namespace std;

int main(){
    int num;
    int divisor;
    cout << "Please input the integer : ";
    cin >> num;
    cout << "Please input the divisor : ";
    cin >> divisor;

    // if(num % 2 == 0){
    //     cout << "the number is even" << endl;
    // }else{
    //     cout << "the number is odd" << endl;
    // }

    if(num % divisor == 0){
        cout << "The integer can be evenly divided by the divisor!" << endl;
    }else{
        cout << "The integer can not be evenly divided by the divisor!" << endl; 
    }

    return 0;
}

//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117