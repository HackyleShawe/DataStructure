package a_insertion;

import java.util.Arrays;
import java.util.Random;

/**
 * 直接插入排序
 */
public class InsertSort {
    /**
     * 插入排序：把第i++个元素插入到前面i++个已经排好序了的数中
     */
    public static void insertSort(Comparable[] a) {
        for(int i=1; i<a.length; i++) {
            for(int j=i; j>0; j--) {
                if(greater(a[j-1],a[j])) { //从j开始，依次向前满足条件互相交换
                    exchange(a,j-1,j);
                } else {
                    break;
                }
            }
        }
    }

    public static boolean greater(Comparable a, Comparable b) {
        return a.compareTo(b) > 0;
    }
    public static void exchange(Comparable[] a, int i, int j) {
        Comparable t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
}

class InsertSortTest {
    public static void main(String[] args) throws Exception {
        Random random = new Random();
        int len = Math.abs(random.nextInt()%100);
        Integer[] arr = new Integer[len];
        for(int i=0; i<len; i++) {
            arr[i] = random.nextInt()%100; //构造随机数组
        }
        System.out.println(Arrays.toString(arr));

        InsertSort.insertSort(arr);
        System.out.println(Arrays.toString(arr));
    }

}