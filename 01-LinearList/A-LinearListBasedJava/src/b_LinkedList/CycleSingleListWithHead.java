import org.junit.jupiter.api.Test;

import java.util.Iterator;

/**
 * 带头结点的循环单链表
 */
public class CycleSingleListWithHead<T> {
    private final Node head; //头结点
    private Integer N; //元素个数

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
     * 构造器，初始化头结点
     */
    public CycleSingleListWithHead() {
        this.head = new Node(null,null); //头结点
        this.N = 0;
    }

    /**
     * 头插法
     * @param data 待插入的数据
     */
    public void addInHead(T data) {
        if(head.next == null) { //此时链表为空
            head.next = new Node(data,head);
        } else {
            Node tmp = head.next;
            head.next = new Node(data,tmp);
        }
        this.N++;
    }

    /**
     * 尾插法
     * @param data 待插入的数据
     */
    public void addInTail(T data) {
        if(head.next == null) {
            head.next = new Node(data,head);
        } else {
            Node tmp = head.next;
            while(tmp.next != head) {
                tmp = tmp.next;
            }
            tmp.next = new Node(data,head);
        }
        this.N++;
    }

    /**
     * 获取链表中元素个数
     */
    public Integer size() {
        return this.N;
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
     * 从头打印链表
     */
    public void print() {
        Node tmp = head.next;
        while(tmp != head) {
            System.out.println(tmp.data);
            tmp = tmp.next;
        }
    }
}



/**
 * 测试
 */
class CycleSingleListWithHeadTest {

    /**
     * 测试头插法、尾巴插法
     */
    @Test
    public void test01() {
        CycleSingleListWithHead<Integer> singleList01 = new CycleSingleListWithHead<>();
        singleList01.addInHead(11);
        singleList01.addInHead(22);
        singleList01.addInHead(33);

        singleList01.print();

        CycleSingleListWithHead<Integer> singleList02 = new CycleSingleListWithHead<>();
        singleList02.addInTail(11);
        singleList02.addInTail(22);
        singleList02.addInTail(33);

        singleList02.print();
        System.out.println(singleList02.size());

        System.out.println("迭代器遍历：");
        Iterator<Integer> iterator = singleList01.iterator();
        while (iterator.hasNext()) {
            System.out.println(iterator.next());
        }
    }

}