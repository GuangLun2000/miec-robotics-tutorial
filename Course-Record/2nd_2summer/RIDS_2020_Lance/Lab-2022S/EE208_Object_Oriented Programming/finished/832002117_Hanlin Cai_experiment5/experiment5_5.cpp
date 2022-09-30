#include<iostream>
using namespace std;


int maxDiff(int arr[], int arr_size)
{	
    int maxProfit = arr[1] - arr[0];
    for (int i = 0; i < arr_size; i++)
    {
        for (int j = i+1; j < arr_size; j++)
        {	
        if (arr[j] - arr[i] > maxProfit)
            maxProfit = arr[j] - arr[i];
        }
    }
    if (maxProfit > 0)
    {
        return maxProfit;
    } else{
        return 0;
    }
}

int main()
{
    int length;
    cout << "Please enter the length: ";
    cin >> length;
    int arr[length];
    cout << "Please enter the arr: ";
    for (int i = 0; i < length; i++){
        cin >> arr[i];
    }
    //int arr[] = {7,1,5,3,6,4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "The profit is " << maxDiff(arr, n);
    return 0;
}
//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117