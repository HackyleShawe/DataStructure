
import java.util.Random;
import org.junit.Test;


public class InsertSort {
	private int n = 10;
	
	/**
	 * 直接插入排序
	 */
	@Test
	public void testInsertSort() {
		int[] a = new int[n];
		getArray(a,n);
		
		for(int i=0; i<n; i++) {
			int t = a[i];
			int j = 0;
			for(j=i-1; j>=0 && t<a[j]; j--) { //找
				a[j+1] = a[j]; //挪
			}
			a[j+1] = t; //插入
		}
		
		showArray(a,n);
	}

	
	public void getArray(int[] a, int n) {
		Random r = new Random();
		for(int i=0; i<n; i++) {
			a[i] = r.nextInt(1000);
		}
		showArray(a,n);
	}
	public void showArray(int[] a, int n) {
		for(int i=0; i<n; i++) {
			System.out.print(a[i] + " ");
		}
		System.out.println();
	}
}
