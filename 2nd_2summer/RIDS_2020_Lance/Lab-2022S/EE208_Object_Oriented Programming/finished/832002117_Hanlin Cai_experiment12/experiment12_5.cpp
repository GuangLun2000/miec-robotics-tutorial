#include <iostream>
#include <cstring>
using namespace std;

/*
Write a program, input N student data, 
including student ID, name, grades, output these student data, 
and calculate the average score.
*/

class Stud {

    private:
    char stduent_ID[10];
    char stduent_name[10];
    double stduent_score;
    static double sum;
    static int num;

    public:
    void setData(char* theID, char* theName, double theScore);
    void display(int i);
    static double avg();
};

double Stud::sum = 0.0;
int Stud::num = 0;

void Stud::setData(char* theID, char* theName, double theScore) {
    strcpy(stduent_ID,theID);
    strcpy(stduent_name,theName);
    stduent_score = theScore;
    sum += theScore;
    num++;
}

void Stud::display(int i) {
    cout << "--------------------------------" << endl;
    cout << i << " Student ID: " << stduent_ID << endl;
    cout << i << " Student Name: " << stduent_name << endl;
    cout << i << " Student Score: " << stduent_score << endl;
}

double Stud::avg() {
    return sum/num;
}

int main() {

    int number;
    cout << "Please enter the number of student: ";
    cin >> number;
    Stud* stud = new Stud[number];
    cout << "Please enter the ID, Name, and Score of the student: " ;
    
    for (int i = 0; i < number; i++)
    {
        char theID[10];
        char theName[10];
        double theScore;
        cin >> theID >> theName >> theScore;
        stud[i].setData(theID,theName,theScore);
    }
    
    for(int i = 0; i < number; i++){
        stud[i].display(i);
    }
    
    double avgScore = Stud::avg();
    cout << "--------------------------------FINAL" << endl;
    cout << "The average score = " << avgScore << endl;

    return 0;
}
// Experiment 12 - 5
// This code is created by Hanlin Cai
// MU  number : 20122161
// FZU number : 832002117