/*
Given an input string of a signed 32-bit integer x, return x with its digits reversed.
If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31-1], then return 0.


 */

package MIEC_CS210;
import java.util.Scanner;

public class P07_ReverseInteger {

    public static void main(String[] args) {
        System.out.println("Please input the integer:");
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        System.out.println(reverseInteger(num));

    }

    public static int  reverseInteger(int num) {
        long ans1 = 0 ;
        int temp = 0;

        while (num!=0) {
            temp = num%10;
            num/=10;
            ans1=ans1*10+temp;
            if (ans1>Integer.MAX_VALUE||ans1<Integer.MIN_VALUE) {
                return 0;
            }
        }
        return (int) ans1;


    }
}
