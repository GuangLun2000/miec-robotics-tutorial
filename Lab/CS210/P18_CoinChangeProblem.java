package MIEC_CS210;

// This code is contributed by Lance Cai
// Recursive JAVA program for
// coin change problem.

import java.util.*;
class P18_CoinChangeProblem
{

    // Returns the count of ways we can
// sum S[0...m-1] coins to get sum n
    static int count(int S[], int m, int n)
    {

        // If n is 0 then there is 1 solution
        // (do not include any coin)
        if (n == 0)
            return 1;

        // If n is less than 0 then no
        // solution exists
        if (n < 0)
            return 0;

        // If there are no coins and n
        // is greater than 0, then no
        // solution exist
        if (m <= 0 && n >= 1)
            return 0;

        // count is sum of solutions (i)
        // including S[m-1] (ii) excluding S[m-1]
        return count(S, m - 1, n) +
                count(S, m, n - S[m - 1]);
    }

    // Driver code
    // This code is contributed by Lance Cai
    public static void main(String args[])
    {
        Scanner input = new Scanner(System.in);
        String str = input.next();
        int total = input.nextInt();
        String[] string = str.split(",");
        int[] numsInt1 = new int[string.length];
        for (int i = 0; i < string.length; i++) {
            numsInt1[i] = Integer.parseInt(string[i]);
            //System.out.print(numsInt1[i]+" ");
        }
        int m = numsInt1.length;

        System.out.println(count(numsInt1, m, total));
    }

}

// This code is contributed by Lance Cai 20122161