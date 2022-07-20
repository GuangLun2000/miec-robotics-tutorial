#include<iostream>
using namespace std;

/*
Find First and Last Position of Element in Sorted Array.
Given an array of integers nums sorted in ascending order,
find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
*/

void findFirstAndLast(int arr[], int n, int x)
{
	int first = -1, last = -1;
	for (int i = 0; i < n; i++) {
		if (x != arr[i])
			continue;
		if (first == -1)
			first = i;

		last = i;
	}

	if (first != -1)
		cout << "[" << first << "," << last << "]";
	else
		cout << "[-1,-1]";
}

int main()
{
	int arr[] = { 5,7,7,8,8,10 };
	int n = sizeof(arr) / sizeof(int);
	int x = 6;
	findFirstAndLast(arr, n, x);
	return 0;
}

//this code is created by Lance Cai 832002117