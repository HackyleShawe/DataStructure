package b_selection;

import java.util.Arrays;
import java.util.Random;

/**
 * 选择排序
 */
public class SelectSort {

    /**
     * 每一回找到最小的数，与第i++位置处的数交换
     */
    public static void selectSort(Comparable[] arr) {
        for (int i = 0; i < arr.length; i++) {
            int min = i; //最小数的下标
            for (int j = i+1; j < arr.length; j++) {
                if(smaller(arr, j, min)) {
                    min = j;
                }
            }
            //还有更小的数
            if(min != i) {
                exchange(arr,i,min);
            }
        }
    }


    public static boolean smaller(Comparable[] arr, int i, int j) {
        return arr[i].compareTo(arr[j]) < 0;
    }

    public static void exchange(Comparable[] arr, int i, int j) {
        Comparable tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}



/**
 * 测试：选择排序
 */
class SelectSortTest {
    public static void main(String[] args) {
        Random random = new Random();
        int len = Math.abs(random.nextInt(15));
        Integer[] arr01 = new Integer[len];
        Double[] arr02 = new Double[len];
        for (int i = 0; i < len; i++) {
            arr01[i] = random.nextInt(1000);
            arr02[i] = random.nextDouble()*1000;
        }

        SelectSort.selectSort(arr01);
        System.out.println(Arrays.toString(arr01));

        System.out.println();
        SelectSort.selectSort(arr02);
        System.out.println(Arrays.toString(arr02));
    }
}