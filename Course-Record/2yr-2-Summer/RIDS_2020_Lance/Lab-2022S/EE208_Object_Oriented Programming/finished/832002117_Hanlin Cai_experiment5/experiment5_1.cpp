#include <iostream>
using namespace std;
#define NO_OF_CHARS 256

int* getCharCountArray(char* str)
{
	int* count = (int*)calloc(sizeof(int), NO_OF_CHARS);
	int i;
	for (i = 0; *(str + i); i++)
		count[*(str + i)]++;
	return count;
}

int firstNonRepeating(char* str)
{
	int* count = getCharCountArray(str);
	int index = -1, i;

	for (i = 0; *(str + i); i++) {
		if (count[*(str + i)] == 1) {
			index = i;
			break;
		}
	}

	// To avoid memory leak
	free(count);
	return index;
}

int main()
{
    int length;
    cout << "Please the length: ";
    cin >> length;
    char str[length];
	// char str[] = "geeksforgeeks";
    cout << "Please the string: ";
    cin >> str;
    int index = firstNonRepeating(str);
    if (index == -1){
        cout << "Either all characters are repeating or string is empty";
    } else {
        cout << "The index of first non-repeating characters is : "<< index << endl;
    }
    // getchar();
    return 0;
}
//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117