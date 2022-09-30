#include<iostream>
using namespace std;

int main(){

    int arr[3];
    cout << "Please input the three cards :";
    for(int i = 0; i < 3; i++){
        cin >> arr[i];
    }
    
    // for(int i = 0; i < 3; i++){
    //     cout << arr[i] << " ";
    // }

    int flag;
    double sum = 0.0;

    // Check if the input has ace
    for(int i = 0; i < 3; i++){
        if(arr[i] == 1){
            flag = 1;
        }
    }

    // Calculate the current total
    for(int i = 0; i < 3; i++){
            sum = sum + arr[i];
    }

    // cout
    if(flag == 1){
        if ((sum+10) <= 21)
        {
            cout << "Sum=" << sum + 10;
        }else{
            cout << "Sum=" << sum;
        }
    }else{
        cout << "Sum=" << sum;
    }

}
//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117