package b_LinkedList;

import java.util.Iterator;

/**
 * 单向链表
 */
public class SingleLinkedList<T> implements Iterable<T>  {
    /**
     * 链表的头
     */
    private Node head;
    /**
     * 链表的长度
     */
    private int N;

    /**
     * 成员内部类：表示链表的一个结点
     */
    private class Node {
        T data;
        Node next;

        public Node(T data, Node next) {
            this.data = data;
            this.next = next;
        }
    }

    /**
     * 构造器：初始化单链表的头节点
     */
    public SingleLinkedList() {
        this.head = new Node(null,null); //带头结点
        this.N=0;
    }

    /**
     * 增：头插法
     */
    public void insertByHead(T t) {
        if(head.next == null) { //空链表
            head.next = new Node(t,null);
        } else {
            head.next = new Node(t, head.next);
        }
    }

    /**
     * 增：尾插法
     */
    public void insertByTail(T t) {
        Node tmp = head;
        while(tmp.next != null) { //遍历到最后
            tmp = tmp.next;
        }
        tmp.next = new Node(t,null);
        N++; //链表的元素个数加一
    }

    //链表通常不能按位置插入
    //public void insert(T t, int index) {
    //    if(index<0 || index>=N) {
    //        throw new RuntimeException("下标参数："+index+", 越界");
    //    }
    //
    //    Node tmp = head;
    //    Node post = head;
    //    Node pre = head;
    //
    //    for(int i=0; i<=index; i++) {
    //        post = tmp;
    //        tmp = tmp.next;
    //        pre = tmp;
    //    }
    //    Node newNode = new Node(t,null);
    //    post.next = newNode;
    //    newNode.next = pre;
    //    N++; //链表的数目加一
    //}

    /**
     * 删除所有
     */
    public void clear() {
        head.next = null;
        N = 0;
    }

    /**
     * 删除指定元素
     */
    public void remove(T t) {
        Node tmp = head.next;
        Node post = head;
        while(tmp!=null) {
            if(tmp.data.equals(t)) {
                post.next = tmp.next;
            }
            post = tmp;
            tmp = tmp.next;
        }
        N--;
    }


    /**
     * 链表反转
     * Algorithm：头插法实现(遍历原链表，逐一取下，以头插法形式创建新链)
     */
    public void reverse() {
        //if(isEmpty()) {
        //    throw new RuntimeException("链表为空，无法反转");
        //}
        //
        Node t = head.next;
        Node p = t;
        Node newHead = null;
        while(t!=null) {
            p = t;
            t = t.next;
            if(newHead == null) {
                newHead = p;
                newHead.next = null;
            } else {
                p.next = newHead;
                newHead = p;
            }
        }
        head.next = newHead;
    }


    /**
     * 节点数量
     */
    public int length() {
        return this.N;
    }

    /**
     * 是否为空
     */
    public boolean isEmpty() {
        return N==0;
    }

    /**
     * 获取尾巴的数据
     */
    public T getTail() {
        Node t = head;
        while(t.next != null) {
            t = t.next;
        }
        return t.data;
    }

    //通常链表不能有根据索引进行的相关操作
    //public T get(int index) {
    //    Node t = head;
    //    for(int i=0; i<=index; i++) {
    //        t = t.next;
    //    }
    //    return t.data;
    //}


    /**
     * 迭代器
     */
    public Iterator<T> iterator() {
        return new MySingleListIterator();
    }
    private class MySingleListIterator implements Iterator<T> {
        private Node t;
        public MySingleListIterator() {
            this.t = head;
        }
        @Override
        public boolean hasNext() {
            return t.next != null;
        }

        @Override
        public T next() {
            t = t.next;
            return t.data;
        }
    }
}



/**
 * 单向链表测试
 */
class SingleLinkedListTest {
    public static void main(String[] args) throws Exception {
        SingleLinkedList<Integer> linkedList = new SingleLinkedList<Integer>();
        linkedList.insertByTail(11);
        linkedList.insertByTail(22);
        linkedList.insertByTail(33);
        linkedList.insertByTail(44);

        //linkedList.clear();
        //linkedList.remove(44);

        //System.out.println(linkedList.get(2)); //获取索引下标为2的元素
        //System.out.println(linkedList.getTail()); //获取尾部元素
        //System.out.println(linkedList.length());

        Iterator<Integer> it = linkedList.iterator();
        while(it.hasNext()) {
            System.out.println(it.next());
        }
        System.out.println(".......");
        linkedList.reverse(); //反转
        Iterator<Integer> it01 = linkedList.iterator();
        while(it01.hasNext()) {
            System.out.println(it01.next());
        }
    }

}