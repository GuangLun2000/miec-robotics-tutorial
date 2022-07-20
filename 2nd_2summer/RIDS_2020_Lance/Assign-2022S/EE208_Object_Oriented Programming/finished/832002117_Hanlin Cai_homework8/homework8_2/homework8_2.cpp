#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct Student {
    string Student_name;
    int Student_grade1;
    int Student_grade2;
    int Student_homework;
    int Student_final;
    double Student_score;
    string Student_level;
}info[20];

int main()
{

	int i = 0;
    while (i < 20)
    {
        cin >> info[i].Student_name >> info[i].Student_grade1 >> info[i].Student_grade2 >> info[i].Student_homework >> info[i].Student_final;
        info[i].Student_score = 0.2*info[i].Student_grade1 + 0.2*info[i].Student_grade2 + 0.35*info[i].Student_homework + 0.25*info[i].Student_final;
        
        if (info[i].Student_score < 60)
        {
            info[i].Student_level = 'F';
        }
        if (info[i].Student_score >= 60 && info[i].Student_score < 70)
        {
            info[i].Student_level = 'D';
        }
        if (info[i].Student_score >= 70 && info[i].Student_score < 80)
        {
            info[i].Student_level = 'C';
        }
        if (info[i].Student_score >= 80 && info[i].Student_score < 90)
        {
            info[i].Student_level = 'B';
        }
        if (info[i].Student_score >= 90 && info[i].Student_score <= 100)
        {
            info[i].Student_level = 'A';
        }
        if (info[i].Student_score > 100 && info[i].Student_score<0){
            cout << "null!" << endl;
        }
        
        i++;
    }
    

    for (int i = 0; i < 20; i++) {
        cout  << info[i].Student_name << " : " << info[i].Student_score << "--" << info[i].Student_level << endl;
	}

	fstream outfile;
	outfile.open("try.txt", ios::out | ios::app);
    for (int i = 0; i < 20; i++)
    {
        outfile << info[i].Student_name << " " << info[i].Student_score << " " << info[i].Student_level << endl;
    }
    
	outfile.close();  //调用close（）函数关闭文件

	return 0;
}
//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117