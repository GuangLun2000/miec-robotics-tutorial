#include <iostream>
#include <cstring>
using namespace std;

/*
Define the Person class. The Teacher class and the Cadre class are derived from Person.
1. The data members included in the Person class include name, age, and gender.
2. Include data members in the Teacher class: position.
3. Include data members in the Cadre class: work, salary.
Define member functions in the class body. And each class has a display information function (Show).
*/

class Person
{
protected:
    char name[10];
    int age;
    char sex[10];

public:
    Person(char pname[] = "", int page = 0, char psex[] = "")
    {
        strcpy(name, pname);
        age = page;
        strcpy(sex, psex);
    }
    
    void show() const{
        cout << "--------------------------------------------------" << endl;      
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Sex: " << sex << endl;
    }

};

class Teacher : public Person
{
    protected:
    char position[10];

    public:
    Teacher(char tname[]="",int tage=0,char tsex[]="",char *pposition=""):Person(tname,tage,tsex)
    {
        strcpy(position,pposition);
    }

    void show() const{
        cout << "--------------------------------------------------" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Sex: " << sex << endl;
        cout << "Position: " << position << endl;
    }

};

class Cadre : public Person
{
    protected:
    char work[10];
    int salary;

    public:
    Cadre(char cname[]="",int cage=0,char csex[]="",char *cwork="",int csalary=0):Person(cname,cage,csex)
    {
        strcpy(work,cwork);
        salary = csalary;
    }

    void show() const{
        cout << "--------------------------------------------------" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Sex: " << sex << endl;
        cout << "Work: " << work << endl;
        cout << "Salary: " << salary << endl;
    }

};

int main()
{
    Teacher teacher1("Lance",20,"Male","RA");
    Cadre cadre1("King",21,"Female","Lecture",5000);
    teacher1.show();
    cadre1.show();


    return 0;
}

// Experiment 14 - 3
// This code is created by Hanlin Cai
// MU  number : 20122161
// FZU number : 832002117