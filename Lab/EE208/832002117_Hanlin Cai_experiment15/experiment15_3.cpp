#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


struct stud
{
    string account;
    int grade;
};

// bool cmp(stud a,stud b){
//     return a.grade > b.grade;
// }

int cmp(const void *a, const void *b){
    struct stud aa = *(struct stud *)a;
    struct stud bb = *(struct stud *)b;
    return aa.grade < bb.grade;
}


int main()
{
    int N,G,K;
    cout << "Please enter the N,G,K: ";
    cin >> N >> G >> K;
    stud arr[N];
    cout << "Please enter the student's account number and overall grade: " << endl;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i].account >> arr[i].grade;
    }
    
    // cout << arr[0].account << endl;

    int values = 0;
    for (int i = 0; i < N; i++)
    {
        if(arr[i].grade>=G){
            values += 50;
        }
        else if(arr[i].grade<G && arr[i].grade>=60){
            values += 20;
        }
        else{
            continue;
        }
    }
    cout << "----------------------------------------------------------------" << endl;
    cout << "values = " << values << endl;
    
    // sort(arr.begin(),arr.end(),compare);
    qsort(arr,N,sizeof(arr[0]),cmp);

    for(int i=0; i < K;){
        if (arr[i].grade != arr[i+1].grade)
        {
            cout << (i+1) << " " << arr[i].account << " " << arr[i].grade << endl;
            i++;
        }else{
            cout << (i+1) << " " << arr[i].account << " " << arr[i].grade << endl;
            cout << (i+1) << " " << arr[i+1].account << " " << arr[i+1].grade << endl;
            i+=2;
        }
    }

    return 0;
}

// Experiment 15 - 3
// This code is created by Hanlin Cai
// MU  number : 20122161
// FZU number : 832002117