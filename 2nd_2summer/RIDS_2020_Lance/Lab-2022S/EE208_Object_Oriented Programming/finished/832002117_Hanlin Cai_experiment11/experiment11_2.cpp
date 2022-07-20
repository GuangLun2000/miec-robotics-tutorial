#include <iostream>
using namespace std;

// Use Pointers to write a function to bubble sort an integer array.
// 3 5 2 8 2 9 5 1

void BubbleSort(int *arr, int len)
{
    for (int i = 0; i < len - 1; i++)
        for (int j = 0; j < len - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // int tmp = arr[j];
                // arr[j] = arr[j + 1];
                // arr[j + 1] = tmp;
                swap(arr[j], arr[j + 1]);
            }
        }
}

void PrintArray(int *arr, int len)
{
    cout << "Output: ";
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    // int arr[10] = {2, 3, 1, 5, 9, 10, 12, 15, 0, 4};
    // int len = sizeof(arr) / sizeof(arr[0]);
    cout << "Please enter the len: ";
    int len;
    cin >> len;
    int arr[len];
    cout << "Please enter the array: ";
    for (int i = 0; i < len ; i++){
        cin >> arr[i];
    }

    BubbleSort(arr, len);
    PrintArray(arr, len);

    return 0;
}
// Homework 11 - 2
// This code is created by Hanlin Cai
// MU  number : 20122161
// FZU number : 832002117