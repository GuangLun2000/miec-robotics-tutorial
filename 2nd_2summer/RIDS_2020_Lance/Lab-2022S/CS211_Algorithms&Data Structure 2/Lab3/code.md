```
package MIEC_CS211.Lab3_0422;

import java.io.*;
import java.util.Arrays;

public class SortingRecords {
    private static void mergeSort(String[] data, String[] auxArray, int left, int right) {
        if (left < right) {
            int centre = (left + right) / 2;
            mergeSort(data, auxArray, left, centre);
            mergeSort(data, auxArray, centre + 1, right);
            merge(data, auxArray, left, centre + 1, right);
        }
    }

    public static void mergeSort(String[] data) {
        String[] auxArray = new String[data.length];

        mergeSort(data, auxArray, 0, data.length - 1);
    }

    /**
     *
     * @param data original array
     * @param auxArray sorted array
     * @param leftPos left
     * @param rightPos right
     * @param rightEnd
     */
    private static void merge(String[] data, String[] auxArray, int leftPos, int rightPos, int rightEnd) {
        int leftEnd = rightPos - 1;
        int tempPos = leftPos;
        int numElements = rightEnd - leftPos + 1;

//        for (int i = 0; i < data.length; i++) {
//
//        }

        // Start by populating the left and right (ordered) data into the auxArray array
        // Until one of the ordered sequences on the left and right sides is processed
        while (leftPos <= leftEnd && rightPos <= rightEnd) {

            // If the current element of the left ordered sequence is less than or equal to the current element of the right ordered sequence
            // Populate the auxArray array with the current element on the left
            if (/*data[leftPos]<=data[rightPos] */data[leftPos].equals(data[rightPos]) && (data[leftPos].compareTo(data[rightPos]) <0 ) ) {
                auxArray[tempPos++] = data[leftPos++];
            } else {
                auxArray[tempPos++] = data[rightPos++];
            }
        }


        // Fill the rest of the data into auxArray
        while (leftPos <= leftEnd) {
            auxArray[tempPos++] = data[leftPos++];
        }

        while (rightPos <= rightEnd) {
            auxArray[tempPos++] = data[rightPos++];
        }

        for (int i = 0; i < numElements; i++, rightEnd--) {
            data[rightEnd] = auxArray[rightEnd];
        }
    }



    public static void main(String[] args) throws IOException {
//        int[] l1 = { 9, 3, 4, 2, 7, 8, 16, 2, 19, 1 };


        File f = new File("/Users/lancecai/Desktop/Lab-2022S/CS211_Algorithms&Data Structure 2/Lab3/Lab3_DrugsCom.tsv");
        FileReader fre = new FileReader(f);
        BufferedReader bre = new BufferedReader(fre);
        String str = "";

        int count = 0 ;
        while ((str = bre.readLine()) != null) {
            System.out.println(str);
            String[] string = str.split("   ");
            String[][] temp = new String[0][];

            for(int k = 0; k < string.length ;) {
                for (int i = 0; i < string.length/6;) {
                    for (int j = 0; j < 6; ) {
                        temp[i][j] = string[k];
                        j++;
//                        System.out.println(temp[i][j]);
                    }
                    i++;
                }
                k++;
            }

            for (int i = 0; i <temp.length; i++) {
                SortingRecords.mergeSort(temp[i]);
                System.out.println(Arrays.toString( temp ));
            }



//            String[] temp;
//            count++;


        }



        bre.close();
        fre.close();


//            for(int k = 5; k < string.length ;) {
//                for (int i = 0; i < string.length/6;) {
//                    for (int j = 0; j < 6; ) {
//                        temp[i][j] = string[k];
//                        j++;
//                    }
//                    i++;
//                }
//                k++;
//            }

//            int[] numsInt1 = new int[string.length/6];
//            for (int i = 0; i < string.length; i++) {
//                SortingRecords.mergeSort(temp[i][3]);



//        SortingRecords.mergeSort(l1);
//        System.out.println(Arrays.toString(l1));

    }
}
```