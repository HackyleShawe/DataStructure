package d_stack;

import java.util.Iterator;


/**
 * 链式栈：栈 + 单链表
 */
public class MyStack<T> implements Iterable<T>  {
    private Node<T> top; //栈顶
    private Long N; //个数

    public MyStack() {
        top = null;
        N = 0L;
    }

    /* 栈元素 */
    private class Node<T> {
        T data;
        Node next;
        public Node(T data, Node next) {
            this.data = data;
            this.next = next;
        }
    }

    /* 入栈：单链表的头插法 */
    public void push(T t) {
        Node<T> newNode = new Node(t,null);
        if(top == null) {
            top = newNode;
        } else {
            newNode.next = top;
            top = newNode;
        }
    }

    /* 出栈 */
    public T pop() {
        if(isEmpty()) {
            return null;
        }
        T result = top.data;
        top = top.next;
        return  result;
    }

    /* 判空 */
    public boolean isEmpty() {
        return N==0 || top == null;
    }

    /* 栈遍历 */
    @Override
    public Iterator<T> iterator() {
        return new StackIterator();
    }
    private class StackIterator implements Iterator<T> {
        private Node<T> t;
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

class MyStackTest {
    public static void main(String[] args) throws Exception {
        MyStack<String> stack = new MyStack<String>();
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