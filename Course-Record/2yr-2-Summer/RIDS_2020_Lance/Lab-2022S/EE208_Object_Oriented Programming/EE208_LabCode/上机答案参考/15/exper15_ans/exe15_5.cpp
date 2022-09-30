#include <bits/stdc++.h>

using namespace std;

const int maxn = 105;

set<int> s;

struct Node {
    string name;
    int sum;
    int k;

    bool operator<(Node obj) const {
        if (sum == obj.sum) {
            return k < obj.k;
        }
        return sum > obj.sum;
    }
} node[maxn];

int n;

int main() {

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> node[i].name;
        cin >> node[i].k;
        s.clear();
        for (int j = 0; j < node[i].k; j++) {
            int x;
            cin >> x;
            s.insert(x);
        }
        node[i].sum = s.size();
    }

    sort(node, node + n);

    if (n >= 3) {
        cout << node[0].name << " " << node[1].name << " " << node[2].name;
    }
    if (n == 2) {
        cout << node[0].name << " " << node[1].name << " -" << endl;
    }
    if (n == 1) {
        cout << node[0].name << " - -" << endl;
    }
}
