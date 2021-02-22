package c_queue;

import java.util.Iterator;

/**
 * 自己实现队列
 */
class MyQueue<T> implements Iterable<T> {
    private Node head; //队首
    private Node last; //队尾
    private Long N;

    private class Node {
        private T data;
        private Node next;

        public Node(T data, Node next) {
            this.data = data;
            this.next = next;
        }
    }

    public MyQueue() {
        this.head = new Node(null,null);
        this.last = null;
        this.N = 0L;
    }


    /*入队列*/
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

    /*出队列*/
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

    public Long size() {
        return N;
    }
    public boolean isEmpty() {
        return N==0;
    }

    @Override
    public Iterator<T> iterator() {
        return new QueueIterator();
    }
    private class QueueIterator implements Iterator {
        private Node tmp;
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

class MyQueueTest {
    public static void main(String[] args) throws Exception {
        MyQueue<String> queue = new MyQueue<>();
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