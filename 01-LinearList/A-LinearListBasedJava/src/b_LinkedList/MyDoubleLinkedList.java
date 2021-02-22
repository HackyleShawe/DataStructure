package b_LinkedList;

import java.util.Iterator;

public class MyDoubleLinkedList<T> implements Iterable<T> {
    private Node head; //头指针
    private Node last; //尾指针
    private long N; //长度

    /*节点*/
    private class Node {
        T data;
        Node next;
        Node pre;

        public Node(T data, Node next, Node pre) {
            this.data = data;
            this.next = next;
            this.pre = pre;
        }
    }

    /*构造器*/
    public MyDoubleLinkedList() {
        this.head = new Node(null,null,null);
        this.last = null;
        this.N = 0;
    }

    /*增*/
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


    /*删*/
    public void clear() {
        this.head.next = null;
        this.head.pre = null;
        this.head = null; //清空头指针
        this.last = null;
        this.N = 0;
    }
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

    /*改*/


    /*查*/
    public long length() {
        return this.N;
    }
    public boolean isEmpty() {
        return N==0;
    }
    public T getHead() {
        if(this.head.next == null) {
            return null;
        }
        return this.head.next.data;
    }
    public T getLast() {
        if(this.last == null) {
            return null;
        }
        return this.last.data;
    }

    /*迭代*/
    @Override
    public Iterator<T> iterator() {
        return new DLIterator();
    }
    private class DLIterator implements Iterator<T> {
        private Node n;
        public DLIterator() {
            this.n = head;
        }
        @Override
        public boolean hasNext() {
            return n.next!=null;
        }

        @Override
        public T next() {
            n = n.next;
            return n.data;
        }
    }

}

class MyDoubleLinkedListTest {
    public static void main(String[] args) throws Exception {
        MyDoubleLinkedList<Integer> linkedList = new MyDoubleLinkedList<Integer>();
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
