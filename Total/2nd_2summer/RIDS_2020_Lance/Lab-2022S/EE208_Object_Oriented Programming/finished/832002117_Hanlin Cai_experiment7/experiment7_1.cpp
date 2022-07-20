#include <iostream>
using namespace std;

// exper7_1 findMajority in the array

void findMajority(int arr[], int n)
{
	int flag = 0;
	int index = 0;
	for (int i = 0; i < n; i++) {
		int count = 0;
		for (int j = 0; j < n; j++) {
			if (arr[i] == arr[j])
				count++;
		}

		// if count of current element is greater
		if (count > flag) {
			flag = count;
			index = i;
		}
	}

	// if (flag > n/2), then return the element
	if (flag > n / 2)
		cout << "Majority Element : " <<arr[index] << endl;

	else
		cout << "No Majority Element" << endl;
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
    
	findMajority(arr, length);

	return 0;
}
//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117