#include<iostream>
#include <cstring>
#include<algorithm>

using namespace std;

class Employee {
private:
    //编号、工资率、最大工作时长
    int id;
    double payRate;
    double maxWorkHours;
public:

    //有三个普通成员函数SetData()，updatadata()和Disp()，分别用于给数据成员赋值，更新和输出。
    void setdata(int i, double p, double m) {
        id = i;
        payRate = p;
        maxWorkHours = m;
    }

    Employee updatadata(Employee employee, int i, double p, double m) {
        employee.id = i;
        employee.payRate = p;
        employee.maxWorkHours = m;
        return employee;
    }

    void display() {
        cout << "id:" << id << "\tpay rate:" << payRate << "\tmax work hours:" << maxWorkHours << endl;
    }


};

int main() {

    cout << "请输入三个新员工信息" << endl;
    Employee employee[3];
    for (int i = 0; i < 3; i++) {
        int id;
        double payRate, maxWorkHours;
        cin >> id >> payRate >> maxWorkHours;
        employee[i].setdata(id, payRate, maxWorkHours);
    }
    employee[1].display();
    for (int j = 0; j < 3; j++) {
        employee[j].display();
    }

}
