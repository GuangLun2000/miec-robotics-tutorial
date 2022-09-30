#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct name
{
    string firstName;
    string lastName;
}name[5];

int main(){
    string firstName,lastName;

    // for (int i = 0; i < 5; i++)
    // {
    //     cout << "Please enter your name : " ;
    //     cin >> firstName >> lastName;
    //     cout << lastName << " " << firstName << " " << endl;
    // }


    for (int i = 0; i < 5; i++){
        cout << "Please enter your name : " ;
        cin >> name[i].firstName >> name[i].lastName;
        cout << "The output is : " << name[i].lastName << " " << name[i].firstName << " " << endl;
    }

    cout << "***************OVER*****************" << endl;
    return 0;

}
//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117