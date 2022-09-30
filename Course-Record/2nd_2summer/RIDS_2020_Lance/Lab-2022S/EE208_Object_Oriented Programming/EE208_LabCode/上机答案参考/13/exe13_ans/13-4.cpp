#include<iostream>

using namespace std;

class Student {
private:
    int ID;
    double grade;
public:
    Student(int ID = 111111, double grade = 0.0) {
        this->ID = ID;
        this->grade = grade;
    }

    void accessor() {
        cout << "ID:" << this->ID << endl;
        cout << "grade:" << this->grade << endl;
    }
};

int main() {
    Student stu1;
    Student stu2(12345, 90.0);

    stu1.accessor();
    stu2.accessor();
} 
