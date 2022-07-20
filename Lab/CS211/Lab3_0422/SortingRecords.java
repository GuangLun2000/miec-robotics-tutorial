package MIEC_CS211.Lab3_0422;

// This code is contributed by Hanlin Cai 832002117 20122161
// Last update in 2022/04/22 04:21pm

import java.io.*;
import java.util.Arrays;

public class SortingRecords {

    static int length;
    static class drug {
        String code;
        String drugName;
        String condition;
        int rating;
        String date;
        int usefulCount;
        // This code is contributed by Hanlin Cai 832002117 20122161
    }

    private static void mergeSort(drug[] data, int[] auxArray, int left, int right) {
        if (left < right) {
            int centre = (left + right) / 2;
            mergeSort(data, auxArray, left, centre);
            // sort the left partition
            mergeSort(data, auxArray, centre + 1, right);
            // sort the right partition
            merge(data, auxArray, left, centre + 1, right);
            // get two partition sorted together
        }
    }

    public static void mergeSort(drug[] data) {
        int[] auxArray = new int[data.length];

        mergeSort(data, auxArray, 0, length);
    }

    /**
     *
     * @param data original array
     * @param auxArray sorted array
     * @param leftPos left
     * @param rightPos right
     * @param rightEnd
     * This code is contributed by Hanlin Cai 832002117 20122161
     */
    private static void merge(drug[] data, int[] auxArray, int leftPos, int rightPos, int rightEnd) {
        int leftEnd = rightPos - 1;
        int tempPos = leftPos;
        int numElements = rightEnd - leftPos + 1;
        // Start by populating the left and right (ordered) data into the auxArray array
        // Until one of the ordered sequences on the left and right sides is processed
        while (leftPos <= leftEnd && rightPos <= rightEnd) {
            // If the current element of the left ordered sequence is less than or equal to the current element of the right ordered sequence
            // Populate the auxArray array with the current element on the left
            if (data[leftPos].rating <= data[rightPos].rating) {
                auxArray[tempPos++] = data[leftPos++].rating;
            } else {
                auxArray[tempPos++] = data[rightPos++].rating;
            }
        }

        // Fill the rest of the data into auxArray
        while (leftPos <= leftEnd) {
            auxArray[tempPos++] = data[leftPos++].rating;
        }

        while (rightPos <= rightEnd) {
            auxArray[tempPos++] = data[rightPos++].rating;
        }

        for (int i = 0; i < numElements; i++, rightEnd--) {
            data[rightEnd].rating = auxArray[rightEnd];
        }
    }

    // This code is contributed by Hanlin Cai 832002117 20122161
    public static void main(String[] args) throws IOException {
        //Read the tsv file by ISR
        InputStreamReader ISR = new InputStreamReader(new FileInputStream("/Users/lancecai/Desktop/Lab-2022S/CS211_Algorithms&Data Structure 2/Lab3/Lab3_DrugsCom.tsv"));
        char[] ch = new char[10000000];
        ISR.read(ch);
        String[] str0 = (new String(ch)).split("    ");
        length = str0.length - 1;

        drug[] str1 = new drug[2000000];
        for (int i = 0; i < 2000000; i++) {
            str1[i] = new drug();
        }

        for (int j = 1; j < str0.length; j++) {
            str1[j] = new drug();
            String[] str2 = str0[j].split("\t");
            str1[j].code = str2[0];
            str1[j].drugName = str2[1];
            str1[j].condition = str2[2];
            str1[j].rating = Integer.parseInt(str2[3]);
            str1[j].date = str2[4];
            str1[j].usefulCount = Integer.parseInt(str2[5].trim());
//            System.out.println(str1[j].code + "\t" + str1[j].drugName + "\t" + str1[j].condition + "\t" + str1[j].rating + "\t" + str1[j].date + "\t" + str1[j].usefulCount + "\n");

        }
        SortingRecords.mergeSort(str1);
//        SortingRecords.mergeSort(str2);

//        for (int i = 1; i < length; i++) {
//            System.out.println(str1[i].code + "\t" + str1[i].drugName + "\t" + str1[i].condition + "\t" + str1[i].rating + "\t" + str1[i].date + "\t" + str1[i].usefulCount + "\n");
//        }

        BufferedWriter BW = new BufferedWriter(new FileWriter("/Users/lancecai/Desktop/Lab-2022S/CS211_Algorithms&Data Structure 2/Lab3/Results.tsv"));
        BW.write("code\tdrugName\tcondition\trating\tdate\tusefulCount\n");
        for (int i = 1; i < length; i++) {
            String out = str1[i].code + "\t" + str1[i].drugName + "\t" + str1[i].condition + "\t" + str1[i].rating + "\t" + str1[i].date + "\t" + str1[i].usefulCount + "\n";
            BW.write(out);
        }

    }

}
// This code is contributed by Hanlin Cai 832002117 20122161
// Last update in 2022/04/22 04:21pm