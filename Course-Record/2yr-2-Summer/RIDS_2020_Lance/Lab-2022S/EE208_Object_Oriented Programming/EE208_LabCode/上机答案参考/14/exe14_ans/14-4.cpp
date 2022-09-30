#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

//person类定义
class Person {
    //数据成员
protected:
    char name[10];
    int age;
    char sex[10];
public:
    //构造函数
    Person(char pname[] = "", int page = 0, char psex[] = "") {
        strcpy(name, pname);
        age = page;
        strcpy(sex, psex);
    }

    //show函数
    void show() const {
        cout << "姓名:" << name << endl;
        cout << "年龄:" << age << endl;
        cout << "性别:" << sex << endl;

    }
};

//定义Teacher类
class Teacher : public Person {
    //新增数据成员
protected:
    char title[10];

public:
    //构造函数
    Teacher(char tname[] = "", int tage = 0, char tsex[] = "", char *ttitle = "") : Person(tname, tage, tsex) {
        strcpy(title, ttitle);
    }

    //新增show函数
    void show() const {
        cout << "姓名:" << name << endl;
        cout << "年龄:" << age << endl;
        cout << "性别:" << sex << endl;
        cout << "职称:" << title << endl;
    }
};

//定义Cadre类
class Cadre : public Person {
    //新增数据成员
protected:
    char post[20];
    int wages;
public:
    //构造函数
    Cadre(char cname[] = "", int cage = 0, char csex[] = "", char *cpost = "", int cwages = 0) : Person(cname, cage,
                                                                                                        csex) {
        strcpy(post, cpost);
        wages = cwages;
    }

    //新增show函数
    void show() const {
        cout << "姓名:" << name << endl;
        cout << "年龄:" << age << endl;
        cout << "性别:" << sex << endl;
        cout << "职务:" << post << endl;
        cout << "工资:" << wages << endl;
    }
};

int main() {
    Teacher t("王五", 35, "男", "副教授");
    Cadre c("张姗", 27, "女", "计算机教师", 5000);
    t.show();
    c.show();
    return 0;
}

