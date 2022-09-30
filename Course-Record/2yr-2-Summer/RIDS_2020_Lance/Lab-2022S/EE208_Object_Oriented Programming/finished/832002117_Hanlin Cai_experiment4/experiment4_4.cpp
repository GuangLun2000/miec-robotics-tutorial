#include<iostream>
using namespace std;

int main(){
    double y;
    cout << "------------------------------------------------" << endl;
    for(double x=1.0;x<6;x++){
        double z=2.0;
        for(;z<7;z++){
            if (x==z)
            {
                cout<<"Function Undefined"<<endl;
                continue;
            }
            y = (x*z)/(x-z);
            cout << y << endl;
        }
    }
    cout << "------------------------------------------------" << endl;
    return 0;
}
//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117