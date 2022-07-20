#include <iostream>
using namespace std;

struct Point {
    double x, y;
};

Point midpoint(Point A, Point B) {
    Point n;
    n.x = (A.x + B.x)/2;
    n.y = (A.y + B.y)/2;
    return n;
}

int main()
{
    struct Point P,Q,Z;
    struct Point P1,Q1,Z1;
    cout << "Please input the coordinates of the three points: ";
    cin >> P.x >> P.y >> Q.x >> Q.y >> Z.x >> Z.y;
    P1 = midpoint(P,Q);
    Q1 = midpoint(Q,Z);
    Z1 = midpoint(Z,P);

    cout << "Midpoint triangle verts: " << endl;
    cout << "midPoint 1: (" << P1.x << "," << P1.y << ")" << endl;
    cout << "midPoint 2: (" << Q1.x << "," << Q1.y << ")" << endl;
    cout << "midPoint 3: (" << Z1.x << "," << Z1.y << ")" << endl;

    return 0;
}

// Experiment 15 - 1
// This code is created by Hanlin Cai
// MU  number : 20122161
// FZU number : 832002117