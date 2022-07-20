/*
Read two inputs - two integer numbers m and n - from console.
Output m^n.

 */
package MIEC_CS210;
import java.util.Scanner;


public class P06_PowerOFn {
    static double pwr(double a, int k) {
        double ans = 1;
        while (k > 0) {
            if ((k & 1) != 0) {
                ans = ans * a;
            }
            a = a * a;
            k >>= 1;
        }
        return ans;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int n = sc.nextInt();
        if (n < 0) {
            System.out.println(pwr(1.0 / m, -n));
        } else {
            System.out.println(pwr(m, n));
        }
    }
}
