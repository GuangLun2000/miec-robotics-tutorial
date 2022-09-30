package MIEC_CS210;
//BaoBaoCode-832002117

import java.util.Scanner;

public class P15_ReverseEveryConsecutiveM {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] x1 = scanner.nextLine().split(",");
        int len = x1.length;
        int[] x = new int[100];
        int[] pre = new int[100];
        for (int i = 0; i < x1.length; i++) {
            x[i] = Integer.parseInt(x1[i]);
        }
        int m = scanner.nextInt();
        int l = scanner.nextInt();
        int r = scanner.nextInt();

        for (int i = l, cnt = 0; cnt < (r - l + 1) / m; i += m, cnt++) {
            int j = i + m - 1;
            for (int k = 0; k < m / 2; k++) {
                int temp = x[j - k];
                x[j - k] = x[i + k];
                x[i + k] = temp;
            }
        }
        for (int i = 0; i < len; i++) {
            if (i != 0) {
                System.out.print(",");
            }
            System.out.print(x[i]);
        }
    }

}
