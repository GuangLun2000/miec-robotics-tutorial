#include<iostream>
#include <cstring>

using namespace std;

class Student {
public:
    //友元函数Compare()，比较两个学生成绩的高低
    friend int compare(Student *a, Student *b);

    //用于设置学生信息
    void set(char *n, double s) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        score = s;
    }

    //用于获取学生信息
    double getScore() { return score; }

    char *getName() { return name; }

    //显示学生信息
    void display() {
        cout << "Name:" << name << "\tScore:" << score << endl;
    }

    //析构函数
    ~Student() {
        delete name;
    }

private:
    char *name;
    double score;
};


//1表示大于，0表示等于，-1表示小于
int compare(Student *a, Student *b) {
    if (a->getScore() > b->getScore())
        return 1;
    else if (a->getScore() == b->getScore())
        return 0;
    else
        return -1;
}

int main() {
    Student *min, *max;
    Student studs[5];
    char *stunames[] = {"Rose", "Mike", "Eve", "Micheal", "Jack"};
    double scores[] = {95, 84, 88, 64, 100};

    for (int i = 0; i < 5; i++) {
        studs[i].set(stunames[i], scores[i]);
        studs[i].display();
    }

    min = &studs[0];
    max = &studs[0];
    for (int i = 1; i < 5; i++) {
        Student *j = &studs[i];
        if (compare(min, j) == 1)
            min = j;
        if (compare(max, j) == -1)
            max = j;
    }
    cout << "The worst student : " << min->getName() << endl;
    cout << "The best student : " << max->getName() << endl;


    return 0;
}


