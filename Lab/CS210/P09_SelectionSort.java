/*
Given an array of distinct integers, using selection sort to sort it.
And print out each step of your code.

 */

package MIEC_CS210;
import java.util.Scanner;

public class P09_SelectionSort {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.nextLine();
        String [] ta = a.split(",");
        int [] aa = new int[105];
        int len = ta.length;
        for (int i = 0; i < len; i++) {
            aa[i] = Integer.parseInt(ta[i]);
        }
        for (int i = 0; i < len; i++) {
            System.out.print("Step " + i + ": arr =  [");
            for (int j = 0; j < len; j++) {
                if (j != 0) {
                    System.out.print(", ");
                }
                System.out.print(aa[j]);
            }
            System.out.print("]");
            int pos = 0, minNum = 0x3f3f3f3f;
            for (int j = i; j < len; j++) {
                if (aa[j] < minNum) {
                    minNum = aa[j];
                    pos = j;
                }
            }
            System.out.println(" and min_position = " + pos);
            if (pos != i) {
                aa[pos] ^= aa[i];
                aa[i] ^= aa[pos];
                aa[pos] ^= aa[i];
            }
        }


    }
}
