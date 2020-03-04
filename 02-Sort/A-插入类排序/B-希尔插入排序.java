
import java.util.Random;

import org.junit.Test;

public class A01_ShellInsertSort {
	private int n = 10;
	
	/**
	 * 希尔插入排序
	 * 算法：
	 * 	把插入排序中的“减1”改为“减d”
	 */
	@Test
	public void shellInsertSort() {
		int[] a = getRandomArray();
		showArray(a);
		
		for(int d=a.length/2; d>0; d/=2) {
			for(int i=d; i<a.length; i++) {
				int t=a[i];
				int j;
				for(j=i-d; j>=0 && t>a[j]; j-=d) { //找
					a[j+d] = a[j]; //挪
				}
				a[j+d]=t; //插
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
