#include <iostream>
#include <string>
using namespace std;

// Count the number of occurrences of a substring in a string.
// Statement : substr- points to a substring, STR - points to a long string
int frequency(char * substr, char * str)
{
    int n=0,s1=0,s2=0;
    char *p=str;
    
    s1 = strlen(str);
    s2 = strlen(substr);

    while(s1 >= s2)
    {
        str=strstr(str,substr);
        if(str!=0){
            n++;
            str+=s2; // Back from where the substring was found
        }
        else break; // Jump out
        s1=strlen(str);
    }
    return n;
}

int main()
{
    char sub[100],str[100];
    cout << "Please enter the str : ";
    cin.getline(str,100);
    cout << "Please enter the substr : ";
    cin.getline(sub,100);
    int n = frequency(sub,str);  // count the number of times a substring occurs in a long string
    cout << "The frequency of this substr is : " << n << endl;
    return 0;
}
//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117