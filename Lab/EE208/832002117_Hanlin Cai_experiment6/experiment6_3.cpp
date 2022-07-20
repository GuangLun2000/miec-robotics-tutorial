#include <iostream>
using namespace std;

int main()
{
    int i = 0,j = 0;
	int length1;
    int length2;
    cin >> length1 >> length2;
    int array1[length1];
    int array2[length2];
    int a[length1][length2];

    for(i = 0; i < length1; i++)
	{
		for(j = 0; j < length2; j++)
		{
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < length1;i++) {
        array1[i] = 1;
    }
    for (int i = 0; i < length2; i++){
        array2[i] = 1;
    }

	// int array1[3] = {1,1,1,1};
	// int array2[4] = {1,1,1,1,1};



    //clear()
	for(i = 0; i < length1; i++)
	{
		for(j = 0; j < length2; j++)
		{
			if(a[i][j] == 0)
			{
				array1[i] = 0;
				array2[j] = 0;
			}
			else
			{
				continue;
			}
		}
	}

	for(int k = 0; k < length1; k++)
	{
		if(array1[k] == 0)
		{
			for(j =0; j < length2; j++)
			{
				a[k][j] = 0;
			}
		}
		else
		{
			continue;
		}
	}

	for(int k = 0; k < length2; k++)
	{
		if(array2[k] == 0)
		{
			for(j =0; j < length1; j++)
			{
				a[j][k] = 0;
			}
		}
		else
		{
			continue;
		}
	}

    cout << "--------------------------------"<<endl;
    //print()
	for(i = 0; i < length1; i++)
	{
		for(j = 0; j < length2; j++)
		{
			cout << a[i][j] << '\t';
		}
		cout << endl;
	}
	return 0;
}
//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117