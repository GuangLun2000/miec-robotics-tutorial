#include <iostream>
#include <vector>
using namespace std;

int main(){
    int count = 0;
    int array[100];
    printf("please enter the vector: \n");
    do{
        scanf("%d" , &array[count]);
        count++;
    }while(array[count-1] >= 0);

    //BubbleSortTest by Hanlin Cai
    //BubbleSort(array,count);

    vector<int> vec(array,array+count-1);
    // cout << vec.size() << endl;
    // int min = *min_element(vec.begin(), vec.end());
    // cout << min << endl;

    //cout << "the min number is: " << *min_element(vec.begin(),vec.end())<<endl;
    cout << "the min location is: " << distance(vec.begin(),min_element(vec.begin(),vec.end())) +1 <<endl;
    
    // for(int i=0;i<vec.size();i++){
    //     cout << vec[i] << " ";
    // }

}
//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117