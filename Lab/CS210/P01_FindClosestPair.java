/*
Given an input string of a sequence of integers from the console (e.g., using Scanner)
read the string and parse it as an unsorted array of integers，
then find the closest pair of the adjacent elements of this array.

找到差值最小的一对（或多对）相邻数

所用知识点：
1、split函数，删去逗号
2、

 */

package MIEC_CS210;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
public class P01_FindClosestPair {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        findIndex(str);
    }

    public static void findIndex(String st) {
        String[] numString = st.split(",");
        int len = numString.length;
        int[] nums = new int[len];
        for (int i = 0; i < len; i++) {
            nums[i] = Integer.parseInt(numString[i]);
        }
        int difference = Math.abs(nums[0] - nums[1]);
        List<Integer> list = new ArrayList<>();
        list.add(0);
        for (int i = 1; i < len - 1; i++) {
            int tempDifference = Math.abs(nums[i] - nums[i + 1]);

            if (tempDifference < difference) {
                difference = tempDifference;
                list.clear();
                list.add(i);
            } else if (tempDifference == difference){
                list.add(i);
            }

        }

        for (int index : list) {
            System.out.println("Pair found at index " + index + " and " + (index + 1));
        }
    }
}