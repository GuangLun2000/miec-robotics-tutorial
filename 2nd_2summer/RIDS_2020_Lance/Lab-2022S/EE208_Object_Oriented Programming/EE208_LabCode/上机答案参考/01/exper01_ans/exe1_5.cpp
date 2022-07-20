/*
Write, compile, and run a program to calculate and display the fourth root of a user-entered number. 
Recall from elementary algebra that you find the fourth root of a number by raising the number to the 1/4 power.
 (Hint: Don’t use integer division—can you see why?) Verify your program by calculating the fourth roots of this 
 test data: 81, 16, 1, and 0. When you’re finished, use your program to determine the fourth roots of 
 42, 121, 256, 587, 1240, and 16,256。
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int data; //input data
    cin >> data;
    cout << pow(data, 1.0 / 4) << endl;
    return 0;
}