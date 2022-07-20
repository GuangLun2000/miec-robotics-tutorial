#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(){

    string str1;
    cout << "Please input the txt :";
    getline(std::cin, str1); 
    // use getline rather than cin, so that the input will not out of index.
    
    int count = 0;

    for (int i = 0; i < str1.length(); i++)
    {
        if (str1[i] != '.' )
        {
            count++;
        } else {
            break;
        }

        if (str1[i] == ' ')
        {
            count++;
        }
        
    }

    cout << count << endl;
    
    // string str2 = str1;
    string str2 = str1.substr(0,count);
    
    int length;
    length =count;

    str2[0] = toupper(str2[0]);
    for (int j = 1 ; j <length ; j++){
        if (str2[j] == ' ')
        {
            continue;
        }
        str2[j] = tolower(str2[j]);
    }
    
    cout << "The return txt is : " << str2 << endl;

    return 0;
}

//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117