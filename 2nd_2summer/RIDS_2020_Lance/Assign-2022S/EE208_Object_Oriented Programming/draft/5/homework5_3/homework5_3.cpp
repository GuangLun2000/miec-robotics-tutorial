#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main(){
    char buf[2];
    cout << "Please enter two characters : ";
    cin  >> buf;
    // cout << buf[1];
    char char1 = buf[0];
    char char2 = buf[1];
    while (int(char1) >= int(char2))
    {
        cout << "Input error, please check and reinput the 2nd char : ";
        cin >> buf[1];
        char2 = buf[1];
    }
    cout << endl;

    // int length = int(buf[1])-int(buf[0]);
    // int intArray[length];
    char c;
    int temp;
    for(c=buf[0]; c<=buf[1]; c++){
        //decimal
        temp = int(c);

        //octal
        string temp1;
        stringstream sc;
        sc << std::oct <<temp;
        sc >> temp1; 

        //hexadecimal
        string temp2;
        stringstream ss;
        ss << std::hex <<temp;
        ss >> temp2 ;
        // transform(temp2.begin(), out.end(), out.begin(), ::toupper);

        //cout 3 types
        cout << c << " ---- Decimal : " << temp;
        cout << " ---- Octal : " << temp1;
        cout << " ---- Hexadecimal : " << temp2 <<endl;
    }

}

//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117