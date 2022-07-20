#include<cstdio>
#include<cmath>
using namespace std;

//Displays the value of π, using 2, 3, and 4 terms of the series

int main(){
	double PI=0,num=1;
	int i=1;
	while(num <= 7){
        //the slope of num can be changed
        //the bigger the more accurate
        
		if(i%2){
			PI += 1/num;
		}else{
			PI -= 1/num;
		}
		num += 2;
		i ++;
	}

	PI *= 4;
	printf("PI=%10.8f",PI);
	return 0;
}

//this code is created by Lance Cai 832002117