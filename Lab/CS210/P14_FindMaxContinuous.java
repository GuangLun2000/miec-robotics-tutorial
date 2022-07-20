package MIEC_CS210;
//BaoBaoCode-832002117

import java.util.Scanner;

public class P14_FindMaxContinuous {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        String[] x1 = scanner.nextLine().split(",");
        int len = x1.length;
        int[] x = new int[1000];
        int[] pre = new int[1000];

        for (int i = 0; i < x1.length; i++) {
            x[i] = Integer.parseInt(x1[i]);
            if (i == 0) {
                pre[i] = (x[i] == 0 ? 1 : 0);
            } else {
                pre[i] = pre[i - 1] + (x[i] == 0 ? 1 : 0);
            }
        }


        int k = scanner.nextInt();
        int ans = 0, l = -1, r = -1;
        for (int i = 0; i < len - 1; i++) {
            for (int j = i + 1; j < len; j++) {
                int num;
                if (i == 0) {
                    num = pre[j];
                } else {
                    num = pre[j] - pre[i - 1];
                }
                if (num <= k) {
                    if (j - i + 1 > ans) {
                        l = i;
                        r = j;
                        ans = j - i + 1;
                    }
                }
            }
        }

        //PrintMode
        System.out.print("The length of longest sequence is ");
        System.out.print(ans);
        System.out.print(" (from index ");
        System.out.print(l);
        System.out.print(" to index ");
        System.out.print(r);
        System.out.println(")");
        System.out.print("[");

        for (int i = 0; i < len; i++) {
            if (i != 0) {
                System.out.print(", ");
            }
            if (l <= i && i <= r) {
                System.out.print(1);
            } else {
                System.out.print(x[i]);
            }
        }
        System.out.println("]");
    }

}
