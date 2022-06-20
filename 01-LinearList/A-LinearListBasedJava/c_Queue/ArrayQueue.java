import org.junit.jupiter.api.Test;

import java.util.ArrayList;

/**
 * 顺序队列
 */
public class ArrayQueue<T> {
    /** 队列头 */
    private int head;
    /** 队列尾 */
    private int tail;
    /** 顺序队列 */
    private ArrayList<T> arrayList;

    /**
     * 构造器
     */
    public ArrayQueue() {
        arrayList = new ArrayList<>();
        head = 0;
        tail = 0;
    }

    /**
     * 入队列
     */
    public void inQueue(T data) {
        arrayList.add(data);
        tail++;
    }

    /**
     * 出队列
     */
    public T outQueue() {
        if(head >= tail) {
            throw new RuntimeException("队列已经为空，无法再获取");
        }
        T tmp = arrayList.get(head);
        head++;
        return tmp;
    }

    /**
     * 打印队列
     */
    public void print() {
        for (int i = head; i < tail; i++) {
            System.out.print(arrayList.get(i) + " ");
        }
    }
}


class ArrayQueueTest {
    @Test
    public void test01() {
        ArrayQueue<String> queue = new ArrayQueue<>();
        queue.inQueue("aa");
        queue.inQueue("bb");
        queue.inQueue("vv");

        queue.print();
        System.out.println();

        System.out.println(queue.outQueue());
        System.out.println(queue.outQueue());
        System.out.println(queue.outQueue());
        System.out.println(queue.outQueue()); //抛出异常

    }
}