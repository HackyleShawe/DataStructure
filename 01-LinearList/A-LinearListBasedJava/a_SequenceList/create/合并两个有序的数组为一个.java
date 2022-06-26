
import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Random;

public class ArrayOperate {
    /**
     * 函数功能：合并两个有序数组
     * 算法：
     *  1.同时遍历两个有序数组，将符合条件的下标前进，不符合条件的下标不动；
     *  2.看那个数组还有剩余，将剩余的依次顺序加入到新的数组即可；
     */
    public static int[] mergeOrderedArray(int[] arr, int[] brr) {
        int alen = arr.length;
        int blen = brr.length;

        int[] resultArr = new int[alen + blen];

        int i = 0, j = 0, k = 0;
        while(i < alen && j < blen) {
            if(arr[i] > brr[j]) {
                resultArr[k++] = brr[j];
                j++;
            } else {
                resultArr[k++] = arr[i];
                i++;
            }
        }

        while(i<alen) {
            resultArr[k++] = arr[i++];
        }
        while(j<blen) {
            resultArr[k++] = brr[j++];
        }

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
            arr[i] = ranVal;
        }
        return arr;
    }

    @Test
    public void testPartInterchange() {
        int lenBound = 10;
        int elementBound = 500;
        Random random = new Random();
        int alen = random.nextInt(lenBound);
        int blen = random.nextInt(lenBound);

        int[] arr = genRandomArr(alen, elementBound);
        int[] brr = genRandomArr(blen, elementBound);

        Arrays.sort(arr);
        Arrays.sort(brr);

        System.out.println("arr: " + Arrays.toString(arr) + "; length: " + arr.length);
        System.out.println("brr: " + Arrays.toString(brr) + "; length: " + brr.length);

        int[] orderedArray = ArrayOperate.mergeOrderedArray(arr, brr);
        System.out.println("orderedArray: " + Arrays.toString(orderedArray)  + "; length: " + orderedArray.length);
    }
}