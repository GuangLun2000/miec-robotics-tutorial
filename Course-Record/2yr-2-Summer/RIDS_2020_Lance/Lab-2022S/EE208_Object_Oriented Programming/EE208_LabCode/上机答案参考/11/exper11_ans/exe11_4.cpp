
#include<iostream>

using namespace std;

int main() {
    double *array[10], d;
    double total = 0, *sum = &total;
    cout << "please input 10 double-precision numbers:" << endl;
    int i = 0;
    while (i < 10) {
        cin >> d;
        // open space for double
        *(array + i) = new double(d);
        total += d;
        i++;
    }
    i = 0;
    while (i < 10) {
        cout << "array[" << i << "]: " << **(array + i) << endl;
        i++;
    }
    cout << "sum of the array is: " << *sum << endl;
    return 0;

}
