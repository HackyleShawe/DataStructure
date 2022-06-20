
import java.util.Iterator;
import java.util.LinkedList;

/**
 * 双向链表
 */
public class DoubleLinkedList<T> implements Iterable<T> {
    /** 头指针 */
    private Node head;
    /** 尾指针 */
    private Node last;
    /** 链表的长度 */
    private long N;

    /**
     * 链表节点定义
     */
    private class Node {
        /**
         * 节点数据
         */
        T data;
        /**
         * 后继
         */
        Node next;
        /**
         * 前驱
         */
        Node pre;

        public Node(T data, Node next, Node pre) {
            this.data = data;
            this.next = next;
            this.pre = pre;
        }
    }

    /**
     * 构造器：初始化双向链表的头结点，头节点不存数据
     */
    public DoubleLinkedList() {
        this.head = new Node(null,null,null);
        this.last = null;
        this.N = 0;
    }

    /**
     * 增：头插法
     */
    public void insertHead(T t) {
        Node tmp = this.head;
        if(isEmpty() || tmp.next == null) {
            Node newNode = new Node(t, null, this.head);
            tmp.next = newNode;
            this.last = newNode;
        } else {
            Node p = tmp.next;
            Node newNode = new Node(t,p,tmp);
            p.pre = newNode;
            tmp.next = newNode;
        }
        N++;
    }

    /**
     * 增：尾插法
     */
    public void insertLast(T t) {
        if(isEmpty() || this.head.next == null) {
            Node newNode = new Node(t, null, this.head);
            this.last = newNode;
            this.head.next = newNode;
        } else {
            Node oldLast = this.last;
            Node newNode = new Node(t, null, oldLast);
            oldLast.next = newNode;
            this.last = newNode;
        }
        N++;
    }


    /**
     * 删除所有
     */
    public void clear() {
        this.head.next = null;
        this.head.pre = null;
        this.head = null; //清空头指针
        this.last = null;
        this.N = 0;
    }

    /**
     * 删除指定元素
     * @param t 待删除的元素
     */
    public void remove(T t) {
        Node tmp = this.head.next;
        Node post = this.head;
        while(tmp!=null) {
            if(tmp.data.equals(t)) {
                post.next = tmp.next;
            }
            post = tmp;
            tmp = tmp.next;
        }
    }


    /**
     * 获取双向链表的元素个数
     * @return 链表数量
     */
    public long length() {
        return this.N;
    }

    /**
     * 判断是否为空
     */
    public boolean isEmpty() {
        return N==0;
    }

    /**
     * 获取头节点
     * @return 头结点的元素
     */
    public T getHead() {
        if(this.head.next == null) {
            return null;
        }
        return this.head.next.data;
    }

    /**
     * 获取尾节点
     * @return 尾结点的元素
     */
    public T getLast() {
        if(this.last == null) {
            return null;
        }
        return this.last.data;
    }

    /**
     * 正向迭代器
     */
    @Override
    public Iterator<T> iterator() {
        return new DoubleListIterator();
    }
    private class DoubleListIterator implements Iterator<T> {
        private Node iterate;
        public DoubleListIterator() {
            this.iterate = head;
        }
        @Override
        public boolean hasNext() {
            return iterate.next!=null;
        }

        @Override
        public T next() {
            iterate = iterate.next;
            return iterate.data;
        }
    }

}


/**
 * 双向链表测试
 */
class DoubleLinkedListTest {
    public static void main(String[] args) throws Exception {
        DoubleLinkedList<Integer> linkedList = new DoubleLinkedList<Integer>();
        linkedList.insertHead(11);
        linkedList.insertHead(22);
        linkedList.insertLast(33);
        linkedList.insertLast(44);
        linkedList.insertLast(55);

        linkedList.remove(11);

        System.out.println(linkedList.getHead());
        System.out.println(linkedList.getLast());

        Iterator<Integer> it = linkedList.iterator();
        while(it.hasNext()) {
            System.out.print(it.next()+ "  ");
        }
    }
}
