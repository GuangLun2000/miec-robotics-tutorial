#include <iostream>
using namespace std;

// exper7_4 Pascal's triangle

int binomialSum(int n, int k);

void printPascal(int n)
{
    cout <<"[";
	for (int line = 0; line < n; line++)
	{
        cout <<"[";
		for (int i = 0; i <= line; i++){
            // if (i==line)
            // {
            //     cout << binomialSum(line, i); 
            //     break;
            // }
			cout << binomialSum(line, i);
            if (i<line)
            {
                cout <<",";
            }
        }
		cout <<"]";
        if (line<n-1)
        {
            cout << ",";
        }
        
	}
    cout <<"]";
}

int binomialSum(int n, int k)
{
	int res = 1;
	if (k > n - k)
	k = n - k;
	for (int i = 0; i < k; ++i)
	{
		res *= (n - i);
		res /= (i + 1);
	}
	
	return res;
}

int main()
{
    cout << "Please the height of the Pascal's triangle : ";
	int num;
    cin >> num;
	printPascal(num);
	return 0;
}
//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117