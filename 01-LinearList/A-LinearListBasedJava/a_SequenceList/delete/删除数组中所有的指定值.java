import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Random;

public class ArrayOperate {
    /**
     * 功能：删除arr中的所有val
     * 算法：
     *  从头开始的双下标思想：设定：i遍历数组，k为符合条件的数组下标；
     *  当元素不等于指定值时，将下标i的值赋值给下标k
     */
    public static int[] delValue(int[] arr, int val) {
        if(arr.length < 1) {
            throw new RuntimeException("数组为空！");
        }

        int k = 0;
        for (int i = 0; i < arr.length; i++) {
            if(arr[i] != val) {
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
    public void testDelValue() {
        int lenBound = 100;
        int elementBound = 500;
        Random random = new Random();
        int len = random.nextInt(lenBound);
        int[] arr = genRandomArr(len, elementBound);

        int randIndex = random.nextInt(len);
        int randVal = arr[randIndex];

        System.out.println("randVal: " + randVal);
        System.out.println("del before: " + Arrays.toString(arr) + "; length: " + arr.length);
        int[] resultArr = ArrayOperate.delValue(arr, randVal);
        System.out.println("del after: " + Arrays.toString(resultArr)  + "; length: " + resultArr.length);
    }
}
