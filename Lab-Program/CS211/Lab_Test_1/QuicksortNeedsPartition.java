package MIEC_CS211.Lab_Test_1;

import java.util.Arrays;

public class QuicksortNeedsPartition<E extends Comparable<E>> {
	private static <E> void swap(E[] data, int idx1, int idx2) {
		E temp = data[idx1];
		data[idx1] = data[idx2];
		data[idx2] = temp;
	}

	// Implement the method here
	// by Hanlin Cai 832002117
	private int hoarePartition(E[] data, int left, int right) {
		int i = left;
		int j = right;
		E temp = data[left];
		E flag;

		while(i < j){
			while(i < j && temp.compareTo(data[j])<=0){
				j--;
			}
			while(i < j && temp.compareTo(data[i])>=0){
				i++;
			}
			if(i < j){
				flag = data[j];
				data[j] = data[i];
				data[i] = flag;
			}

		}
		
		data[left] = data[i];
		data[i] = temp;
				
		return j;
	}

	private void quicksort(E[]data, int left, int right) {
		if (left < right) {
			int p = hoarePartition(data, left, right);
			quicksort(data, left, p);
			quicksort(data, p + 1, right);
		}
	}

	public void quicksort(E[] data) {
		quicksort(data, 0, data.length - 1);
		
	}

	public static void main(String[] args) {
		Integer[] data = { 16, 8, 24, 4, 12, 20, 28, 2, 6, 10, 14, 26, 1 };
		QuicksortNeedsPartition<Integer> qs = new QuicksortNeedsPartition<>();

		qs.quicksort(data);

		System.out.println(Arrays.toString(data));
	}

}

