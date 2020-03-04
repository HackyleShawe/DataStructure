
import java.util.Random;

import org.junit.Test;

public class C01_ExchangeBubbleSort {
	private int n = 10;
	
	/**
	 * 冒泡排序
	 * 
	 * 算法：
	 * 	相邻两个数两两交换
	 */
	@Test
	public void testBubbleSort() {
		int[] a = getRandomArray();
		showArray(a);
		
		for(int i=0; i<a.length-1; i++) {
			for(int j=0; j<a.length-i-1; j++) {
				if(a[j]>a[j+1]) {
					int t = a[j];
					a[j] = a[j+1];
					a[j+1] = t;
				}
			}
		}
		
		showArray(a);
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
