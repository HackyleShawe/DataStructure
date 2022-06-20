import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Random;

public class ArrayOperate {
    /**
     * 功能：删除无序表arr中元素值在区间[start, end]内的元素
     * 算法：
     *  双下标思想。设定：i遍历数组，k为符合条件的数组下标
     *  当Arr[i]不等于区间[X, Y]内的元素时，将下标i的值赋值给下标k
     */
    public static int[] delByBound(int[] arr, int start, int end) {
        if(arr.length < 1) {
            throw new RuntimeException("数组为空！");
        }
        if(start > end) {
            throw new RuntimeException("元素值的区间不合法: start="+start+";end="+end);
        }

        int k = 0;
        for (int i = 0; i < arr.length; i++) {
            if(start > arr[i] || arr[i] > end) {
                arr[k++] = arr[i];
            }
        }

        int[] resultArr = new int[k];
        if (k >= 0) System.arraycopy(arr, 0, resultArr, 0, k);

        return resultArr;
    }

}

class ArrayOperateTest {
    public int[] genRandomArr(int len, int bound) {
        len = len < 1 ? 10 : len;
        int[] arr = new int[len];
        Random random = new Random();
        for (int i = 0; i < len; i++) {
            arr[i] = random.nextInt(bound);
        }
        return arr;
    }
    @Test
    public void testDelByBound() {
        int lenBound = 100;
        int elementBound = 500;
        Random random = new Random();
        int len = random.nextInt(lenBound);
        int[] arr = genRandomArr(len, elementBound);

        int start = random.nextInt(elementBound);
        int end = start + 100;

        System.out.println("start=" + start + "; end=" + end);
        System.out.println("del before: " + Arrays.toString(arr) + "; length: " + arr.length);
        int[] resultArr = ArrayOperate.delByBound(arr, start, end);
        System.out.println("del after: " + Arrays.toString(resultArr)  + "; length: " + resultArr.length);
    }
}
