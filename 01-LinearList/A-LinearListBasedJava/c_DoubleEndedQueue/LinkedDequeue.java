
import org.junit.jupiter.api.Test;

/**
 * <p>链式双端队列</p>
 * <p>本质：队列的思想 + 不带头结点的双向链表</p>
 */
public class LinkedDequeue<T> {
    /** 队列头 */
    private Node head;
    /** 队列尾 */
    private Node tail;
    /** 队列的元素个数 */
    private int N;

    /** 节点定义 */
    private class Node {
        T data;
        Node pre;
        Node next;
        public Node(Node pre, T data, Node next) {
            this.data = data;
            this.pre = pre;
            this.next = next;
        }
    }

    /**
     * 构造器（注意：不带头结点）
     */
    public LinkedDequeue() {
        head = null;
        tail = null;
        N = 0;
    }

    /**
     * <p>Function：从头部入队列</p>
     * <p>Algorithm：</p>
     * <p> 1. 队列为空，则新创建一个节点，让head和tail指向该节点</p>
     * <p> 2. 队里不为空，创建节点node，指向head。让head的pre指向node，然后head往前移</p>
     */
    public void headInDequeue(T data) {
        if(head == null && tail == null) {
            Node node = new Node(null, data,null);
            head = node;
            tail = node;
        } else {
            head.pre = new Node(null, data, head);
            head = head.pre;
        }
        N++;
    }

    /**
     * <p>Function：头部出队列</p>
     * <p>Algorithm: 取得head的data，将head向后移一个</p>
     */
    public T headOutDequeue() {
        if(size() == 0  || (head == null && tail == null)) {
            throw new RuntimeException("队列为空");
        }
        T result = head.data;
        head = head.next;
        head.pre = null;

        N--;
        return result;
    }

    /**
     * <p>Function：尾部入队列</p>
     * <p>Algorithm: </p>
     * <p> 1.队列为空，则创建一个node，让head、tail指向该node</p>
     * <p> 2.队列不为空，创建一个node，让其的pre指向原来的tail，next指向null。tail后移一位即可。</p>
     */
    public void tailInDequeue(T data) {
        if(head == null && tail == null) {
            Node node = new Node(null, data, null);
            head = node;
            tail = node;
        } else {
            tail.next = new Node(tail, data,null);
            tail = tail.next;
        }
        N++;
    }

    /**
     * <p>Function：尾部出队列</p>
     * <p>Algorithm：取出tail的data，将tail向前移一位即可</p>
     */
    public T tailOutDequeue() {
        if(size() == 0  || (head == null && tail == null)) {
            throw new RuntimeException("队列为空");
        }
        T result = tail.data;
        tail = tail.pre;
        tail.next = null;
        N++;

        return result;
    }

    /**
     * 队列中的元素
     */
    public int size() {
        return N;
    }


    /**
     * 从队列头依次打印，至队列尾结束
     */
    public void printFromHead() {
        Node tmp = head;
        while(tmp != null) {
            System.out.print(tmp.data + " ");
            tmp = tmp.next;
        }
        System.out.println();
    }

    /**
     * 从队列尾依次打印，至队列头结束
     */
    public void printFromTail() {
        Node tmp = tail;
        while(tmp != null) {
            System.out.print(tmp.data + " ");
            tmp = tmp.pre;
        }
        System.out.println();
    }
}


class LinkedDequeueTest {
    @Test
    public void test01() {
        LinkedDequeue<String> dequeue = new LinkedDequeue<>();
        dequeue.tailInDequeue("aa");
        dequeue.tailInDequeue("bb");
        dequeue.tailInDequeue("cc");
        dequeue.tailInDequeue("dd");

        dequeue.headInDequeue("11");
        dequeue.headInDequeue("00");

        System.out.println("数量：" + dequeue.size());
        System.out.println("正向打印：");
        dequeue.printFromHead();
        System.out.println("反向打印：");
        dequeue.printFromTail();
        System.out.println("尾出队列" + dequeue.tailOutDequeue());
        System.out.println("尾出队列" + dequeue.tailOutDequeue());

        System.out.println("头出队列" + dequeue.headOutDequeue());
        System.out.println("头出队列" + dequeue.headOutDequeue());

    }
}