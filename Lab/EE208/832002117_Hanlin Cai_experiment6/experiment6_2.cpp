#include <iostream>
using namespace std;

void Print(int arr[], int length) {
	for (int i = 0; i < length; i++) {
		cout << arr[i] << " ";
	}
	cout <<endl;
}

int main() {

    // int arr[7] = { 1,2,3,4,5,6,7 };
	int length = 7;
	int arr[7];
    for (int i = 0; i < length; i++){
        cin >> arr[i];
    }

    int num;
	cin >> num;
	
    int temp;
	// Print(arr, length);
	for (int j = 0; j < num; j++) {
		//移动几次循环几次 How many moves and how many loops
		temp = arr[length-1];
		for (int i = 0; i<length; i++) {
			//从最后一位开始，移动一位 Start with the last digit and move one digit
			if (i == 0) {
				arr[length-1] = arr[0];
				//第一位的数等于最后一位的数
				//The first digit is equal to the last digit
			}
			else if(i!=length-1){
				arr[i-1] = arr[i];
				//让后一位等于前一位的数
				//Let the latter be equal to the former
			}
			else {
				arr[length-2] = temp;
				//Now it's left with the second-to-last number, which is not the original number, which is recorded in temp.
			}
		}
	}
	Print(arr, length);
	return 0;
}
//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117