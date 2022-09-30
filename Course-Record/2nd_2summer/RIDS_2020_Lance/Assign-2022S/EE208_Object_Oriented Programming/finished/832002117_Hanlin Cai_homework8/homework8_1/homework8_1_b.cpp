#include <fstream>
#include <iostream>
#include <string>
using namespace std;


int main()
{
	ifstream in( "number.txt" , ios::in);

	if (!in.is_open())
    {
        cout <<  "Error: opening file fail"  << endl;
        exit (1);
    }

    double num[18];
    double sum[3];
	int i = 0;
    int j = 0;
    double flag = 0.0;


    while (!in.eof() && i < 18)
    {
        in >> num[i];

        int temp = num[0]; // temp = 5
        if (0 < i && i <= temp) // 0 < i < 5
        {
            flag += num[i];
            if (i == 5)
            {
                sum[j] = flag/5;
                j++; // then,j=1
                // cout << j <<endl;
                flag=0;
                
            }
        }

        if (6<i && i<11)
        {
            flag += num[i];
            if (i==10)
            {
                sum[j] = (flag)/4;
                j++; //then,j=2
                flag=0;
            }
            
        }

        if (10<i)
        {
            flag += num[i];
            if (i==17)
            {
                sum[j] = (flag)/6;
            }
            
        }
        // if (i == count)
        // {
        //     temp = num[count];
        //     int temp1 = count + temp;
        //     if (i <= temp1 )
        //     {
        //         flag += num[i];
        //         if (i == temp1)
        //         {
        //             sum[j] = flag/temp;
        //             count = i+1;
        //             j++;
        //         }
        //     }
        // }

        i++;
    }
    
    for (int k = 0; k < 3; k++) {
        cout  << sum[k] << endl;
	}

	// Close the open file
	in.close();
	return 0;

}
//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117