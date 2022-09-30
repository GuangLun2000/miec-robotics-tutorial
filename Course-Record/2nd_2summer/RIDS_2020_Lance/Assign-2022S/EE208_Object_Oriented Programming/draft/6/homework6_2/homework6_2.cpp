#include<iostream>
using namespace std;

int main(){
    double money = 0.01;
    double count = 0.00;
    for(int i = 0; i <64 ; i++){
        money = money * 2;
        cout << "Day" << i+1 << " King must pay the beggar: "<< money << endl;
        count += money;
        // cout << count << endl;
        if (count >= 1000000)
        {
            cout << "--------------------------------------------" << endl;
            cout << "In Day" << i+1 << " The king will have paid the beggar a total of one million dollars." << endl;
            break;
        }
        
    }
    return 0;
}
//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117