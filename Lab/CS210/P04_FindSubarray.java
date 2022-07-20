/*
Given an array of integers and a specify number.
Find a subarray with the maximum length which its sum is equal to this given number.


 */

package MIEC_CS210;

import java.util.Scanner;

public class P04_FindSubarray {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String st = sc.nextLine();
        int sum = sc.nextInt();
        System.out.println(farr(st, sum));

        sc.close();
    }


    public static int[] findSub(String st) {
        String[] numString = st.split(",");
        int len = numString.length;
        if (len < 1) {
            System.out.println("Wrong input! Return null");
            return null;
        }
        int[] nums = new int[len];
        for (int i = 0; i < len; i++) {
            nums[i] = Integer.parseInt(numString[i]);
        }
        return nums;
    }

    public static int farr(String st, int flag) {
        int[] arr = findSub(st);
        int len = arr.length;
        int ans = len;
        int sum = 0;

        while (ans > 0) {
            for (int i = 0; i < len - ans + 1; i++) {
                for (int j = i; j < i + ans; j++) {
                    sum = sum + arr[j];
                }
                //find the flag
                if (flag == sum) {
                    for (int j = i; j < i+ans; j++) {
                        System.out.print(arr[j]+",");
                    }
                    System.out.println();
                    return ans;
                } else {
                    sum = 0;
                }
            }
            ans--;
        }

        if (ans == 0) {
            System.out.println("not exist");
        }
        return ans;
    }

}