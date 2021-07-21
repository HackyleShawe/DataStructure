package a_insertion;

import java.util.Arrays;
import java.util.Random;

/**
 * Shell插入排序
 */
public class ShellSort {
    /**
     * <p>以间隔d，进行插入排序</p>
     * <p>插入排序：把第i++个元素插入到前面i++个已经排好序了的数中</p>
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


/**
 * 测试：Shell排序
 */
class ShellSortTest {
    public static void main(String[] args) {
        Random random = new Random();
        int len = Math.abs(random.nextInt()%15);
        Integer[] arr01 = new Integer[len];
        Double[] arr02 = new Double[len];

        for(int i=0; i<len; i++) {
            arr01[i] = random.nextInt()%100; //构造随机数组
            arr02[i] = random.nextDouble()*1000;
        }
        System.out.println(Arrays.toString(arr01));
        ShellSort.shellSort(arr01);
        System.out.println(Arrays.toString(arr01));

        System.out.println();
        System.out.println(Arrays.toString(arr02));
        ShellSort.shellSort(arr02);
        System.out.println(Arrays.toString(arr02));
    }
}