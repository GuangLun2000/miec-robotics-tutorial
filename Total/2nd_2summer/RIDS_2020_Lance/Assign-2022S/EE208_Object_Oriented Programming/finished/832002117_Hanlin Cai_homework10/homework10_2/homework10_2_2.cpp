#include <iostream>
using namespace std;

/*
Modify the display function written in Exercise 4a to alter the address in message. 
Also, use the expression *strng rather than *(strng + i) to retrieve the correct element.
*/

void solution(char* strng) {
    // int length = strlen(strng);
    // for (int i = 0; i < length; i++) {
        // printf("%c",  *(strng + i) );
    // }
    printf("%s",strng);
}

int main() {
    char message[50] = "Vacation is near";
    solution(message);

    return 0;
}
// Homework 10 - 2 - 1
// This code is created by Hanlin Cai
// MU  number : 20122161
// FZU number : 832002117