package ds;

import org.junit.jupiter.api.Test;

/**
 * <p>链式双端循环队列</p>
 * <p>本质：队列的思想 + 不带头结点的双向链表</p>
 *
 * 双向循环链表示意图，如果还是不怎么理解，见"DataStruct-线性表-队列-双端循环队列.docx"
 *  >———————————————————————————————————————————>
 *  <-- |-pre- | <--  |-pre- | <--  |-pre- | <--
 *      |-data-|      |-data-|      |-data-|
 *  --> |-next-| -->  |-next-| -->  |-next-| --->
 *  <————————————————————————————————————————<———
 */
public class LinkedDequeueCycle<T> {
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
    public LinkedDequeueCycle() {
        head = null;
        tail = null;
        N = 0;
    }

    /**
     * <p>Function: 循环双向队列的 <b>头部入队列</b> </p>
     * <p>Algorithm: </p>
     * <p> 1.创建节点node，因为是放在头部的，直接让其的pre指向tail，next指向head</p>
     * <p> 2.如果head为空，则说明目前循环双向链表一个元素也没有，则直接上tail、head都指向node</p>
     * <p> 3.如果head不为空，则说明目前循环双向链表已经有了元素，则需要在原来的元素之前插入。</p>
     */
    public void headInDequeue(T data) {
        Node tmp = head;
        Node node = new Node(tail, data, head);
        head = node;
        if(tmp == null) { //第一个节点
            tail = node;
        } else {
            tmp.pre = node;
        }

        /* 这一步很重要：将队列的尾部next与头部连接起来 */
        tail.next = head;
        N++;
    }

    /**
     * <p>Function: 头部出队列</p>
     * <p>Algorithm: 取得head的data，将head向后移一位，再将head的pre指向tail</p>
     */
    public T headOutDequeue() {
        if(isEmpty()) {
            throw new RuntimeException("队列为空");
        }

        T result = head.data;
        head = head.next;
        if(head != null) {
            head.pre = tail;
        }
        N--;

        return result;
    }

    /**
     * <p>Function: 尾部入队列</p>
     * <p>Algorithm: </p>
     * <p> 1.创建节点node，因为是放在尾部的，直接让其的pre指向tail，next指向head</p>
     * <p> 2.如果tail为空，则说明当前队列一个元素也没有，直接让tail、head指向node</p>
     * <p> 3.如果tail不为空，则当前队列已经有元素了，则把原来的tail的next指向node即可</p>
     */
    public void tailInDequeue(T data) {
        Node tmp = tail;
        Node node = new Node(tail, data, head);
        tail = node;
        if(tmp == null) { //当前双向循环队列为空
            head = node;
        } else {
            tmp.next = node;
        }

        /* 作用：将队列的头部pre与尾部联系起来。这一步其实可有可无，因为在new Node时已经指明了 */
        head.pre = tail;
        N++;
    }

    /**
     * <p>Function: 尾部出队列</p>
     * <p>Algorithm: 取得tail的data，tail向前移动一位，再将tail的next指向head</p>
     */
    public T tailOutDequeue() {
        if(isEmpty()) {
            throw new RuntimeException("队列为空");
        }

        T result = tail.data;
        tail = tail.pre;
        if(tail != null) {
            tail.next = head;
        }
        N--;

        return result;
    }

    /**
     * 队列中元素的个数
     */
    public int size() {
        return N;
    }

    /**
     * 队列是否为空
     */
    public boolean isEmpty() {
        return head == null || tail == null || N==0;
    }

    /**
     * 正向打印队列
     */
    public void printFromHead() {
        if(isEmpty()) {
            throw new RuntimeException("队列为空");
        }

        System.out.print(head.data + " ");
        Node tmp = head.next;
        while(tmp != tail.next) {
            System.out.print(tmp.data + " ");
            tmp = tmp.next;
        }
        System.out.println();
    }

    /**
     * 逆向打印队列
     */
    public void printFromTail() {
        if(isEmpty()) {
            throw new RuntimeException("队列为空");
        }

        System.out.print(tail.data + " ");
        Node tmp = tail.pre;
        while(tmp != head.pre) {
            System.out.print(tmp.data + " ");
            tmp = tmp.pre;
        }
        System.out.println();
    }
}

/**
 * 双向循环链表的测试
 */
class LinkedDequeueCycleTest {

    /**
     * 多个元素在头部进、出队列，在尾部进、出队列
     */
    @Test
    public void test01() {
        LinkedDequeueCycle<String> dequeue = new LinkedDequeueCycle<>();
        dequeue.tailInDequeue("AA");
        dequeue.tailInDequeue("BB");
        dequeue.tailInDequeue("CC");
        dequeue.tailInDequeue("DD");

        dequeue.headInDequeue("22");
        dequeue.headInDequeue("11");
        dequeue.headInDequeue("00");

        System.out.println("数量：" + dequeue.size());
        System.out.println("正向遍历：");
        dequeue.printFromHead();
        System.out.println("反向遍历：");
        dequeue.printFromTail();

        System.out.println("尾出：" + dequeue.tailOutDequeue());
        System.out.println("尾出：" + dequeue.tailOutDequeue());

        System.out.println("头出：" + dequeue.headOutDequeue());
        System.out.println("头出：" + dequeue.headOutDequeue());
    }

    /**
     * 空队列的进、入操作
     */
    @Test
    public void test02() {
        LinkedDequeueCycle<String> dequeue = new LinkedDequeueCycle<>();
        System.out.println(dequeue.size());
        try {
            System.out.println(dequeue.headOutDequeue());
        } catch (RuntimeException e) {
            e.printStackTrace();
        }

        try {
            System.out.println(dequeue.tailOutDequeue());
        } catch (RuntimeException e) {
            e.printStackTrace();
        }
    }

    /**
     * 一个元素的双向循环队的入、出队列操作
     */
    @Test
    public void test03() {
        LinkedDequeueCycle<String> dequeue01 = new LinkedDequeueCycle<>();
        dequeue01.headInDequeue("AA");
        System.out.println(dequeue01.headOutDequeue());

        LinkedDequeueCycle<String> dequeue02 = new LinkedDequeueCycle<>();
        dequeue02.tailInDequeue("AAA");
        System.out.println(dequeue02.tailOutDequeue());

        LinkedDequeueCycle<String> dequeue03 = new LinkedDequeueCycle<>();
        dequeue03.headInDequeue("XXX");
        System.out.println(dequeue03.tailOutDequeue());

        LinkedDequeueCycle<String> dequeue04 = new LinkedDequeueCycle<>();
        dequeue04.tailInDequeue("YYY");
        System.out.println(dequeue04.headOutDequeue());
    }
}