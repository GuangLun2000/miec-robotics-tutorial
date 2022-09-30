
#include <iostream>

using namespace std;

int main() {
    int num[100], len;
    cout << "please input the length of the sequence" << endl;
    cin >> len;
    cout << "please input the sequence" << endl;
    int i = 0, temp;
    while (i < len) {
        cin >> num[i];
        i++;
    }
    int *p = num;
    // bubble sort
    for (int i = len - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (*(p + j) > *(p + j + 1)) {
                temp = *(p + j);
                *(p + j) = *(p + j + 1);
                *(p + j + 1) = temp;
            }
        }
    }
    i = 0;
    cout << "the sorted sequence:" << endl;
    while (i < len) {
        cout << num[i] << " ";
        i++;
    }
    return 0;
}

