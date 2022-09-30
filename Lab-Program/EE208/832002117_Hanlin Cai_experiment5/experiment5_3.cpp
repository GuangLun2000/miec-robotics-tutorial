#include<iostream>
using namespace std;

int calculateOdd(int num1, int num2){
    int sum = 0;
    for(int i =num1; i <= num2; i++){
        if (i%2!=0)
        {
            sum += i;
        }
    }
    return sum;
}

int main() {
    
    int length;
    cout << "Please enter how many pairs: ";
    cin >> length;
    int num[length*2];
    cout << "Please enter all of the num: ";
    for (int i = 0; i < length*2 ; i++) {
        cin >> num[i];
    }

    // for (int i = 0; i < length*2; i++) {
    //     cout << num[i] << endl;
    // }


    int oddSum[length];
    for (int i = 0; i < length*2;)
    {
        int temp = calculateOdd( num[i] , num[i+1] );
        
        oddSum[i] = temp;

        // cout << temp << endl;
        i = i + 2;
    }


    // for (int i = 0; i < length*2;)
    // {
    //     cout << "oddSum= " << oddSum[i] << endl;
    //     i++; //
    // } 


    //output the max
    int max = oddSum[0];
    for (int i = 1; i < length; i++)
    {
        if (oddSum[i]>max)
        {
            max = oddSum[i];
        }else{
            continue;
        }
    }
    
    cout << "max = " << max << endl;

    return 0;
}
//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117