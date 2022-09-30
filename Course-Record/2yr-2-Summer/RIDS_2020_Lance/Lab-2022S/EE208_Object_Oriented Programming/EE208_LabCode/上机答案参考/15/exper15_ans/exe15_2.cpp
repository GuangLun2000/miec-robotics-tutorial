#include <bits/stdc++.h>

using namespace std;

struct Fraction {
    int numerator;
    int denominator;
};

double multiply(Fraction fractionOne, Fraction fractionTwo) {
    double ret = ((double) fractionOne.numerator / fractionOne.denominator) *
                 ((double) fractionTwo.numerator / fractionTwo.denominator);
    return ret;
}

int main() {

    Fraction A, B;
    char c;
    cout << "input the first fraction:" << endl;
    cin >> A.numerator >> c >> A.denominator;
    cout << "input the second fraction:" << endl;
    cin >> B.numerator >> c >> B.denominator;
    cout << multiply(A, B) << endl;

}
