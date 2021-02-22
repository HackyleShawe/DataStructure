package c_CompleteBinTree;

import java.util.Arrays;
import java.util.Objects;

public class HeapCRUD<T extends Comparable<T>> {
    private T[] items; //堆的底层存储结构：数组
    private int N; //堆元素的个数

    public HeapCRUD(int capacity) {
        this.items = (T[]) new Comparable[capacity+1]; //为什么要+1？因为堆排序中第一个元素(下标为0)是不使用的。
        this.N = 0;
    }
    public HeapCRUD(T[] source, int capacity) {
        //this.items = (T[]) new Comparable[capacity+1];
        this.items = Arrays.copyOf(source,capacity+1);
        this.N = source.length-1;
    }

    /**
     * i处的值比j处的值小，则返回true
     * @param i 值1
     * @param j 值2
     * @return i处的值更小，则为true
     */
    private boolean less(int i, int j) {
        return items[i].compareTo(items[j])<0;
    }

    /**
     * 交换数组中i和j处的值，实际上是交换二叉树中直接子节点和直接父节点的值
     * @param i 父节点
     * @param j 子节点
     */
    private void exchange(int i,int j) {
        T temp = items[i];
        items[i] = items[j];
        items[j] = temp;
    }

    /**
     * 插入元素
     * @param t 插入元素的值
     */
    public void insert(T t) {
        items[++N] = t;
        swim(N); //上浮算法，使得插入的元素能够构成大/小顶堆
    }
    /**
     * 功能：上浮调整
     * 算法：不断比较交换当前节点与其直接父节点的值
     * @param k 使用上浮算法，使索引k处的元素能在堆中处于一个正确的位置
     */
    private void swim(int k) {
        //不断比较当前节点与其直接父节点的值，进行交换
        while(k>1) {
            if(less(k/2,k)) {
                exchange(k/2,k);
            }
            k = k/2;
        }
    }

    /**
     * 功能：大顶堆删除最大值，并返回
     * 算法：
     *  1.交换完全二叉树最后一个节点与第一个节点的值
     *  2.删除最后一个节点
     *  3.将数组长度减一
     *  4.进行下沉调整
     */
    public T deleteMax() {
        T max = items[1]; //大顶堆中的最大值
        exchange(1,N); //交换第一个节点与最后一个节点
        items[N] = null; //删除最后一个节点
        N--;
        sink(1);
        return max;
    }

    /**
     * 功能：删除元素后，使用下沉思想调整为大顶堆
     * @param k 使用下沉算法，使得索引k处的元素能在堆中处于一个正确的位置
     */
    private void sink(int k) {
        //不断比较并交换当前节点与直接子节点
        while(2*k <= N) {
            int max; //获取当前结点的直接子结点中的较大结点
            if(2*k+1<=N) {
                if(less(2*k,2*k+1)) {
                    max = 2*k+1;
                } else {
                    max = 2*k;
                }
            } else {
                max = 2*k;
            }

            //比较当前结点和较大结点的值
            if (!less(k,max)){
                break;
            }

            exchange(k,max);

            k = max;
        }
    }

}

class HeapCURDTest {
    public static void main(String[] args) {
        Integer[] sourceArray = {10,23,99,33,13,44,11,64,68,76};
        Integer[] heapSortArray = new Integer[sourceArray.length+1]; //注意：堆排序的数组不使用下标0
        Heap heap = new Heap();
        heap.createBigHeap(sourceArray,heapSortArray);
        System.out.print("创建出的大顶堆：");
        Arrays.stream(heapSortArray).filter(Objects::nonNull).forEach(e -> System.out.print(e+" ")); //IDEA代码优化
        System.out.println();

        HeapCRUD<Integer> heapCRUD = new HeapCRUD<Integer>(heapSortArray, 20);
        heapCRUD.insert(9);
        heapCRUD.insert(108);
        heapCRUD.insert(5);
        heapCRUD.insert(200);

        System.out.println("插入新值后的大顶堆：");
        Integer del;
        while((del=heapCRUD.deleteMax())!=null){
            System.out.print(del+"  ");
        }
    }
}
