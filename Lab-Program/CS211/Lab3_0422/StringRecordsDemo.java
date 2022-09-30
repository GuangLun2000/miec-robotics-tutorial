package MIEC_CS211.Lab3_0422;

import java.io.*;
public class StringRecordsDemo {
    private static void mergeSort(String data[][], String[][] auxArray, int left, int right) {
        if (left < right) {
            int centre = (left + right) / 2;
            mergeSort(data, auxArray, left, centre);
            mergeSort(data, auxArray, centre + 1, right);
            merge(data, auxArray, left, centre + 1, right);
        }
    }

    public static void mergeSort(String[][] data) {
        String[][] auxArray = new String[data.length][6];

        mergeSort(data, auxArray, 0, data.length - 1);
    }

    //In this method, we merge the arrays on both sides
    private static void merge(String[][] data, String[][] auxArray, int leftPos, int rightPos, int rightEnd){
        int leftEnd = rightPos - 1;//get the end on the left
        int tempPos = leftPos;
        int numElements = rightEnd - leftPos + 1;//Get the number of elements

        //In this while loop, we combine a new array by comparing
        // the size of the left and right elements
        while (leftPos <= leftEnd && rightPos <= rightEnd) {
            if (Integer.parseInt(data[leftPos][3]) < Integer.parseInt(data[rightPos][3])) {
                for (int i = 0; i < 6; i++) {
                    auxArray[tempPos][i]=data[leftPos][i];
                }
                tempPos++;leftPos++;
            } else if(Integer.parseInt(data[leftPos][3])==Integer.parseInt(data[rightPos][3])) {
                if (Integer.parseInt(data[leftPos][5]) <=Integer.parseInt(data[rightPos][5])) {
                    for (int i = 0; i < 6; i++) {
                        auxArray[tempPos][i]=data[leftPos][i];
                    }
                    tempPos++;leftPos++;
                }else {
                    for (int i = 0; i < 6; i++) {
                        auxArray[tempPos][i]=data[rightPos][i];
                    }
                    tempPos++;rightPos++;
                }
            }else {
                for (int i = 0; i < 6; i++) {
                    auxArray[tempPos][i]=data[rightPos][i];
                }
                tempPos++;rightPos++;
            }
        }

        while (leftPos <= leftEnd) {
            for (int i = 0; i < 6; i++) {
                auxArray[tempPos][i]=data[leftPos][i];
            }
            tempPos++;leftPos++;
        }

        while (rightPos <= rightEnd) {
            for (int i = 0; i < 6; i++) {
                auxArray[tempPos][i]=data[rightPos][i];
            }
            tempPos++;rightPos++;
        }

        //It rearranges two elements here
        for (int i = 0; i < numElements; i++, rightEnd--) {
            for (int j = 0; j < 6; j++) {
                data[rightEnd][j]=auxArray[rightEnd][j];
            }
        }
    }

    public static void main(String[] args) throws IOException{
        File f=new File("/Users/lancecai/Desktop/Lab-2022S/CS211_Algorithms&Data Structure 2/Lab3/Lab3_DrugsCom.tsv");
        FileInputStream fip=new FileInputStream(f);
        BufferedReader br=new BufferedReader(new InputStreamReader(fip));
        String S1[]=new String[161297];
        int i=0;
        while(br.ready()&&i<S1.length) {
            S1[i]=br.readLine();
            i++;
        }
        System.out.println(S1.length);
        System.out.println(S1[1]);
        String s[][]=new String[S1.length-1][6];
        for (int j = 0; j < s.length; j++) {
            String s2[]=S1[j+1].split("	");
            for (int k = 0; k < s2.length; k++) {
                s[j][k]=s2[k];
            }

        }
        System.out.println(s[0][3]);
        System.out.println(s[1][3]);
        System.out.println(Integer.parseInt(s[0][3])>Integer.parseInt(s[1][3]));
        StringRecordsDemo.mergeSort(s);
        File file =new File("/Users/lancecai/Desktop/Lab-2022S/CS211_Algorithms&Data Structure 2/Lab3/Results.tsv");
        if (!file.exists()) {
            file.createNewFile();
        }
        FileOutputStream fop=new FileOutputStream(file);
        OutputStreamWriter write = new OutputStreamWriter(fop);
        for (int j = 0; j < s.length; j++) {
            for (int j2 = 0; j2 < 6; j2++) {
                write.append(s[j][j2]+"	");
            }
            write.append("\n");
        }
        write.close();
    }


}

