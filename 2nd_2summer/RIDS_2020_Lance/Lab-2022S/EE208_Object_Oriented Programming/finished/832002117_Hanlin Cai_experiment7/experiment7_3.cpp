#include <iostream>
using namespace std;

// exper7_3 sort the even and odd numbers in the array, respectively

void swap(int *a, int *b);

void segregateEvenOdd(int arr[], int length)
{
	/* Initialize left and right indexes */
	int left = 0, right = length-1;
	while (left < right)
	{
		/* Increment left index while we see 0 at left */
		while (arr[left] % 2 == 0 && left < right)
			left++;

		/* Decrement right index while we see 1 at right */
		while (arr[right] % 2 == 1 && left < right)
			right--;

		if (left < right)
		{
			/* Swap arr[left] and arr[right]*/
			swap(&arr[left], &arr[right]);
			left++;
			right--;
		}
	}

    // sort(arr, arr+length);
    // sort the even and odd numbers
    sort(arr, arr + left);
    sort(arr + left,arr + length);

}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
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

	int i = 0;

	segregateEvenOdd(arr, length);

	cout <<"New array :";
	for (i = 0; i < length; i++)
		cout << arr[i] << " ";

	return 0;
}
//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117