#include<iostream>
using namespace std;

int main(){
    double arr[3];
    cout << "Please input the three numbers (x,y,z) :";
    for(int i = 0; i < 3; i++){
        cin >> arr[i];
    }

    for (int i = 0; i < 3; i++){
        for (int j = i-1; j >= 0; j--){
            if(arr[j+1] < arr[j]){
                double temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }else{
                break;
            }
        }
    }
    for (int i = 0; i < 3; i++){
        cout << arr[i] << " ";
    }


}