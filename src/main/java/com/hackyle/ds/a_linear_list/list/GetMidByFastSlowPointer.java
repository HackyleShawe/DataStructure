package com.hackyle.ds.a_linear_list.list;

/**
 * 快慢指针获取中间值
 */
public class GetMidByFastSlowPointer {
    public static void main(String[] args) throws Exception {
        Node<String> first = new Node<String>("aa", null);
        Node<String> second = new Node<String>("bb", null);
        Node<String> third = new Node<String>("cc", null);
        Node<String> fourth = new Node<String>("dd", null);
        Node<String> fifth = new Node<String>("ee", null);
        Node<String> six = new Node<String>("ff", null);
        Node<String> seven = new Node<String>("gg", null);

        //完成结点之间的指向
        first.next = second;
        second.next = third;
        third.next = fourth;
        fourth.next = fifth;
        fifth.next = six;
        six.next = seven;

        //查找中间值
        String mid = getMiddle(first);
        System.out.println("中间值为："+mid);
    }

    public static String getMiddle(Node<String> head) {
        Node<String> fast = head;
        Node<String> slow = head;
        while(fast.next!=null && slow.next!=null) {
            fast = fast.next.next;
            slow = slow.next;
        }
        return slow.data;
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
