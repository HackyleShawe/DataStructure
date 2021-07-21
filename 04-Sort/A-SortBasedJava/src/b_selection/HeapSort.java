package b_selection;

import java.util.Arrays;
import java.util.Random;

/**
 * <p>堆排序</p>
 */
public class HeapSort {
    /**
     * <p>升序排序：</p>
     * <ol>
     * <li>构造小顶堆；</li>
     * <li>将堆顶元素与堆尾元素交换；</li>
     * <li>将堆尾元素从堆中移除、输出，最终输出的就是升序数组</li>
     * <li>从堆顶元素开始执行上浮操作；</li>
     * </ol>
     */
    public static void ascendingHeapSort(Comparable[] sourceArr) {
        //入参校验
        if(sourceArr == null || sourceArr.length == 0) {
            System.out.println("记录日志：入参为空");
            return;
        }

        //辅助空间：保存堆
        Comparable[] heapArr = new Comparable[sourceArr.length+1];
        //将数据复制到保存堆的数组中。注意堆数组是从下标1开始存储数据的
        System.arraycopy(sourceArr, 0, heapArr, 1, sourceArr.length);

        int index = 0;

        //1.构建小顶堆
        createLittleHeap(heapArr);

        int range = heapArr.length-1;
        while(range >= 1) {
            //2.将堆顶元素与堆尾元素交换；
            swap(heapArr,1, range);
            //3.将堆头元素从堆中移除、输出，最终输出的就是升序数组
            //System.out.print(heapArr[count] + "  ");
            sourceArr[index++] = heapArr[range];
            //4.从堆尾元素开始执行下沉操作
            sink4Min(heapArr,1, --range);
        }

    }

    /**
     * 创建小顶堆
     * @param heapArr 将heapArr变为小顶堆数组
     */
    private static void createLittleHeap(Comparable[] heapArr) {
        //1.从数组的一半处（记为k）开始向数组头方向遍历
        for (int i = heapArr.length/2; i > 0; i--){
            //2.选择k节点和其左右子节点较小的放在k位置，直到k到数组头（堆顶）
            sink4Min(heapArr, i, heapArr.length-1);
        }
    }

    /**
     * <p>Function: 在heap堆中，选择target节点和其左右子节点中最小的值放在target位置，
     *              target的左右子节点范围为[1,range]</p>
     * <p>Algorithm：</p>
     *  <ol>
     *  <li>找出当前节点与其子节点的较小的子节点</li>
     *  <li>比较当前节点的值与较小子节点的值</li>
     *  <li>符合条件则交换</li>
     *  </ol>
     * @param target 想要对谁进行下沉操作
     * @param range 限制target的左右子节点的范围：[1,range]
     */
    private static void sink4Min(Comparable[] heapArr, int target, int range) {
        while(2*target <= range) {
            //1.找出当前结点的较大的子结点
            int min;
            if (2 * target + 1 <= range) { //target节点如果还有子节点
                if (smaller(heapArr, 2 * target, 2 * target + 1)) { //比较target节点的左右节点
                    min = 2 * target;
                } else {
                    min = 2 * target + 1;
                }
            } else { //target节点只有左子节点
                min = 2 * target;
            }

            //2.比较当前结点的值和较大子结点的值
            if (smaller(heapArr, target, min)) { //target已经较小，不需要交换
                break;
            }

            swap(heapArr, min, target); //如果符合条件，则交换
            target = min;
        }
    }


    /**
     * <p>降序排序：</p>
     * <ol>
     * <li>构造大顶堆；</li>
     * <li>将堆顶元素与堆尾元素交换；</li>
     * <li>将堆尾元素从堆中移除、输出，最终输出的就是降序数组</li>
     * <li>从堆顶元素开始执行<b>下沉</b>操作；</li>
     * </ol>
     */
    public static void descendingHeapSort(Comparable[] sourceArr) {
        //入参校验
        if(sourceArr == null || sourceArr.length == 0) {
            System.out.println("记录日志：入参为空");
            return;
        }

        //辅助空间：保存堆
        Comparable[] heapArr = new Comparable[sourceArr.length+1];
        //将数据复制到保存堆的数组中。注意堆数组是从下标1开始存储数据的
        System.arraycopy(sourceArr, 0, heapArr, 1, sourceArr.length);

        int index = 0;

        //1.构建大顶堆
        createBigHeap(heapArr);

        int range = heapArr.length-1;
        while(range >= 1) {
            //2.将堆顶元素与堆尾元素交换；
            swap(heapArr,1, range);
            //3.将堆尾元素从堆中移除、输出，最终输出的就是降序数组
            //System.out.print(heapArr[count] + "  ");
            sourceArr[index++] = heapArr[range];
            //4.从堆顶元素开始执行下沉操作：
            sink4Max(heapArr,1, --range);
        }

    }

