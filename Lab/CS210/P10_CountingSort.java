package MIEC_CS210;

//Hanlin Cai  832002117  20122161
import java.util.Scanner;

public class P10_CountingSort {
    static int max1 = 0;
    static int num = 0;
    static int[] cnt = new int[1000];

    public static int max(int a1, int a2) {
        if (a1 > a2) {
            return a1;
        }
        return a2;
    }

    public static void print() {
        System.out.print("Step ");
        System.out.print(num);
        System.out.print(": Count = [");
        for (int i = 0; i <= max1; i++) {
            if (i != 0) {
                System.out.print(",");
            }
            System.out.print(cnt[i]);
        }
        System.out.println("]");
        num++;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] a1 = sc.nextLine().split(",");
        int[] a2 = new int[1000];
        int[] cntNum = new int[1000];
        for (int i = 0; i < a1.length; i++) {
            a2[i] = Integer.parseInt(a1[i]);
            max1 = max(max1, a2[i]);
        }
        for (int i = 0; i < 1000; i++) {
            cnt[i] = 0;
        }
        print();
        for (int i = 0; i < a1.length; i++) {
            cnt[a2[i]]++;
            cntNum[a2[i]]++;
            print();
        }
        for (int i = 1; i <= max1; i++) {
            cnt[i] += cnt[i - 1];
            print();
        }
        for (int i = 0; i < a1.length; i++) {
            cnt[a2[i]]--;
            print();
        }
        System.out.print("[");
        boolean ok = false;
        for (int i = 0; i <= max1; i++) {
            if (cnt[i] != cnt[i + 1]) {
                for (int j = 0; j < cntNum[i]; j++) {
                    if (ok) {
                        System.out.print(", ");
                    }
                    System.out.print(i);
                    ok = true;
                }
            }
        }
        System.out.print("]");
    }
}
