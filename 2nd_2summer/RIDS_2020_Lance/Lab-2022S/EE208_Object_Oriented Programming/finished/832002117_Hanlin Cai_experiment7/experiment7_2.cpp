#include <iostream>
using namespace std;

// exper7_2 Magic Index

int linearSearch(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++) {
		if (arr[i] == i)
			return i;
	}

	/* If no magic index present then */
	return -1;
}


int main()
{
	cout << "Please the length: ";
    int length;
    cin >> length;
	int arr[length];
    cout << "Please enter all of the num: ";
    for (int i = 0; i < length; i++) {
        cin >> arr[i];
    }

	cout << "Magic Index : " << linearSearch(arr, length);
	return 0;
}
//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117