    /**
     * 创建大顶堆
     * @param heapArr 将heapArr变为大顶堆数组
     */
    private static void createBigHeap(Comparable[] heapArr) {
        //根据完全二叉树，从倒数第二层有子节点的的节点开始，向前遍历，进行下沉操作
        for (int i = heapArr.length/2; i > 0; i--) {
            sink4Max(heapArr, i, heapArr.length-1);
        }
    }

    /**
     * <p>Function: 在heap堆中，选择target节点和其左右子节点中最大的值放在target位置，
     *              target的左右子节点范围为[1,range]</p>
     * <p>Algorithm：</p>
     * <ol>
     * <li>找出当前节点与其子节点的较大的子节点</li>
     * <li>比较当前节点的值与较大子节点的值</li>
     * <li>符合条件则交换</li>
     * </ol>
     * @param heapArr 堆数组
     * @param target 想要对谁进行下沉操作
     * @param range 限制target的左右子节点的范围：[1,range]
     */
    private static void sink4Max(Comparable[] heapArr, int target, int range) {
        while(2*target <= range) {
            //1.找出当前结点的较大的子结点
            int max;
            if (2 * target + 1 <= range) { //target节点如果还有子节点
                if (greater(heapArr, 2 * target, 2 * target + 1)) { //比较target节点的左右节点
                    max = 2 * target;
                } else {
                    max = 2 * target + 1;
                }
            } else { //target节点只有左子节点
                max = 2 * target;
            }

            //2.比较当前结点的值和较大子结点的值
            if (greater(heapArr, target, max)) { //target已经是较大的，不交换
                break;
            }

            swap(heapArr, max, target); //符合条件，则交换
            target = max;
        }
    }

    /**
     * 在arr数组中，如果i位置的数比j位置的数更小，则返回true
     */
    private static boolean smaller(Comparable[] arr, int i, int j) {
        return arr[i].compareTo(arr[j]) < 0;
    }

    /**
     * 在arr数组中，如果i位置的数比j位置的数更大，则返回true
     */
    private static boolean greater(Comparable[] arr, int i, int j) {
        return arr[i].compareTo(arr[j]) > 0;
    }

    /**
     * 交换arr数组中的，i、j位置上的数
     */
    private static void swap(Comparable[] arr, int i, int j) {
        Comparable tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}


/**
 * 测试：堆排序
 */
class HeapSortTest {
    public static void main(String[] args) {
        Random random = new Random();
        int length = Math.abs(random.nextInt(15));
        Integer[] arr01 = new Integer[length];
        Double[] arr02 = new Double[length];

        for (int i = 0; i < length; i++) {
            arr01[i] = random.nextInt(100);
            arr02[i] = random.nextDouble()*1000;
        }


        System.out.println("升序（小顶堆）:");
        System.out.println("Before: " + Arrays.toString(arr01));
        HeapSort.ascendingHeapSort(arr01);
        System.out.println("After: " + Arrays.toString(arr01));

        System.out.println("降序（大顶堆）");
        System.out.println("Before: " + Arrays.toString(arr01));
        HeapSort.descendingHeapSort(arr01);
        System.out.println("After: " + Arrays.toString(arr01));

        System.out.println("升序（小顶堆）:");
        System.out.println("Before: " + Arrays.toString(arr02));
        HeapSort.ascendingHeapSort(arr02);
        System.out.println("After: " + Arrays.toString(arr02));

        System.out.println("降序（大顶堆）");
        System.out.println("Before: " + Arrays.toString(arr02));
        HeapSort.descendingHeapSort(arr02);
        System.out.println("After: " + Arrays.toString(arr02));
    }
}