#include<iostream>
using namespace std;

int FindSecond(int* p, int len)
{
	//
	if (NULL==p || len <= 1)
	{
		return 0;
	}
	//Take the first two elements of the array and consider them to be the largest
	int max = p[0], second = p[1];
	if (max< second)
	{
		//wap(max, second);
		max = p[1];
		second = p[0];
	}
	for (int i = 0; i < len; i++)
	{
		//If max is not the maximum, replace it with a larger one
		if (max < p[i])
		{
			second = max;
			max = p[i];
		}
		//If it's not as big as the number we started with, so compare the second largest number
		else if (second<p[i])
		{
			second = p[i];
		}
	}
	return second;
}

int main(){
    int length;
    cin >> length;
    int tar[length];
    int num;
    cin>>num;
    int count;
    for(count = 0; num >0;){
        tar[count] = num;
        count++;
        cin>>num;
    }

    int second = FindSecond(tar,length);
    if (second == 0)
    {
        cout << "-1" ;
    } else {
        cout << second << endl;
    }
    
}
//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117