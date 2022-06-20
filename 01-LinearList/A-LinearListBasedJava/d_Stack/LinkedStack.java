
import java.util.Iterator;


/**
 * 链式栈：栈 + 单链表
 */
public class LinkedStack<T> implements Iterable<T>  {
    /** 栈顶 */
    private Node top;
    /** 栈内元素的个数 */
    private Long N;

    /**
     * 构造器：初始化栈顶指针为null，元素个数为0
     */
    public LinkedStack() {
        top = null;
        N = 0L;
    }

    /**
     * 栈内元素节点的定义
     */
    private class Node {
        /** 节点元素的类型 */
        T data;
        /** 下一个元素的位置 */
        Node next;

        public Node(T data, Node next) {
            this.data = data;
            this.next = next;
        }
    }

    /**
     * 入栈：单链表的头插法
     * @param t 要入栈的元素
     */
    public void push(T t) {
        Node newNode = new Node(t,null);
        if(top == null) {
            top = newNode;
        } else {
            newNode.next = top;
            top = newNode;
        }
    }

    /**
     * 出栈：弹出单链表的头结点
     * @return 出栈前栈顶的元素
     */
    public T pop() {
        if(isEmpty()) {
            return null;
        }
        T result = top.data;
        top = top.next;
        return  result;
    }

    /**
     * 是否为空
     */
    public boolean isEmpty() {
        return N==0 || top == null;
    }

    /**
     * 栈迭代器
     */
    @Override
    public Iterator<T> iterator() {
        return new StackIterator();
    }
    private class StackIterator implements Iterator<T> {
        private Node t;
        public StackIterator() {
            t = top;
        }

        @Override
        public boolean hasNext() {
            return t.next!=null;
        }

        @Override
        public T next() {
            t = t.next;
            return t.data;
        }
    }

}


/**
 * 链式栈测试
 */
class LinkedStackTest {
    public static void main(String[] args) {
        LinkedStack<String> stack = new LinkedStack<String>();
        stack.push("aa");
        stack.push("bb");
        stack.push("CC");

        stack.pop();

        Iterator<String> it = stack.iterator();
        while(it.hasNext()) {
            System.out.println(it.next());
        }
    }

}