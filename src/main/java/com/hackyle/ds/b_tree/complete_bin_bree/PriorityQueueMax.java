package c_CompleteBinTree;

import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.List;

/**
 * 最大优大队列（本质：大顶堆）
 */
public class PriorityQueueMax<T extends Number> {
    /** 最大优大队列基于堆，堆的存储结构为数组 */
    private List<T> heapQueue;

    /**
     * 构造器
     */
    public PriorityQueueMax() {
        heapQueue = new ArrayList<>();
        heapQueue.add(null); //注意：堆数组的第一个元素是不存储具体的数据的
    }

    /**
     * 入队列
     */
    public void inQueue(T data) {
        heapQueue.add(data);
        swim(heapQueue.size() - 1);
    }
    /**
     * <p>Function: 使用上浮算法，使索引k处的元素能在堆中处于一个正确的位置</p>
     * <p>Algorithm: 比较交换当前节点与其父节点</p>
     * @param k 对当前节点k进行上浮操作
     */
    private void swim(int k) {
        while(k > 1){
            if (smaller(k/2, k)){
                exchange(k/2, k);
            }

            k = k/2;
        }
    }

    /**
     * <p>Function: 获取优大队列中的最优大的数据</p>
     * <p>算法：大顶堆中的最大值就是对数组中的下标为1的元素</p>
     *  <ol>
     *  <li>取得下标为1的元素</li>
     *  <li>交换数组中的下标为1的元素和数组的最后一个元素</li>
     *  <li>下沉刚刚交换上来的元素</li>
     *  </ol>
     */
    public T getMaxPriority() {
        T max = heapQueue.get(1);
        exchange(1,heapQueue.size() - 1);
        sink(1); //交换上的元素放在顶点，对顶点进行下沉
        return max;
    }
    /**
     * <p>Function: 使用下沉算法，使索引k处的元素能在堆中处于一个正确的位置</p>
     * <p>Algorithm: 比较交换当前节点与其子节点</p>
     * @param k 对当前节点k进行下沉操作
     */
    private void sink(int k) {
        while(2*k <= heapQueue.size()-1){
            int max;
            if (2*k+1 <= heapQueue.size() - 1){ //如果当前节点k有左右子节点
                if (smaller(2*k,2*k + 1)){ //比较左右子节点，返回最大子节点的下标
                    max=2*k + 1;
                }else{
                    max = 2*k;
                }
            }else { //只有左子节点，直接认定该左子节点为最大节点
                max = 2*k;
            }

            if (!smaller(k, max)){
                break;
            }

            exchange(k, max);
            k = max;
        }
    }

    /**
     * 判断优大队列是否为空
     */
    public boolean isEmpty() {
        return heapQueue.isEmpty();
    }

    /**
     * 交换两个位置上的数
     */
    private void exchange(int i, int j) {
        T tmp = heapQueue.get(i);
        heapQueue.set(i, heapQueue.get(j));
        heapQueue.set(j, tmp);
    }

    /**
     * 如果i位置上的数更小，则返回true
     */
    private boolean smaller(int i, int j) {
        BigDecimal a = new BigDecimal(heapQueue.get(i).toString());
        BigDecimal b = new BigDecimal(heapQueue.get(j).toString());
        return a.compareTo(b) < 0;
    }
}


/**
 * 测试类
 */
class PriorityQueueMaxTest {
    public static void main(String[] args) {
        PriorityQueueMax<Integer> priorityQueueMax01 = new PriorityQueueMax<>();
        priorityQueueMax01.inQueue(22);
        priorityQueueMax01.inQueue(3452);
        priorityQueueMax01.inQueue(12341);
        priorityQueueMax01.inQueue(34);
        priorityQueueMax01.inQueue(13);
        priorityQueueMax01.inQueue(17876876);

        System.out.println("获取优大队列中最优大的数据：" + priorityQueueMax01.getMaxPriority());
        System.out.println("获取优大队列中最优大的数据：" + priorityQueueMax01.getMaxPriority());

        PriorityQueueMax<BigDecimal> priorityQueueMax02 = new PriorityQueueMax<>();
        priorityQueueMax02.inQueue(new BigDecimal("2222222222"));
        priorityQueueMax02.inQueue(new BigDecimal("352345"));
        priorityQueueMax02.inQueue(new BigDecimal("9879789678"));
        priorityQueueMax02.inQueue(new BigDecimal("23413"));
        priorityQueueMax02.inQueue(new BigDecimal("32431.31434"));
        System.out.println("获取优大队列中最优大的数据：" + priorityQueueMax02.getMaxPriority());
        System.out.println("获取优大队列中最优大的数据：" + priorityQueueMax02.getMaxPriority());
    }

}