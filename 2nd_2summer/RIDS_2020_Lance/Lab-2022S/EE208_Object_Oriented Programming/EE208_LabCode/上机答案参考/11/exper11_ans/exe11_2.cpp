
#include <iostream>

using namespace std;

char *mystrcat(char *a, const char *b) {
    char *c = a;
    while (*c != '\0') {
        c++;
    }
    while (*b != '\0') {
        *c++ = *b++;
    }
    *c = *b;
    return a;
}

int main() {

    char str1[100];
    char str2[100];
    cout << "input the destination string" << endl;
    gets(str1);
    cout << "input the source string" << endl;
    gets(str2);
    cout << "Result is:" << mystrcat(str1, str2) << endl;
    return 0;
}

