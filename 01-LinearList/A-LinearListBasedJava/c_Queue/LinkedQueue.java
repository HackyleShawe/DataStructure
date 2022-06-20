
import org.w3c.dom.Node;

import java.util.Iterator;

/**
 * 链式队列
 */
class LinkedQueue<T> implements Iterable<T> {
    /** 队首 */
    private Node head;
    /** 队尾 */
    private Node last;
    /** 队列中元素的个数 */
    private Long N;

    /**
     * 节点定义
     */
    private class Node {
        /** 节点内的数据 */
        private T data;
        /** 下一个节点 */
        private Node next;

        public Node(T data, Node next) {
            this.data = data;
            this.next = next;
        }
    }

    /**
     * 构造器：创建队列头，队列尾尾null
     */
    public LinkedQueue() {
        this.head = new Node(null,null);
        this.last = null;
        this.N = 0L;
    }


    /**
     * 入队列
     * @param t 要入队列的元素
     */
    public void enqueue(T t) {
        if(last == null) {
            last = new Node(t, null);
            head.next = last;
        } else {
            Node oldLast = last;
            last = new Node(t,null);
            oldLast.next = last;
        }
        N++;
    }

    /**
     * 出队列
     * @return 出队列后的元素
     */
    public T dequeue() {
        if(isEmpty()) {
            return null;
        }
        Node oldHead = head.next;
        head.next = oldHead.next;
        N--;

        //如果队列中的元素全部被删除了，则需要将last置空
        if(isEmpty()) {
            last = null;
        }
        return oldHead.data;
    }

    /**
     * 获取队列中的元素个数
     * @return 元素个数
     */
    public Long size() {
        return N;
    }

    /**
     * 队列是否为空
     */
    public boolean isEmpty() {
        return N==0;
    }

    /**
     * 迭代器
     */
    @Override
    public Iterator<T> iterator() {
        return new QueueIterator();
    }
    private class QueueIterator implements Iterator<T> {
        private LinkedQueue<T>.Node tmp;
        public QueueIterator() {
            tmp = head;
        }
        @Override
        public boolean hasNext() {
            return tmp.next != null;
        }

        @Override
        public T next() {
            tmp = tmp.next;
            return tmp.data;
        }
    }
}


/**
 * 链式队列测试
 */
class LinkedQueueTest {
    public static void main(String[] args) {
        LinkedQueue<String> queue = new LinkedQueue<>();
        queue.enqueue("aa");
        queue.enqueue("bb");
        queue.enqueue("cc");
        queue.enqueue("dd");

        System.out.println("弹出队首元素："+queue.dequeue());

        Iterator<String> it = queue.iterator();
        while(it.hasNext()) {
            System.out.println(it.next());
        }
    }

}