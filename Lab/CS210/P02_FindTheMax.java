/*
Given an input string of a sequence of integers from the console (e.g., using Scanner),
read the string and parse it as an unsorted array of integers, then find the maximum and minimum elements of this array.


 */

package MIEC_CS210;
import java.util.Scanner;

public class P02_FindTheMax {

    public static void main(String[] args) {
        // TODO Auto-generated method stub
        System.out.println("please input: ");
        Scanner input = new Scanner(System.in);

        String str = input.nextLine();
        String[] string = str.split(",");

        int[] numsInt = new int[string.length];
        for (int i = 0; i < string.length; i++) {
            numsInt[i] = Integer.parseInt(string[i]);
            //System.out.print(numsInt[i]+" ");
        }

        int max=numsInt[0];
        int min=numsInt[0];

        for(int i=1;i<numsInt.length;i++)
        {
            if(numsInt[i]>max)
            {
                max=numsInt[i];
            }
            if(numsInt[i]<min)
            {
                min=numsInt[i];
            }
        }
        System.out.println("max="+max);
        System.out.println("min="+min);

    }
}
