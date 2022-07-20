#include <iostream>
using namespace std;

int main()
{
    int count = 0;
    double array[100];
    double sum = 0.0;
    cout << "Please enter the gradeArray : ";

    do
    {
        scanf("%lf", &array[count]);
        count++;

    } while (array[count - 1] >= 0);

    for (int i = 0; i < count - 1; i++)
    {
        sum += array[i];
    }

    double average = sum / (count - 1);
    cout << "Sum = " << sum << endl;
    cout << "Average = " << average << endl;

    cout << "gradeArray: ";
    // for(int i = 0; i < count-1; i++){

    //     if (array[i] < average)
    //     {
    //         cout << "*" << array[i] << " ";
    //     } else {
    //         cout << array[i] << " ";
    //     }

    // }

    for (int i = 0; i < count - 1; i++)
    {
        if (array[i] < 60)
        {
            cout << array[i] << "--F  ";
        }
        else if (array[i] >= 60 && array[i] < 70)
        {
            cout << array[i] << "--D  ";
        }
        else if (array[i] >= 70 && array[i] < 80)
        {
            cout << array[i] << "--C  ";
        }
        else if (array[i] >= 80 && array[i] < 90)
        {
            cout << array[i] << "--B  ";
        }
        else if (array[i] >= 90)
        {
            cout << array[i] << "--A  ";
        }
    }

    // cout << "Please check";

    return 0;
}
// This code is created by Hanlin Cai
// MU  number : 20122161
// FZU number : 832002117