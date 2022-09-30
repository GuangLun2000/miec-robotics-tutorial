package MIEC_CS210;
//BaoBaoCode-832002117

import java.util.Arrays;
import java.util.Scanner;

public class P13_MergeTwoArrays {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] x1 = scanner.nextLine().split(",");
        int[] x = new int[100];
        for (int i = 0; i < x1.length; i++) {
            x[i] = Integer.parseInt(x1[i]);
        }
        String[] y1 = scanner.nextLine().split(",");
        int[] y = new int[100];
        for (int i = 0; i < y1.length; i++) {
            y[i] = Integer.parseInt(y1[i]);
        }
        int pos = 0;
        for (int i = 0; i < x1.length; i++) {
            if (x[i] == 0) {
                x[i] = y[pos++];
            }
        }
        Arrays.sort(x, 0, x1.length);
        for (int i = 0; i < x1.length; i++) {
            if (i != 0) {
                System.out.print(",");
            }
            System.out.print(x[i]);
        }
    }

}
