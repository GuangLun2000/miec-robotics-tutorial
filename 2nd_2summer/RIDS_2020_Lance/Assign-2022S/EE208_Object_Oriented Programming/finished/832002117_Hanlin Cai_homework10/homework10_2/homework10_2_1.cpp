#include <iostream>
using namespace std;

/*
Write a program that has a declaration in main() 
to store the string Vacation is near in an array named message. 
Include a function call that accepts message in an argument named strng 
and then displays the contents of message by using the pointer notation *(strng + i).
Actually, I don't understand what it means...
*/

void solution(char* strng) {
    int length = strlen(strng);
    for (int i = 0; i < length; i++) {
        printf("%c",  *(strng + i) );
    }
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