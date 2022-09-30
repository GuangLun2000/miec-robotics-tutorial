#include<iostream>
using namespace std;

int main(){
    int num;
    int divisor;
    cout << "Please input the integer:" << endl;
    cin >> num;
    cout << "Please input the divisor:" << endl;
    cin >> divisor;

    // if(num/3 == 0){

    // }
    // if(num/7 == 0){

    // }
    // if(num/13 == 0){

    // }

    if(num%divisor == 0){
        cout << "The integer can be evenly divided by the divisor!" << endl;
    }else{
        cout << "The integer can not be evenly divided by the divisor!" << endl; 
    }
    

    return 0;
}