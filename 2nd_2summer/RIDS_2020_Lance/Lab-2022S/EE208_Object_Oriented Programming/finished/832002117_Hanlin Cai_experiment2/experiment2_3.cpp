#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//Given an integer array nums, find three numbers hose product is maximum
//and return the maximum product

class Solution {

public:
    int maxProduct(vector<int> & nums) {

        int length = nums.size();
        int res;
        // If the lengthgth is 3, we just multiply it.
        if (length == 3) {
            return nums[length - 1] * nums[length - 2] * nums[length - 3];
        }
        //If we have two negative numbers at the end, we compare the product. 
        //If we don't have two negative numbers, we just return the product of the three numbers.
        int min1 = INT_MAX, min2 = INT_MAX, max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            int a = nums[i];
            int temp = 0;
            if (a <= min1) {
                min2 = min1;
                min1 = a;
            }
            else if (a < min2) {
                min2 = a;
            }
            if (a >= max1) {
                max3 = max2;
                max2 = max1;
                max1 = a;
            }
            else if (a >= max2) {
                max3 = max2;
                max2 = a;
            }
            else if (a > max3) {
                max3 = a;
            }

            //try to get the sort
            //cout<<min1<<" "<<min2<<" "<<max3<<" "<<max2<<" "<<max1<<"\t\t\t";
        }

        if (min1 < 0 && min2 < 0) {
            return max(max1 * max2 * max3, min1 * min2 * max1);
        }
        else {
            return max1 * max2 * max3;
        }
    }
};

int main() {

    vector<int> intVector{ -6,1,2,3,4,5,6 }; //the output = 120

    Solution sol;
    cout << "Output = " << sol.maxProduct(intVector) << endl;
    return 0;
}


//This code is created by Hanlin Cai
//MU  number : 20122161
//FZU number : 832002117