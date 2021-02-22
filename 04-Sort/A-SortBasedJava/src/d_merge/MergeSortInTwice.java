package d_merge;

import java.util.Arrays;
import java.util.Random;

public class MergeSortInTwice {
    private static Comparable[] assist; //辅助数组

    public static void mergeSort(Comparable[] a) {
        assist = new Comparable[a.length];
        int low = 0;
        int high = a.length - 1;
        division(a, low, high);
    }

    /**
     * 分
     */
    public static void division(Comparable[] a, int low, int high) {
        if(low>=high) { //递归出口
            return;
        }

        int mid = low + (high - low)/2;
        division(a, low, mid);
        division(a,mid+1, high);
        merge(a, low, mid, high);
    }

    /**
     * 合
     */
    public static void merge(Comparable[] a, int low, int mid, int high) {
        int i = low;
        int p1=low, p2=mid+1;

        while(p1<=mid && p2<=high) {
            if(smaller(a[p1],a[p2])) {
                assist[i++] = a[p1++];
            } else {
                assist[i++] = a[p2++];
            }
        }

        while(p1<=mid) {
            assist[i++] = a[p1++];
        }
        while(p2<=high) {
            assist[i++] = a[p2++];
        }

        //把辅助数组的元素拷贝回原数组
        for(int k=low; k<=high; k++) {
            a[k] = assist[k];
        }
    }

    private static boolean smaller(Comparable a, Comparable b) {
        return a.compareTo(b) < 0;
    }

}

class MergeSortInTwiceTest {
    public static void main(String[] args) throws Exception {
        Random random = new Random();
        int len = Math.abs(random.nextInt()%10);
        Integer[] arr = new Integer[len];
        for(int i=0; i<len; i++) {
            arr[i] = random.nextInt()%100; //构造随机数组
        }
        System.out.println(Arrays.toString(arr));

        MergeSortInTwice.mergeSort(arr);
        System.out.println(Arrays.toString(arr));
    }

}