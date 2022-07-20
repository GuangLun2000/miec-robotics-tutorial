#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int main(){
    int temp,flag,count=1;
    srand(time(0));
    flag = rand()%100;

    do{
        cout<<"Please input your lucky number : ";
        cin>>temp;
        if(temp==flag){
            cout<<"*****Lucky!Got it!*****"<<endl;
            break;
        }
        else if(temp>flag)
            cout<<"Too high, try again!"<<endl;
        else
            cout<<"Too low, try again!"<<endl;
        count++;
    }while(count<8);
    if(count==8){
        cout << "--------------------------------" << endl;
        cout << "The opportunity is gone";
    }

    return 0;
}
//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117