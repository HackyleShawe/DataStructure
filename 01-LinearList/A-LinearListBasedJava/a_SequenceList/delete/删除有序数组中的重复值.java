import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Random;

public class ArrayOperate {
    /**
     * 功能：删除有序表中的重复值
     * 分析：值相同的元素一定在连续的位置上
     * 算法：
     * - 遍历时，判断当前元素a[i](i>=1)与前一个元素a[i-1]是否相同
     * - 如果相同，则continue。这一步就跳过了那些相同的元素
     * - 如果不相同，则a[k++] = a[i], k>=1
     */
    public static int[] delOrdered2RepeatValue(int[] arr) {
        if(arr.length < 1) {
            throw new RuntimeException("数组为空！");
        }

        int k = 1;
        for (int i = 1; i < arr.length; i++) {
            if(arr[i] != arr[i-1]) { //如果arr[i] == arr[i-1]，则跳过了那些相同的数
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
            int ranVal = random.nextInt(bound);

            //构造相同的数
            int repeatCounter = random.nextInt(10);
            for (int j = 0; j < repeatCounter; j++) {
                arr[i] = ranVal;
            }
        }
        return arr;
    }

    @Test
    public void testDelOrdered2RepeatValue() {
        int lenBound = 100;
        int elementBound = 500;
        Random random = new Random();
        int len = random.nextInt(lenBound);
        int[] arr = genRandomArr(len, elementBound);
        Arrays.sort(arr);

        System.out.println("del before: " + Arrays.toString(arr) + "; length: " + arr.length);
        int[] resultArr = ArrayOperate.delOrdered2RepeatValue(arr);
        System.out.println("del after: " + Arrays.toString(resultArr)  + "; length: " + resultArr.length);
    }
}
