public class MainTest {
    public static void main(String[] args) throws Exception {
        joseph();
    }

    public static void joseph() {
        //构建41个元素的循环单链表
        Node<Integer> head = null; //头
        Node<Integer> post = null; //某节点的上一个节点
        for(int i=1;i<=41;i++) {
            if(i==1) { //首个节点
                head =new Node<Integer>(i,null);
                post = head;
            } else {
                Node<Integer> newNode = new Node<Integer>(i,null);
                post.next = newNode;
                post = newNode;
                if(i==41) { //形成循环的单链表
                    post.next=head;
                }
            }
        }

        int count = 0; //报数
        Node<Integer> tmp = head; //遍历链表
        post = null;
        while(tmp!=tmp.next) {
            count++;
            if(count==3) { //如果是3，则把当前结点删除调用，打印当前结点，重置count=0，让当前结点n后移
                post.next = tmp.next;
                System.out.print(tmp.data+", ");
                count = 0;
                tmp = tmp.next;
            } else {
                post = tmp;
                tmp = tmp.next;
            }
        }
        //打印最后一个元素
        System.out.println(tmp.data);
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
