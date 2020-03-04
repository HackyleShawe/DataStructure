
import java.util.Random;

import org.junit.Test;

public class C02_QuickSort {
	private int n = 10;
	
	@Test
	public void test() {
		int[] a = getRandomArray();
		showArray(a);
		
		quickSort(a,0,a.length-1);
		
		showArray(a);
	}
	
	public void quickSort(int[] a, int low, int high) {
		if(low<high) {
			int pivot = partition(a,low,high);
			quickSort(a,low,pivot-1);
			quickSort(a,pivot+1,high);
		}
		
	}
	public int partition(int[] a, int low, int high) {
		int pivot_key = a[low]; //以传入数组的第一个元素作基数
		
		while (low < high) //从数组的两端分别向中间扫描
		{
			while (low < high && a[high] >= pivot_key) //当队尾的元素大于等于基数时,向前挪动high指针
			{
				high--;
			}
			//一旦找到比基数小的数，将该数放到最左端
			a[low] = a[low] ^ a[high];
			a[high] = a[low] ^ a[high];
			a[low] = a[low] ^ a[high];

			while (low < high && a[low] <= pivot_key) //从左往右
			{
				low++;
			}
			//一旦找到比基数大的数，将该数放到最右端
			a[low] = a[low] ^ a[high];
			a[high] = a[low] ^ a[high];
			a[low] = a[low] ^ a[high];
		}
		a[low] = pivot_key;
		
		return low;
	}
	
	
	public void showArray(int[] a) {
		for(int i=0; i<n; i++) {
			System.out.print(a[i] + " ");
		}
		System.out.println();
	}
	public int[] getRandomArray() {
		int[] a = new int[n];
		Random rand = new Random();
		for(int i=0; i<n; i++) {
			a[i] = rand.nextInt(1000);
		}
		return a;
	}
}
