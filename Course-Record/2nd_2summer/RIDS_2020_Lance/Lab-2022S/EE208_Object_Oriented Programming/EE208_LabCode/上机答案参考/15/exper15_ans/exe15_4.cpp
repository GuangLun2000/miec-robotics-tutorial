#include <bits/stdc++.h>

using namespace std;

const int maxn = 100005;

map<string, bool> ma;

struct Node {
    string s;
    int x;

    bool operator<(Node &obj) {
        return s < obj.s;
    }
} node[maxn];

vector<Node> v;

int n, m;

int main() {

    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        ma[s] = 1;
    }

    cin >> m;
    int sum = 0;
    for (int i = 0; i < m; i++) {
        cin >> node[i].s >> node[i].x;
        sum += node[i].x;
    }

    sum /= m;

    for (int i = 0; i < m; i++) {
        if (ma[node[i].s] == false && node[i].x > sum) {
            v.push_back(node[i]);
        }
    }

    if (v.size() == 0) {
        cout << "Bing Mei You" << endl;
        return 0;
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        cout << v[i].s << endl;
    }
}
