import org.junit.jupiter.api.Test;

import java.util.ArrayList;

/**
 * 带头结点的循环顺序队列：将第一个元素设置为队列的头结点，不存储数据
 */
public class ArrayQueueCycle<T> {
    /** 队列头 */
    private int head;
    /** 队列尾 */
    private int tail;
    /** 顺序队列 */
    private ArrayList<T> arrayList;
    /** 顺序队列的总大小 */
    private static final int N = 100;

    public ArrayQueueCycle() {
        head = 0;
        tail = 0;
        arrayList = new ArrayList<>(N);
    }

    /**
     * 入队列
     */
    public void inQueue(T data) {
        if(isFull()) {
            throw new RuntimeException("队列已满");
        }

        arrayList.add(data);
        tail++;
    }

    /**
     * 出队列
     */
    public T outQueue() {
        if(isEmpty()) {
            throw new RuntimeException("队列为空");
        }
        return arrayList.get(head++);
    }

    /**
     * 队列中元素的个数
     */
    public int size() {
        return (tail - head + N) % N ;
    }

    /**
     * 判空
     */
    public boolean isEmpty() {
        return size() == 0;
    }

    /**
     * 判满
     */
    public boolean isFull() {
        return (tail + 1) % N == head;
    }

}


class ArrayQueueCycleTest {
    @Test
    public void test01() {
        ArrayQueueCycle<String> queue = new ArrayQueueCycle<>();
        queue.inQueue("aaa");
        queue.inQueue("bbb");
        queue.inQueue("ccc");
        queue.inQueue("ddd");

        System.out.println(queue.isEmpty());
        System.out.println(queue.isFull());
        System.out.println(queue.size());
        System.out.println(queue.outQueue());
        System.out.println(queue.outQueue());

    }
}