package com.hackyle.ds.a_linear_list.list;

/**
 * 快慢指针判断是否有环
 */
public class CheckLoopByFastSlowPointer {
    public static void main(String[] args) throws Exception {
        Node<String> first = new Node<String>("aa", null);
        Node<String> second = new Node<String>("bb", null);
        Node<String> third = new Node<String>("cc", null);
        Node<String> fourth = new Node<String>("dd", null);
        Node<String> fifth = new Node<String>("ee", null);
        Node<String> six = new Node<String>("ff", null);
        Node<String> seven = new Node<String>("gg", null);

        first.next = second;
        second.next = third;
        third.next = fourth;
        fourth.next = fifth;
        fifth.next = six;
        six.next = seven;
        //产生环
        seven.next = third;

        boolean circle = isCircle(first);
        System.out.println("first链表中是否有环："+circle);
    }

    public static boolean isCircle(Node<String> first) {
        //定义快慢指针
        Node<String> fast = first;
        Node<String> slow = first;

        //遍历链表，如果快慢指针指向了同一个结点，那么证明有环
        while(fast!=null && fast.next!=null){
            //变换fast和slow
            fast = fast.next.next;
            slow = slow.next;

            if (fast.equals(slow)){
                return true;
            }
        }

        return false;
    }

    private static class Node<T> {
        T data;
        Node<T> next;
        public Node(T data, Node<T> next) {
            this.data = data;
            this.next = next;
        }
    }
}
