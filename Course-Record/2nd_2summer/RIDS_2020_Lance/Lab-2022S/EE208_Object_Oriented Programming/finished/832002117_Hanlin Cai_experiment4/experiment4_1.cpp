#include<iostream>
using namespace std;

int main(){
    int integer;
    double value = 1;
    cout << "Please input the integer : ";
    cin >> integer;
    if (integer >= 0)
    {
        for (int i = 0; i < integer; i++)
        {  
            value = value * 2;
        }
    }else{
        //integer < 0
        for (int j = -1; j >= integer;)
        {
            // cout << value << endl;
            value = value / 2;
            j--;
        }
        
    }
    
    cout << value << endl;
    return 0;
}
//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117