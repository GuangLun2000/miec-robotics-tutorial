#include <iostream>
#include <algorithm>
#include <vector>

#define M 2
#define N 6
using namespace std;

int main()
{

	int a[N][M] = {
		{1001, 62},
		{949, 85},
		{1050, 33},
		{867, 125},
		{346, 59},
		{1025, 105}};

	cout << "--------------------------------" << endl;
	int i, j;
	// Displays data in the array in decreasing quantity order
	cout << "Displays data in the array in decreasing quantity order : " << endl;
	for (i = 0; i < N - 1; i++)
	{
		for (j = i + 1; j < N; j++)
		{
			if (a[i][1] < a[j][1])
				swap(a[i], a[j]);
		}
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
			cout << a[i][j] << " ";
		cout << " " << endl;
	}

	cout << "--------------------------------" << endl;

	// Display the data in part number order
	cout << "Display the data in part number order : " << endl;
	for (i = 0; i < N - 1; i++)
	{
		for (j = i + 1; j < N; j++)
		{
			if (a[i][0] < a[j][0])
				swap(a[i], a[j]);
		}
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
			cout << a[i][j] << " ";
		cout << " " << endl;
	}

	return 0;
}
// This code is created by Hanlin Cai
// MU  number : 20122161
// FZU number : 832002117