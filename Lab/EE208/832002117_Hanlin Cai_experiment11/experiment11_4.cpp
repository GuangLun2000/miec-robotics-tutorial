#include<iostream>
#include<string>
using namespace std;

// C++ program to find Maximum difference
// between two elements such that larger
// element appears after the smaller number.
// 4 8 2 23 32 13 42 66 24 10

int maxDifference(int arr[], int n) {
	int diff = arr[1] - arr[0];
	int current = diff;
	int max = current;

	for(int i=1; i < n-1; i++)
	{
		// Calculate current diff
		diff = arr[i+1]-arr[i];

		// Calculate current sum
		if (current > 0)
		current += diff;
		else
		current = diff;

		// Update max sum, if needed
		if (current > max)
		max = current;
	}

	return max;
}

int main() {
    cout << "Please input 10 integers: " << endl;
    int arr[10];
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

    cout << "The difference between the maximum and the minimum is: " << maxDifference(arr, 10);

    return 0;
}
// Homework 11 - 4
// This code is created by Hanlin Cai
// MU  number : 20122161
// FZU number : 832002117