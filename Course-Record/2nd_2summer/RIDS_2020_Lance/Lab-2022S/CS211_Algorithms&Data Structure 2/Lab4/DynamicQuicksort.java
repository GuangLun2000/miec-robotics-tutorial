

import java.io.*;
import java.util.Arrays;
import java.util.Arrays;
import java.util.Random;
import java.util.*;
import java.util.stream.Stream;


public class DynamicQuicksort<E extends Comparable<E>> {
//    private int length;

    private static <E> void swap(E[] data, int idx1, int idx2) {
        E temp = data[idx1];
        data[idx1] = data[idx2];
        data[idx2] = temp;
    }

    // To implement insertionSort by Hanlin Cai
    private void insertionSort(E[] data, int left, int right) {
        int i,j;
        E temp;
        for(i=1;i<data.length;i++) {
            temp=data[i];
            for(j=i-1;j>=0;j--) {
                if(temp.compareTo( data[j]) > 0 ) {
                    break;
                }else {
                    data[j+1]=data[j];
                }
            }
            data[j+1]=temp;
        }
    }

    // To implement medianOfThreePartition by Hanlin Cai
    private int medianOfThreePartition(E[] data, int left, int right) {
        /*
        data[pivot] <= data[left] <= data[right]
        1、Put the largest number in the first, 
        2、the largest number in the last, 
        3、and the smallest number in the pivotdle
        */
        int pivot = (right + left)/2;
        if(data[left].compareTo( data[right]) > 0 ) {
            swap(data,left,right);
        } //data[left] <= data[right]
        if(data[pivot].compareTo( data[right]) > 0){
            swap(data,pivot,right);
        }//data[pivot] <= data[right]
        if(data[pivot].compareTo(data[left]) > 0){
            swap(data,left,pivot);
        }//data[pivot] <= data[left]
        
        return 0;
    }

    // To implement randomizedPartition by Hanlin Cai
    private int randomizedPartition(E[] data, int left, int right) {
        Random random = new Random();
        int ranNum = random.nextInt(right-left+1)+left;
        swap(data,left,ranNum);
        int pivot = randomizedPartition(data,left,right);
        if(pivot > left+1){  //There are two elements on the left: starting left 0, pivot>1, at subscript 2
            quicksort(data,left,pivot-1);
        }
        if(pivot < right-1){ //There are two elements on the right: the starting bit, pivot+1
            quicksort(data,pivot+1,right);
        }

        return 0;
    }

    // To comment hoarePartition by Hanlin Cai
    private int hoarePartition(E[] data, int left, int right) {
        E pivot = data[left];
        int i = left - 1;
        int j = right + 1;
        // Left and right must be equal after the while loop ends.
        while (true) {
            do {
                j = j - 1;
            } while (data[j].compareTo(pivot) > 0); // Compare from back to front
            do {
                i = i + 1;
            } while (data[i].compareTo(pivot) < 0);
            /*
            If there is none less than the base value,
            the next one is compared until there is one less than the base value,
            then the position is changed, and then the comparison is backward again.

            This comment is created by Hanlin Cai 832002117.

            If there is none greater than the base value,
            the next one is compared until there is one greater than the base value,
            then the position is switched
             */
            if (i < j) {
                swap(data, i, j);
            } else {
                return j;
            }
        }
    }

    // To choose the 4 different method
    private void quicksort(E[] data, int left, int right) {
        if (left < right) {

            if(data.length <= 20) {
                insertionSort(data,left,right);
            }

            if(20 < data.length && data.length <= 64) {
                int p = randomizedPartition(data, left, right);
                quicksort(data, left, p);
                quicksort(data, p + 1, right);
            }

            if(64 < data.length && data.length <= 256) {
                int p = hoarePartition(data, left, right);
                quicksort(data, left, p);
                quicksort(data, p + 1, right);
            }

            if(256 < data.length) {
                int p = medianOfThreePartition(data, left, right);
                quicksort(data, left, p);
                quicksort(data, p + 1, right);
            }

        }
    }

    public void quicksort(E[] data) {
        quicksort(data, 0, data.length - 1);
    }

