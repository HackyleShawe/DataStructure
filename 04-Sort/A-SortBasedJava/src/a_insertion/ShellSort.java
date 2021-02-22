package a_insertion;

import java.util.Arrays;
import java.util.Random;

public class ShellSort {
    /**
     * 插入排序：把第i++个元素插入到前面i++个已经排好序了的数中
     */
    public static void shellSort(Comparable[] a) {
        //增量的规则由自己确定，可以直接取长度的一半；这里采用这种方式确定增量
        int d = 1;
        while(d < a.length/2) {
            d = 2*d+1;
        }

        while(d>=1) {
            for(int i=d; i<a.length; i++) {
                for(int j=i; j>=d; j-=d) {
                    if(greater(a[j-d],a[j])) {
                        exchange(a,j-d, j);
                    } else {
                        break;
                    }
                }
            }
            d = d/2;
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


class ShellSortTest {
    public static void main(String[] args) throws Exception {
        Random random = new Random();
        int len = Math.abs(random.nextInt()%100);
        Integer[] arr = new Integer[len];
        for(int i=0; i<len; i++) {
            arr[i] = random.nextInt()%100; //构造随机数组
        }
        System.out.println(Arrays.toString(arr));

        ShellSort.shellSort(arr);
        System.out.println(Arrays.toString(arr));
    }

}