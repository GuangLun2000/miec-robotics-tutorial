#include<iostream>
#include<string>
using namespace std;

/*
char *strcat (char *strDest, const char *strSrc)
Hello
World
HelloWorld
*/

char *mystrcat(char *strDest, const char *strSrc) {
	int i,j;
	int len = strlen(strDest);
	i = len;
    
	for(j=0 ; strSrc[j]!=0; j++)  
    {
        strDest[i] = strSrc[j];
        i++;
	}

	return strDest;
}

int main() {
    cout << "Please enter the 1st string :";
	char a[5]="";
    for(int i=0 ; i<5 ; i++){
        cin >> a[i];
    }

    cout << "Please enter the 2nd string :";    
	char b[5]="";
    for(int i=0 ; i<5 ; i++){
        cin >> b[i];
    }
	
	string result = mystrcat(a,b);
    cout << "Result is: " << result << endl;

	return 0;
}
// Homework 11 - 3
// This code is created by Hanlin Cai
// MU  number : 20122161
// FZU number : 832002117