    public static void main(String[] args) throws IOException {
//        Test the Algorithms 1st
//        Integer[] data = { 16, 8, 24, 4, 12, 20, 28, 2, 6, 10, 14, 26, 1 };
//        DynamicQuicksort<Integer> qs = new DynamicQuicksort<>();
//        qs.quicksort(data);
//        System.out.println(Arrays.toString(data));

//        Test the Algorithms 2nd
//        Integer[] a = new Integer[1000000];
//        for (int i = 0; i < 1000000; i++) {
//            a[i] = (int) (Math.random() * 8000000); // 生成一个[0, 8000000) 数
//        }


        // T4--------Test my Algorithms, by Hanlin Cai----------
        BufferedReader readTxt=new BufferedReader(new FileReader("/Users/lancecai/Desktop/Lab-2022S/CS211_Algorithms&Data Structure 2/Lab4/Lab4_RandomNumbers_1M.txt"));
        String textLine="";
        String str="";
        while(( textLine=readTxt.readLine())!=null){
            str += textLine;
        }
        //
        Integer[] a = new Integer[1000000];
        String[] numbersArray = str.split(" ");
//        Integer[] a = Convert.toIntArray(numbersArray);

        for (int i = 0; i < a.length; i++) {
//            System.out.println(numbersArray[i]);
            a[i] = Integer.valueOf(numbersArray[i]);
        }

        //运行前当前系统时间 Current system time before running
        long startTime1 = System.currentTimeMillis();
        //Quick Sort
        DynamicQuicksort<Integer> qs = new DynamicQuicksort<>();
        qs.quicksort(a);
        System.out.println(Arrays.toString(a));

        //运行后当前系统时间 Current system time after running
        long endTime1 = System.currentTimeMillis();
        System.out.println("Running time : " + (endTime1 - startTime1) + " ms");

//        long startTime2 = System.currentTimeMillis();
        //Java工具类自带排序
//        Arrays.sort(a);
//        long endTime2 = System.currentTimeMillis();
//        System.out.println("Java工具类自带排序运行时间:" + (endTime2 - startTime2) + "ms");


        /** T5--------3 extra marks, by Hanlin Cai----------
         *  (1) Chinese: 处理100万个数据时候，插入排序大概需要：569840ms----而快速排序仅需要：130ms
         *     English: When processing 1 million data, insert sort needs approximately: 569840ms ---- while quicksort only needs: 130ms.
         *
         *  (2) Chinese: 快排的优化主要可以采取以下两种方法：
         *              1、当某个区间需要排序的数据为一定范围时，进行直接插入排序，就像这个实验第三步所做的那样
         *              2、采用聚集相同基准元素法，从而提高算法效率，具体代码我附在本代码页面最下方
         *     English: Quicksort can be optimized in the following two ways:
         *              1、When the data to be sorted in a certain range is within a certain range, direct insertion sort is carried out, just as in the third step of this experiment.
         *              2、Use the method of gathering the same benchmark elements to improve the efficiency of the algorithm. The specific code is attached at the bottom of the page of this code.
         */

    }

}


/* 采用聚集相同基准元素法 by Hanlin Cai
待排序数据中有很多相同的数据时，要进行优化，则采取这个方式：
在基准（par）的左边和右边分别定义一个值，par_left和par_right,
先判断基准右边：定义变量i，判断i下标的值是否和par对应的值相等
1、不相等的话，i++
2、相等的话par_right和i先交换，然后par_right和i的下标都+1
3、再用相同的方法判断基准的左边

public static int[] Focus_Same_Num(int[] arr, int low, int par, int high, int left, int right) {
    // 右边
    int par_right = par + 1;
    for (int i = par + 1; i <= high; i++) { //右边
        if (arr[i] == arr[par]) {  //相同的话pr和i先交换再pr和i都++
            if (i != par_right) { //不是紧挨着
                swap(arr, i, par_right);
                par_right++;
            } else { //紧挨着，不用交换，比较下一个
                par_right++;
            }
        }
    }
    right = par_right;
    //左 边
    int par_left = par - 1;
    for (int j = par - 1; j >= low; j--) { //左边
        if (arr[j] == arr[par]) {
            if (j != par_right) { //不是紧挨着
                swap(arr, j, par_left);
                par_left--;
            } else { //紧挨着，不用交换，比较下一个
                par_left--;
            }
        }
    }
    left = par_left;
    int[] temp = new int[2];
    temp[0] = left;
    temp[1] = right;
    return temp;
}

 */