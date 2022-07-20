#include<iostream>
using namespace std;

int main(){
    double x = 0;
    double y = 0;
    double flag = 0;
    cout << "Please input the two numbers and the Select Code :";
    cin >> x >> y >> flag;
    if(flag == 1){
        cout << "Output x+y = " << x+y << endl;
    }
    if(flag == 2){
        cout << "Output x*y = " << x*y << endl;
    }
    if(flag == 3){
        if (y != 0)
        {
            cout << "Output x/y = " << x/y << endl;
        }else{
            cout << "y can not be 0!" << endl;
        }
    }
}