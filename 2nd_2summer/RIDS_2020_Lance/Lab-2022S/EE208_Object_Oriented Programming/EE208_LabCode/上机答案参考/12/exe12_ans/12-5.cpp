#include<iostream>
#include <cstring>
#include<algorithm>

using namespace std;

class Stud {
public:
    //静态变量存放总分和人数
    static double sum_score;
    static int num;

    //有两个普通成员函数SetData()和Disp()，分别用于给数据成员赋值和输出数据成员的值。
    void setdata(int i, char *n, double s) {
        id = i;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        score = s;
        sum_score += score;
        num += 1;
    }

    void display() {
        cout << "id:" << id << "\tname:" << name << "\tscore:" << score << endl;
    }

    //静态成员函数Avg()，它用于计算平均分
    static double avg() { return sum_score / num; }

private:
    //学号、姓名、成绩
    int id;
    char *name;
    double score;
};

//初始化静态成员变量
double Stud::sum_score = 0;
int Stud::num = 0;

int main() {
    int ids[] = {1, 2, 3, 4, 5};
    char *stunames[] = {"Rose", "Mike", "Eve", "Micheal", "Jack"};
    double scores[] = {95, 84, 88, 64, 100};
    Stud stud[5];

    for (int i = 0; i < 5; i++)
        stud[i].setdata(ids[i], stunames[i], scores[i]);

    for (int i = 0; i < 5; i++)
        stud[i].display();

    cout << "\tsum_score:" << stud[0].sum_score << "\tavg:" << stud[0].avg() << endl;
}


