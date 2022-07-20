package MIEC_CS210;

import java.util.Scanner;
// This code is contributed by Lance Cai

public class P19_FindFloorAndCeil {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();
        int n = sc.nextInt();
        String [] input1 = input.split(",");
        int len = input1.length;
        int [] a = new int[100];
        for (int i = 0; i < len; i++) {
            a[i] = Integer.parseInt(input1[i]);
        }

        // Find the ceil of `x` in a sorted array nums[]
        int l = 0, r = len - 1, mid;
        if (n < a[0]) {
            System.out.print(-999);
        } else {
            while (l <= r) {
                mid = (l + r) / 2;
                if (a[mid] > n) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            System.out.print(a[r]);
        }
        System.out.print(",");
        l = 0;
        r = len;
        if (n > a[len - 1]) {
            System.out.print(-999);
        } else {
            while (l < r) {
                mid = (l + r) / 2;
                if (a[mid] >= n) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            System.out.println(a[l]);
        }
    }
}

// This code is contributed by Lance Cai
