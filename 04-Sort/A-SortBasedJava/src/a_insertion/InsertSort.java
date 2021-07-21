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


/**
 * 测试：插入排序
 */
class InsertSortTest {
    public static void main(String[] args) {
        Random random = new Random();
        int len = Math.abs(random.nextInt()%15);
        Integer[] arr01 = new Integer[len];
        Double[] arr02 = new Double[len];
        for(int i=0; i<len; i++) {
            arr01[i] = random.nextInt()%100; //构造随机数组
            arr02[i] = random.nextDouble()*1000;
        }
        System.out.println("Int型数组：");
        System.out.println(Arrays.toString(arr01));
        InsertSort.insertSort(arr01);
        System.out.println(Arrays.toString(arr01));

        System.out.println("Double型数组：");
        System.out.println(Arrays.toString(arr02));
        InsertSort.insertSort(arr02);
        System.out.println(Arrays.toString(arr02));
    }

}