
import java.util.Random;

import org.junit.Test;

public class SelectSort {

	private int n = 10;
	
	public void getArray(int[] a) {
		Random r = new Random();
		for(int i=0; i<n; i++) {
			a[i] = r.nextInt(1000);
		}
		showArray(a);
	}
	public void showArray(int[] a) {
		for(int i:a) {
			System.out.print(i + " ");
		}
		System.out.println();
	}
	
	@Test
	public void testSelectSort() {
		int[] a = new int[n];
		getArray(a);
		
		for(int i=0;i<n;i++) {
			int min = i; //最小值的位置
			int j=i+1;
			for(; j<n; j++) { //找
				if(a[min] > a[j]) { //找到更小的
					min = j;
				}
			}
			if(min!=i) { //交换
				int t = a[min];
				a[min] = a[i];
				a[i] = t;
			}
		}
		
		showArray(a);
	}
}
