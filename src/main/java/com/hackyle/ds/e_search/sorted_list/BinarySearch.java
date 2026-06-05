package sortedList;

import java.util.Arrays;
import java.util.Random;

/**
 * 二分查找法
 */
public class BinarySearch {

    /**
     * <p>Function: 朴素的二分查找法</p>
     * <p>Algorithm: 取arr的中部元素M，key大于M的在其右边继续查找，小于M的在其左边继续查找。直到找到或走完了顺序表</p>
     * @param arr 被查找的有序顺序表
     * @param key 待查找的值
     * @return 查找结果，key的下标，没有找到则返回-1
     */
    public static int binarySearchByPlain(int[] arr, int key) {
        //入参校验
        if(arr == null || arr.length == 0) {
            System.out.println("记录日志：入参为空");
            throw new RuntimeException("binarySearchByPlain入参为空");
        }

        int left = 0;
        int right = arr.length - 1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(arr[mid] < key) {
                //在右边继续二分查找
                left = mid + 1;
            } else if(arr[mid] > key){
                //在左边继续二分查找
                right = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }

}


/**
 * 测试：二分查找法
 */
class BinarySearchTest {

    public static void main(String[] args) {
        testBinarySearchByPlain();
    }

    /**
     * 测试：binarySearchByPlain
     */
    public static void testBinarySearchByPlain() {
        Random random = new Random();
        int len = random.nextInt(100 - 10 + 1) +10;
        int[] arr = new int[len];
        for (int i = 0; i < len; i++) {
            arr[i] = random.nextInt(200);
        }
        int key = random.nextInt(200);

        Arrays.sort(arr);
        System.out.println(Arrays.toString(arr));
        System.out.println(key);

        int result = BinarySearch.binarySearchByPlain(arr, key);
        System.out.println(result == -1 ? "没有找到":"找到了，所在位置："+result);
    }
}