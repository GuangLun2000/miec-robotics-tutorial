/*
Input two sorted integer arrays (as input strings from console), which are sorted from small to large.
Read those input strings as int arrays and combine those arrays being one and sorting it from small to large.


 */

package MIEC_CS210;
import java.util.Arrays;
import java.util.Scanner;

public class P03_SortingTwoArrays {

    public static void main(String[] args) {

        System.out.println("please input Array01: ");
        Scanner input = new Scanner(System.in);
        String str = input.next();
        String[] string = str.split(",");
        int[] numsInt1 = new int[string.length];
        for (int i = 0; i < string.length; i++) {
            numsInt1[i] = Integer.parseInt(string[i]);
            //System.out.print(numsInt1[i]+" ");
        }

        System.out.println("please input Array02: ");
        String str2 = input.next();
        String[] string2 = str2.split(",");
        int[] numsInt2 = new int[string2.length];
        for (int i = 0; i < string2.length; i++) {
            numsInt2[i] = Integer.parseInt(string2[i]);
            //System.out.print(numsInt2[i]+" ");
        }

        input.close();

        int [] numsInt3 = new int[numsInt1.length+numsInt2.length];
        for (int i = 0; i < numsInt1.length; i++) {
            numsInt3[i] = numsInt1[i];
        }
        int n=0;
        for (int i = numsInt1.length; i < numsInt3.length; i++) {
            numsInt3[i] = numsInt2[n];
            n++;
        }

        Arrays.sort(numsInt3);

        for (int i = 0; i < numsInt3.length-1; i++) {
            System.out.print(numsInt3[i] + ",");
        }System.out.print(numsInt3[numsInt3.length-1]);

    }
}
