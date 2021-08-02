package unsortedLinear;

import java.util.Arrays;
import java.util.Random;

/**
 * 无序的线性表查找
 */
public class SequenceListSearch {

    /**
     * <p>Function: 正向查找线性表查找的朴素算法</p>
     * @param arr 待查找的线性表
     * @param key 关键字
     * @return key在arr中的位置下标，返回-1则表示没有找到
     */
    public static int searchingByForward(int[] arr, int key) {
        //入参校验
        if(arr == null || arr.length == 0) {
            System.out.println("记录日志：入参为空");
            throw new RuntimeException("searchingByForward入参为空");
        }

        for (int i = 0; i < arr.length; i++) {
            if(arr[i] == key) {
                return i;
            }
        }
        return -1;
    }

    /**
     * <p>Function: 逆向查找线性表查找朴素算法的优化</p>
     * <p>Algorithm: 优化for循环中的多次比较</p>
     * <ol>
     *     <li>将线性表中的第一个元素作为哨兵，即不存放具体的元素，而作为辅助元素</li>
     *     <li>将待查找的元素key赋值给哨兵元素</li>
     *     <li>逆向遍历线性表，当key等于arr[i]时停止。如果遍历到头部(哨兵处)，则说明没有查找到</li>
     * </ol>
     * @param arr 线性表
     * @param key 待查找的数
     * @return key在arr中的位置下标，返回0则表示没有找到，注意下标为0的是哨兵所在位置
     */
    public static int searchingByBackward(int[] arr, int key) {
        int i = arr.length - 1;
        arr[0] = key; //哨兵元素
        while(arr[i] != key) {
            i--;
        }

        return i;
    }

}


/**
 * 测试：线性表查找
 */
class SequenceListSearchTest {
    public static void main(String[] args) {
        Random random = new Random();
        int len = random.nextInt(100 - 10 + 1) + 10; //生成[10,100]内的随机数
        int[] arr = new int[len];
        for (int i = 0; i < len; i++) {
            arr[i] = random.nextInt(100);
        }
        int key =  random.nextInt(100);

        System.out.println(Arrays.toString(arr));
        System.out.println(key);

        int result01 = SequenceListSearch.searchingByForward(arr, key);
        System.out.println(result01 == -1 ? "没有找到" : "正向查找成功！所在位置："+result01);

        int result02 = SequenceListSearch.searchingByBackward(arr, key);
        System.out.println(result02 == 0 ? "没有找到" : "逆向查找成功！所在位置："+result02);
    }
}
