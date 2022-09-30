
#include<iostream>

using namespace std;

int main() {
    int p[10];
    int max, min;
    cout << "please input 10 numbers(int)" << endl;
    int i = 0;
    while (i < 10) {
        cin >> *(p + i);
        if (i == 0)
            max = min = *(p + i);
        if (*(p + i) > max)
            max = *(p + i);
        if (*(p + i) < min)
            min = *(p + i);
        i++;
    }
    cout << "The difference between the maximum and the minimum is " << max - min << endl;
    return 0;
}

