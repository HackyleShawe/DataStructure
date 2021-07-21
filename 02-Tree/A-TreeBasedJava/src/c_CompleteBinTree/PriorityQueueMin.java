package c_CompleteBinTree;

import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.List;

/**
 * 最小优先队列（本质：小顶堆）
 */
public class PriorityQueueMin<T extends Number> {
    /** 最大优先队列基于堆，堆的存储结构为数组 */
    private List<T> heapQueue;

    /**
     * 构造器
     */
    public PriorityQueueMin() {
        heapQueue = new ArrayList<>();
        heapQueue.add(null); //保存堆的数组，第一个元素是不存储值得
    }

    /**
     * <p>Function：入队列操作</p>
     * <p>Algorithm：直接向数组末尾插入元素，然后再进行上浮操作</p>
     */
    public void inQueue(T data) {
        heapQueue.add(data);
        swim(heapQueue.size() - 1);
    }

    /**
     * <p>Function：使用上浮算法，使索引k处的元素能在堆中处于一个正确的位置</p>
     * <p>Algorithm: 比较交换当前节点与其父节点</p>
     * @param k 对当前节点k进行上浮操作
     */
    private void swim(int k) {
        while(k > 1){
            //比较当前节点与其父节点，小的往上交换
            if (smaller(k,k/2)){ //大顶堆中的写法：smaller(k/2,k)
                exchange(k,k/2);
            }
            k = k/2;
        }
    }


    /**
     * <p>Function：出列对操作</p>
     * <p>Algorithm：小顶堆中的最小值就是对数组中的下标为1的元素</p>
     *  <ol>
     *  <li>取得下标为1的元素</li>
     *  <li>交换数组中的下标为1的元素和数组的最后一个元素</li>
     *  <li>下沉刚刚交换上来的元素</li>
     *  </ol>
     * @return 出队列的数据
     */
    public T getMinPriority() {
        T max = heapQueue.get(1);
        exchange(1, heapQueue.size() - 1);
        sink(1); //交换上的元素放在顶点，对顶点进行下沉
        return max;
    }

    /**
     * <p>Function:使用下沉算法，使索引k处的元素能在堆中处于一个正确的位置</p>
     * <p>Algorithm:比较交换当前节点与其子节点，使得最大值往下沉</p>
     * @param k 对当前节点k进行下沉操作
     */
    private void sink(int k) {
        while(2*k <= heapQueue.size()-1){
            int min;
            if (2*k+1 <= heapQueue.size()-1){ //如果当前节点k有左右子节点
                if (smaller(2*k,2*k+1)){ //比较左右子节点，返回最小子节点的下标
                    min = 2*k;
                }else{
                    min = 2*k+1;
                }
            }else { //只有左子节点，直接认定该左子节点为最小节点
                min = 2*k;
            }

            if (!smaller(k, min)){
                break;
            }

            exchange(k, min);
            k = min;
        }
    }

    /**
     * 判断是否为空
     */
    public boolean isEmpty() {
        return heapQueue.isEmpty();
    }

    /**
     * 如果i处的值更小，则返回true
     */
    private boolean smaller(int i, int j) {
        BigDecimal a = new BigDecimal(heapQueue.get(i).toString());
        BigDecimal b = new BigDecimal(heapQueue.get(j).toString());
        return a.compareTo(b) < 0;
    }

    /**
     * 交换i处和j处的值
     */
    private void exchange(int i, int j) {
        T tmp = heapQueue.get(i);
        heapQueue.set(i, heapQueue.get(j));
        heapQueue.set(j, tmp);
    }
}


/**
 * 测试类
 */
class PriorityQueueMinTest {
    public static void main(String[] args) {
        PriorityQueueMin<Integer> priorityQueueMax01 = new PriorityQueueMin<>();
        priorityQueueMax01.inQueue(22);
        priorityQueueMax01.inQueue(3452);
        priorityQueueMax01.inQueue(12341);
        priorityQueueMax01.inQueue(34);
        priorityQueueMax01.inQueue(13);
        priorityQueueMax01.inQueue(17876876);

        System.out.println("获取优小队列中最优小的数据：" + priorityQueueMax01.getMinPriority());
        System.out.println("获取优小队列中最优小的数据：" + priorityQueueMax01.getMinPriority());

        PriorityQueueMin<BigDecimal> priorityQueueMax02 = new PriorityQueueMin<>();
        priorityQueueMax02.inQueue(new BigDecimal("2222222222"));
        priorityQueueMax02.inQueue(new BigDecimal("352345"));
        priorityQueueMax02.inQueue(new BigDecimal("9879789678"));
        priorityQueueMax02.inQueue(new BigDecimal("23413"));
        priorityQueueMax02.inQueue(new BigDecimal("321.31434"));
        System.out.println("获取优小队列中最优小的数据：" + priorityQueueMax02.getMinPriority());
        System.out.println("获取优小队列中最优小的数据：" + priorityQueueMax02.getMinPriority());
    }
}