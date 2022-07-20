#include <iostream>
using namespace std;

void Print(int arr[], int length) {
	for (int i = 0; i < length; i++) {
		if (arr[i]>=0)
            cout << arr[i] << " ";
	}
	cout <<endl;
}

void BubbleSort(int arr[], int length) {
    //从小到大排序
	int temp;
	for (int i = 0; i < length - 1; i++) {
		for (int j = length - 1; j > i; j--) {
			if (arr[j] < arr[j - 1]) {
				temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
		}
	}
}

int main(){
    int count = 0;
    int array[100];
    printf("please enter the array: \n");
    do{
        scanf("%d" , &array[count]);
        count++;
    }while(array[count-1] >= 0);
    
    BubbleSort(array,count);
    Print(array,count);

}
//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117