package c_CompleteBinTree;

import java.util.Arrays;
import java.util.Objects;

public class Heap {
    private  boolean less(Comparable[] heap, int i, int j) {
        return heap[i].compareTo(heap[j])<0;
    }
    private  void exchange(Comparable[] heap, int i, int j) {
        Comparable tmp = heap[i];
        heap[i] = heap[j];
        heap[j] = tmp;
    }

    /**
     * 根据原始无序数组创建一个大顶堆
     * @param source 原始数组（无序）
     * @param heap 堆(有序)
     */
    public  void createBigHeap(Comparable[] source, Comparable[] heap) {
        //把source中的元素拷贝到heap中，heap中的元素就形成一个无序的堆
        System.arraycopy(source,0,heap,1,source.length);

        //对堆中的元素做下沉调整(从长度的一半处开始，往索引1处扫描，到1处停止)
        for (int i = (heap.length)/2;i>0;i--){
            sink(heap,i,heap.length-1);
        }
    }

    /**
     * 功能：在heap堆中，对target处的元素做下沉，范围是0~range
     * 算法：
     *  1.找出当前节点与其子节点的较大的子节点
     *  2.比较当前节点的值与较大子节点的值
     *  3.符合条件则交换
     * @param heap 堆
     * @param target 想要对谁进行下沉操作
     * @param range 下沉的范围
     */
    private  void sink(Comparable[] heap, int target, int range) {
        while(2*target<=range) {
            //1.找出当前结点的较大的子结点
            int max;
            if (2 * target + 1 <= range) { //target节点如果还有子节点
                if (less(heap, 2 * target, 2 * target + 1)) { //比较target节点的左右节点
                    max = 2 * target + 1;
                } else {
                    max = 2 * target;
                }
            } else { //target节点只有左子节点
                max = 2 * target;
            }

            //2.比较当前结点的值和较大子结点的值
            if (!less(heap, target, max)) {
                break;
            }

            exchange(heap,target,max); //如果符合条件，则交换
            target = max;
        }
    }

    /**
     * 将无序数组构造成小顶堆
     * @param source 原无序数组
     */
    public  void littleHeap(Comparable[] source) {
        Comparable[] littleHeapSort = new Comparable[source.length+1];
        createBigHeap(source,littleHeapSort);

        int k = littleHeapSort.length-1; //记录未排序元素中的最大索引
        while(k!=1) { //通过循环，交换1索引处的元素和排序的元素中最大的索引处的元素
            exchange(littleHeapSort,1,k);
            k--;
            sink(littleHeapSort,1,k);
        }

        //把heap中的数据复制到原数组source中
        System.arraycopy(littleHeapSort,1,source,0,source.length);
    }
}

class HeapTest {
    public static void main(String[] args) {
        Integer[] sourceArray = {10,23,99,33,13,44,11,64,68,76};
        Integer[] heapSortArray = new Integer[sourceArray.length+1]; //注意：堆排序的数组不使用下标0
        Heap heap = new Heap();
        heap.createBigHeap(sourceArray,heapSortArray);

        System.out.println("排序前：");
        Arrays.stream(sourceArray).forEach(e -> System.out.print(e+" "));

        System.out.println();
        System.out.println("大顶堆排序后：");
        //Arrays.stream(heapSortArray).filter(integer -> integer!=null).forEach(e -> System.out.print(e+" "));
        Arrays.stream(heapSortArray).filter(Objects::nonNull).forEach(e -> System.out.print(e+" ")); //IDEA代码优化

        System.out.println();
        System.out.println("转换为小顶堆：");
        heap.littleHeap(sourceArray);
        Arrays.stream(sourceArray).forEach(e-> System.out.print(e+" "));

        //输出：
        //排序前：
        //10 23 99 33 13 44 11 64 68 76
        //大顶堆排序后：
        //99 76 44 68 23 10 11 64 33 13
        //转换为小顶堆：
        //10 11 13 23 33 44 64 68 76 99
    }
}