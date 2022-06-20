import org.junit.jupiter.api.Test;

/**
 * 链式循环队列
 */
public class LinkedQueueCycle<T> {
    /** 循环队列头结点 */
    private Node head;

    /** 节点定义 */
    private class Node {
        T data;
        Node next;
        public Node(T data, Node next) {
            this.data = data;
            this.next = next;
        }
    }

    /**
     * 构造器，初始化链式循环队列的头结点
     */
    public LinkedQueueCycle() {
        head = new Node(null,null);
    }

    /**
     * 入队列，等价于循环单链表的尾插法
     */
    public void inQueue(T data) {
        if(head.next == null) {
            head.next = new Node(data,head);
        } else {
            Node tmp = head.next;
            while(tmp.next != head) {
                tmp = tmp.next;
            }
            tmp.next = new Node(data,head);
        }
    }

    /**
     * 出队列
     */
    public T outQueue() {
        Node first = head.next;
        if(first.data == head.data) {
            throw new RuntimeException("队列已空，无法再出队列");
        }
        head.next = first.next;
        return first.data;
    }

    /**
     * 打印链式队列
     */
    public void print() {
        Node tmp = head.next;
        while(tmp != head) {
            System.out.print(tmp.data + " ");
            tmp = tmp.next;
        }
    }
}



class LinkedQueueCycleTest {
    @Test
    public void test01() {
        LinkedQueueCycle<String> queueCycle = new LinkedQueueCycle<>();
        queueCycle.inQueue("aa");
        queueCycle.inQueue("bb");
        queueCycle.inQueue("cc");

        queueCycle.print();
        System.out.println();

        System.out.println(queueCycle.outQueue());
        System.out.println(queueCycle.outQueue());
        System.out.println(queueCycle.outQueue());
        System.out.println(queueCycle.outQueue());
    }
}