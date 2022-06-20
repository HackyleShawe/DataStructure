import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Random;

public class ArrayOperate {
    /**
     * 功能：删除有序表中元素值在区间[X]内的元素
     * 算法：
     *  双下标思想
     *  遍历数组，找到最后一个小于X的下标为k
     *  继续遍历，从第一个大于Y的下标i开始，a[k++] = a[i]
     */
    public static int[] delOrderedByBound(int[] arr, int start, int end) {
        if(arr.length < 1) {
            throw new RuntimeException("数组为空！");
        }
        if(start > end) {
            throw new RuntimeException("元素值的区间不合法: start="+start+";end="+end);
        }

        int k = 0;
        for (int i = 0; i < arr.length; i++) {
            //找到最后一个小于X的下标为k
            if(arr[i] >= start && k == 0) { //这里的设计绝妙，当k一旦被赋过值，则不能再进入此if体
                k = i;
            }
            //从第一个大于Y的下标i开始，arr[k++] = arr[i]
            if(arr[i] >= end) {
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
    public void testDelOrderedByBound() {
        int lenBound = 100;
        int elementBound = 500;
        Random random = new Random();
        int len = random.nextInt(lenBound);
        int[] arr = genRandomArr(len, elementBound);
        Arrays.sort(arr);

        int start = random.nextInt(elementBound);
        int end = start + 100;

        System.out.println("start=" + start + "; end=" + end);
        System.out.println("del before: " + Arrays.toString(arr) + "; length: " + arr.length);
        int[] resultArr = ArrayOperate.delOrderedByBound(arr, start, end);
        System.out.println("del after: " + Arrays.toString(resultArr)  + "; length: " + resultArr.length);
    }
}
