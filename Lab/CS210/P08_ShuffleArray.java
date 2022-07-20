/*
Given an array of distinct integers, shuffle it according to the given order of elements.

 */

package MIEC_CS210;
import java.util.Scanner;


public class P08_ShuffleArray {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.nextLine();
        String b = sc.nextLine();
        String [] ta = a.split(",");
        String [] tb = b.split(",");
        int [] aa = new int[105];
        int [] bb = new int[105];
        for (int i = 0; i < ta.length; i++) {
            aa[i] = Integer.parseInt(ta[i]);
            bb[i] = Integer.parseInt(tb[i]);
        }
        for (int i = 0; i < ta.length; i++) {
            if (i != 0) {
                System.out.print(",");
            }
            System.out.print(aa[bb[i]]);
        }
    }
}
