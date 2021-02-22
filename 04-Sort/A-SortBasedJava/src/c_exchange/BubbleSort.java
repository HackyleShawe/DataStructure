package c_exchange;

import java.util.Arrays;

public class BubbleSort {
    /**
     * 进行N-1回，每回把最大/小的速往前/后沉
     */
    public static void bubbleSort(Comparable[] arr) {
        for(int i=0; i<arr.length; i++) {
            for(int j=i; j<arr.length; j++) {
                if(greater(arr[i], arr[j])) {
                    exchange(arr, i, j);
                }
            }
        }
    }

    /**
     * 比较a是否大于b
     */
    private static boolean greater(Comparable a, Comparable b) {
        return a.compareTo(b) > 0;
    }

    /**
     * 交换数组arr中的i、j位置上的值
     */
    private static void exchange(Comparable[] arr, int i, int j) {
        Comparable t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }

}


class BubbleSortTest {
    public static void main(String[] args) throws Exception {
        Integer[] arr = {9,8,2,5,8,7,11};
        System.out.println(Arrays.toString(arr));
        BubbleSort.bubbleSort(arr);
        System.out.println(Arrays.toString(arr));
    }

}