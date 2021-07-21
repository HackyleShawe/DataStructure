package c_exchange;

import java.util.Arrays;
import java.util.Random;

/**
 * 快速排序
 */
public class QuickSort {
    public static void quickSort(Comparable[] a) {
        int low = 0;
        int high = a.length - 1;
        quickSort(a, low, high);
    }

    public static void quickSort(Comparable[] a, int low, int high) {
        if(low>=high) {
            return;
        }

        int pivot = partition(a, low, high);
        quickSort(a, low, pivot-1); //让枢轴值的左边有序
        quickSort(a, pivot+1, high); //让枢轴值的右边有序
    }

    /**
     * 以枢轴(pivot)值进行分区操作
     * @param a 待排序的数组
     * @param left 此次Partition的开始位置
     * @param right 此次Partition的结束位置
     * @return 返回枢轴值的下标
     */
    public static int partition(Comparable[] a, int left, int right) {
        int pivot = left; //分区的基准值

        while(left<right) {
            while(left<right && greater(a[pivot], a[left])) { //从左向右找首个小于枢轴值
                left++; //循环完毕，则找到首个小于枢轴值元素的下标为：left
            }
            exchange(a,pivot,left); //交换枢轴值与该值

            while(right>left && greater(a[right],a[pivot]) ) { //从右向左找首个大于枢轴值
                right--;//循环完毕，则找到首个大于枢轴值元素的下标为：right
            }
            exchange(a,pivot,right);
        }
        return left; //返回枢轴值的下标
    }

    private static boolean greater(Comparable a, Comparable b) {
        return a.compareTo(b) > 0;
    }

    public static void exchange(Comparable[] a, int i, int j) {
        Comparable t = a[i];
        a[i] = a[j];
        a[j] = t;
    }

}


/**
 * 测试：快速排序
 */
class QuickSortTest {
    public static void main(String[] args) throws Exception {
        Random random = new Random();
        int len = Math.abs(random.nextInt()%20);
        Integer[] arr = new Integer[len];
        for(int i=0; i<len; i++) {
            arr[i] = random.nextInt()%100; //构造随机数组
        }
        System.out.println(Arrays.toString(arr));

        QuickSort.quickSort(arr);
        System.out.println(Arrays.toString(arr));
    }

}