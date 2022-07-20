#include <iostream>
#include <cstring>
using namespace std;

/*
There is a student class, including the student's name, grades, and requirements:
compare() to compare the grade of two students
main() function to store the input student data
*/

class Stud{
    private:
    char stduent_name[10];
    double stduent_score;


    public:
    void setData(char* theName, double theScore);
    void compare(Stud *arr,int number); // find maximum
    void findMin(Stud *arr,int number); // find minimum
    void display(int i);

};

void Stud::setData(char* theName, double theScore) {
    strcpy(stduent_name,theName);
    stduent_score = theScore;
}

void Stud::display(int i) {
    cout << "--------------------------------" << endl;
    cout << i << " Student Name: " << stduent_name << endl;
    cout << i << " Student Score: " << stduent_score << endl;
}

void Stud::compare(Stud *arr,int number) {
    int max = arr[0].stduent_score;
    string temp = arr[0].stduent_name;
    for (int i = 0; i < number; i++)
	{
		if (arr[i].stduent_score > max)
		{
			max = arr[i].stduent_score;
            temp = arr[i].stduent_name;
		}
	}
    cout << "The max score is: " << max << endl;
	cout << "The max student is: " << temp << endl;
}

void Stud::findMin(Stud *arr,int number) {
    int min = arr[0].stduent_score;
    string temp2 = arr[0].stduent_name;
    for (int i = 0; i < number; i++)
	{
		if (arr[i].stduent_score < min)
		{
			min = arr[i].stduent_score;
            temp2 = arr[i].stduent_name;
		}
	}
    cout << "The max score is: " << min << endl;
	cout << "The max student is: " << temp2 << endl;
}

int main(){

    int number;
    cout << "Please enter the number of student: ";
    cin >> number;
    Stud* stud = new Stud[number];
    cout << "Please enter the Name, Score of the student: \n" ;
    
    for (int i = 0; i < number; i++)
    {
        char theName[10];
        double theScore;
        cin  >> theName >> theScore;
        stud[i].setData(theName,theScore);
    }

    // for(int i = 0; i < number; i++){
    //     stud[i].display(i);
    // }

    cout << "---------------------------------------------------" << endl;
    stud[number].compare(stud,number);
    stud[number].findMin(stud,number);

    return 0;
}

// Experiment 14 - 1
// This code is created by Hanlin Cai
// MU  number : 20122161
// FZU number : 832002117