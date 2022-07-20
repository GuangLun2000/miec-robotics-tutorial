#include <iostream>
#include <math.h>
using namespace std;

/*
Construct a class named Student consisting of
an integer student ID number and a doubleprecision grade point average.
*/

class Student
{
protected:
    int ID;
    double GPA;

public:
    void constructor()
    {
        ID = 111111;
        GPA = 0.0;
    }
    void showData()
    {
        cout << "Student ID: " << ID << endl;
        cout << "Student GPA: " << GPA << endl;
    }
};

int main()
{
    Student student1;
    Student student2;
    student1.constructor();
    student1.showData();
    student2.constructor();
    student2.showData();

    return 0;
}
// Experiment 13 - 3
// This code is created by Hanlin Cai
// MU  number : 20122161
// FZU number : 832002117