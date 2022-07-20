package MIEC_CS210;

//Hanlin Cai  832002117  20122161
import java.util.Scanner;

public class P12_FindSecondMaxInt {
    static int max(int a, int b) {
        if (a > b) {
            return a;
        }
        return b;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] a1 = sc.nextLine().split(",");
        int[] a2 = new int[1000];
        int max1 = -1;
        int max2 = -1;
        for (int i = 0; i < a1.length; i++) {
            a2[i] = Integer.parseInt(a1[i]);
            if (a2[i] > max1) {
                max2 = max1;
                max1 = a2[i];
            } else if (a2[i] > max2 && a2[i] != max1) {
                max2 = a2[i];
            }
        }
        if (max2 != -1) {
            System.out.println(max2);
        } else {
            System.out.println("No second largest number found in the given array");
        }
    }
}