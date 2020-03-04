
import java.util.Random;

import org.junit.Test;

public class A01_InsertSort {
	private int n = 10;
	
	/**
	 * 二分法插入排序
	 * 
	 * 算法：
	 * 	在直接插入排序的基础上，“找”的这一步骤，换成了二分查找；
	 * 	其他不变；
	 */
	@Test
	public void shellInsertSort() {
		int[] a = getRandomArray();
		showArray(a);
		
		for(int i=1; i<a.length; i++) { //从第二个数开始，第一个数总是已经排好序了的
			int temp = a[i];
			int left=0;
			int right=i-1;
			
			while(left<right) { //找
				int mid = (left+right)/2;
				if(temp>a[mid]) {
					left = mid+1;
				} else {
					right = mid-1;
				}
			}
			
			for(int j=i-1; j>right; j--) { //挪
				a[j+1] = a[j];
			}
			a[left]=temp; //插
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
