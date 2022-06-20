
import org.junit.jupiter.api.Test;

import java.util.Iterator;

/**
 * 双向循环链表(带头结点)
 * 注意：不带头结点的双向循环链表非常难以处理一些特殊情况，以后都使用带头结点的链表，方便标识当前链表
 */
public class CycleDoubleLinkedListWithHead<T> {
    private Node head;
    private Integer N;

    /** 节点定义 */
    private class Node {
        T data;
        Node pre;
        Node next;
        public Node(T data, Node pre, Node next) {
            this.data = data;
            this.pre = pre;
            this.next = next;
        }
    }

    /**
     * 构造器
     */
    public CycleDoubleLinkedListWithHead() {
        this.head = new Node(null,null,null);
        this.N = 0;
    }

    /**
     * 尾插法插入数据
     * @param data 待插入的数据
     */
    public void add(T data) {
        if(head.next == null) {
            head.next = new Node(data, head, head);
            head.pre = head;
        } else {
            Node tmp = head.next;
            Node pre = head;
            while(tmp.next != head) {
                pre = tmp;
                tmp = tmp.next;
            }
            tmp.next = new Node(data,pre,head);
        }
        this.N++;
    }

    /**
     * 迭代器
     */
    public Iterator<T> iterator() {
        return new ListIt();
    }
    private class ListIt implements Iterator<T> {
        Node tmp = head.next;
        @Override
        public boolean hasNext() {
            return tmp != head;
        }
        @Override
        public T next() {
            T d = tmp.data;
            tmp = tmp.next;
            return d;
        }
    }

    /**
     * 打印链表
     */
    public void print() {
        Node tmp = head.next;
        while(tmp != head) {
            System.out.print(tmp.data + "  ");
            tmp = tmp.next;
        }
    }
}



class CycleDoubleLinkedListWithHeadTest {
    @Test
    public void test01() {
        CycleDoubleLinkedListWithHead<Integer> doubleList = new CycleDoubleLinkedListWithHead<>();
        doubleList.add(11);
        doubleList.add(22);
        doubleList.add(33);

        doubleList.print();
        System.out.println();

        Iterator<Integer> iterator = doubleList.iterator();
        while (iterator.hasNext()) {
            System.out.print(iterator.next() + "  ");
        }
    }
}