#include <iostream>

using namespace std;

struct point {
    double x, y;
};


point midpoint(point a, point b) {
    point m;
    m.x = (a.x + b.x) / 2;
    m.y = (a.y + b.y) / 2;
    return m;
}

point readpoint() {
    point p;
    char c;
    cin >> c >> p.x >> c >> p.y >> c;
    return p;
}

void writepoint(point p) {
    cout << '(' << p.x << ',' << p.y << ')';
}

int main() {
    // Read in triangle vertices
    cout << "Enter triangle vertices: ";
    point a = readpoint(),
            b = readpoint(),
            c = readpoint();

    // Compute midpoints
    point e = midpoint(a, b),
            f = midpoint(b, c),
            g = midpoint(c, a);

    // Write out midpoint triangel vertices
    cout << "Midpoint triangle verts: ";
    writepoint(e);
    writepoint(f);
    writepoint(g);
    cout << endl;

    return 0;
}


