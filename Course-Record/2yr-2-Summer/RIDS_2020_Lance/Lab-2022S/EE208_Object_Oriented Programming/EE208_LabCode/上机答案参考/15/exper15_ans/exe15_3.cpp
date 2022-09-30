#include <bits/stdc++.h>

using namespace std;

const int maxn = 10005;

int n, g, k;

struct Stu {
    int rank;
    string username;
    int grade;
} stu[10005];

bool cmp(Stu a, Stu b) {
    if (a.grade == b.grade) {
        return a.username < b.username;
    }
    return a.grade > b.grade;
}

int money;

int main() {

    cin >> n >> g >> k;

    for (int i = 0; i < n; i++) {
        cin >> stu[i].username >> stu[i].grade;
        if (stu[i].grade >= 60 && stu[i].grade < g) {
            money += 20;
        }
        if (stu[i].grade >= g && stu[i].grade <= 100) {
            money += 50;
        }
    }

    sort(stu, stu + n, cmp);

    stu[0].rank = 1;
    for (int i = 1; i < n; i++) {
        if (stu[i].grade == stu[i - 1].grade) {
            stu[i].rank = stu[i - 1].rank;
        } else {
            stu[i].rank = i + 1;
        }
    }

    cout << money << endl;
    for (int i = 0; i < n; i++) {
        if (stu[i].rank > k) break;
        cout << stu[i].rank << " " << stu[i].username << " " << stu[i].grade << endl;
    }
}
