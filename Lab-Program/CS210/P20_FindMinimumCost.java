package MIEC_CS210;

import java.util.Scanner;
// This code is contributed by Lance Cai


public class P20_FindMinimumCost{

    static int min(int a, int b) {
        if (a < b) {
            return a;
        } else {
            return b;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();
        String [] input1 = input.split(",");
        int len = input1.length;
        int [] a = new int[100];
        for (int i = 0; i < len; i++) {
            a[i] = Integer.parseInt(input1[i]);
        }
        int m = (int) Math.sqrt(len);
        int [][] maze = new int[100][100];
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                maze[i][j] = a[cnt++];
            }
        }
        int [][] dp = new int[100][100];
        dp[0][0] = maze[0][0];
        for (int i = 1; i < m; i++) {
            dp[0][i] = dp[0][i - 1] + maze[0][i];
            dp[i][0] = dp[i - 1][0] + maze[i][0];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < m; j++) {
                dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + maze[i][j];
            }
        }
        System.out.println(dp[m - 1][m - 1]);
    }

}

// This code is contributed by Lance Cai