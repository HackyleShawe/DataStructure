package c_CompleteBinTree;

/**
 * 最大优先队列（本质：大顶堆）
 */
public class PriorityQueueMax<T extends Comparable<T>> {
    private T[] items; //最大优先队列基于堆，堆的存储结构为数组
    private int N; //数组的长度

    public PriorityQueueMax(int capacity) {
        items = (T[]) new Comparable[capacity+1]; //注意基于堆的数组第一个元素（下标为0）是不使用的
        this.N = 0;
    }

    /**
     * 获取队列中的元素个数
     */
    public int size() {
        return N;
    }
    /**
     * 判断是否为空
     */
    public boolean isEmpty() {
        return N == 0;
    }

    /**
     * 比较大小
     */
    private boolean less(int i, int j) {
        return items[i].compareTo(items[j])<0;
    }
    /**
     * 交换
     */
    private void exchange(int i, int j) {
        T tmp = items[i];
        items[i] = items[j];
        items[j] = tmp;
    }

    /**
     * 功能：入队列操作
     * 算法：直接向数组末尾插入元素，然后再进行上浮操作
     * @param t 要入队列的数据
     */
    public void tailInsert(T t) {
        items[++N] = t;
        swim(N);
    }

    /**
     * 使用上浮算法，使索引k处的元素能在堆中处于一个正确的位置
     * 比较交换当前节点与其父节点
     * @param k 对当前节点k进行上浮操作
     */
    private void swim(int k) {
        while(k>1){
            if (less(k/2,k)){
                exchange(k/2,k);
            }

            k = k/2;
        }
    }

    /**
     * 功能：出列对操作
     * 算法：大顶堆中的最大值就是对数组中的下标为1的元素
     *  1.取得下标为1的元素
     *  2.交换数组中的下标为1的元素和数组的最后一个元素
     *  3.下沉刚刚交换上来的元素
     * @return 出队列的数据
     */
    public T headEject() {
        T max = items[1];
        exchange(1,N);
        N--;
        sink(1); //交换上的元素放在顶点，对顶点进行下沉
        return max;
    }

    /**
     * 使用下沉算法，使索引k处的元素能在堆中处于一个正确的位置
     * 比较交换当前节点与其子节点
     * @param k 对当前节点k进行下沉操作
     */
    private void sink(int k) {
        while(2*k<=N){
            int max;
            if (2*k+1<=N){ //如果当前节点k有左右子节点
                if (less(2*k,2*k+1)){ //比较左右子节点，返回最大子节点的下标
                    max=2*k+1;
                }else{
                    max = 2*k;
                }
            }else { //只有左子节点，直接认定该左子节点为最大节点
                max = 2*k;
            }

            if (!less(k,max)){
                break;
            }

            exchange(k,max);
            k = max;
        }
    }
}


class PriorityQueueMaxTest {
    public static void main(String[] args){
        PriorityQueueMax<Integer> priorityQueue = new PriorityQueueMax<>(10);
        priorityQueue.tailInsert(19);
        priorityQueue.tailInsert(22);
        priorityQueue.tailInsert(43);
        priorityQueue.tailInsert(10);

        System.out.println(priorityQueue.headEject()); //输出：43
        System.out.println(priorityQueue.headEject()); //输出：22
        System.out.println(priorityQueue.headEject()); //输出：19
    }

}