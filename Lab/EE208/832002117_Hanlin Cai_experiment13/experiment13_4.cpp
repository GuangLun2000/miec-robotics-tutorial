#include <iostream>
#include <vector>
using namespace std;

/*
Construct a class definition to represent an employee of a company.
Each employee is defined by an integer ID number,
a double-precision pay rate, and the maximum number of hours the employee should work each week.
*/

class Employee
{
protected:
    int employeeID;
    int maxWorkHours;
    double payRate;

public:
    Employee(int = 0, int = 0, double = 1.00);

    void setID(int id);
    void setmaxWorkHours(int h);
    void setPayRate(double rate);
    void showData();
};

Employee::Employee(int id, int h, double rate)
{
    employeeID = id;
    maxWorkHours = h;
    payRate = rate;
}

void Employee::setID(int id)
{
    employeeID = id;
}

void Employee::setmaxWorkHours(int h)
{
    maxWorkHours = h;
}

void Employee::setPayRate(double rate)
{
    payRate = rate;
}

void Employee::showData()
{
    cout << "Employee ID: " << employeeID << ", max working hours: "
         << maxWorkHours << ", pay rate: " << payRate << endl;
}

int main()
{
    vector<Employee> emp(3);
    int emplength = 0;

    while (true)
    {
        cout << "1. Add an employee\n"
             << "2. Modify employee data\n"
             << "3. Delete an employee\n"
             << "4. Display the data\n"
             << "5. Exit this menu \n";

        int input;
        cin >> input;

        if (input == 1)
        {
            cout << "Please input 3 emp information : " << endl;
            for (int i = 0; i < emp.size(); i++)
            {
                int tmp;
                double tmpDouble;
                cout << "------------------\n";
                cout << "Input employee ID: ";
                cin >> tmp;
                emp[i].setID(tmp);

                cout << "Input max working hours: ";
                cin >> tmp;
                emp[i].setmaxWorkHours(tmp);

                cout << "Input payRate: ";
                cin >> tmpDouble;
                emp[i].setPayRate(tmpDouble);
            }
        }
        else if (input == 2)
        {
            int ind;
            int tmp;
            double tmpDouble;

            cout << "------------------\n";
            cout << "Input the index of the employee: ";
            cin >> ind;

            if (ind < 0 || ind >= emplength)
            {
                cout << "Invalid index input!";
                exit(1);
            }

            cout << "Input new employee ID: ";
            cin >> tmp;
            emp[ind].setID(tmp);

            cout << "Input new max working hours: ";
            cin >> tmp;
            emp[ind].setmaxWorkHours(tmp);

            cout << "Input new payRate: ";
            cin >> tmpDouble;
            emp[ind].setPayRate(tmpDouble);
        }
        else if (input == 3)
        {
            int ind;
            cout << "------------------\n";
            cout << "Input the storing index of the employee: ";
            cin >> ind;

            emp.erase(emp.begin() + ind);
            emp.resize(--emplength);
        }
        else if (input == 4)
        {
            for (int i = 0; i < 3; i++)
            {
                emp[i].showData();
            }
        }
        else
        {
            cout << "bye-bye\n";
            cout << "Have a brilliant day!" << endl;
            break;
        };
    }

    return 0;
}
// Experiment 13 - 4
// This code is created by Hanlin Cai
// MU  number : 20122161
// FZU number : 832002117