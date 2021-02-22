package map;

/**
 * 无序链式存储的Map
 */
public class DisorderLinkedMap<K, V> {
    private Node head;
    private int N;

    /*节点*/
    private class Node {
        private K key;
        private V value;
        private Node next;
        public Node(K key, V value, Node next) {
            this.key = key;
            this.value = value;
            this.next = next;
        }
    }

    /*构造器*/
    public DisorderLinkedMap() {
        head = new Node(null,null,null);
        N = 0;
    }

    //增加：
    // 如果Map中存在了该Key，则直接替换Value即可
    // 如果key不存在，则新增一个节点

    public void put(K key, V value) {
        //检测key是否已经存在
        Node tmp = head.next;
        while(tmp != null) {
            if(tmp.key.equals(key)) {
                tmp.value = value;
                return; //本次put已经完成，不用再执行下去了
            }
            tmp = tmp.next;
        }

        //key不存在，则直接插入到该链表的头部（头插法：原因是使用尾插法需要对全链表进行遍历）
        Node oldHead = head;
        oldHead.next = new Node(key, value, head.next);

        N++;
    }

    public V get(K key) {
        Node tmp = head.next;
        while(tmp != null) {
            if(key.equals(tmp.key)) {
                return tmp.value;
            }
            tmp = tmp.next;
        }
        return null;
    }

    public void remove(K key) {
        Node tmp = head.next;
        Node post = head;
        while(tmp != null) {
            if(tmp.key.equals(key)) { //找到要删除的位置
                post.next = tmp.next;
                N--;
                return;
            }
            post = tmp;
            tmp = tmp.next;
        }
    }

    public int size() {
        return this.N;
    }

    public void print() {
        Node tmp = head.next;
        while(tmp != null) {
            System.out.println(tmp.key+"-"+tmp.value);
            tmp = tmp.next;
        }
    }
}

class DisorderLinkedMapTest {
    public static void main(String[] args) throws Exception {
        DisorderLinkedMap<String,String> myMap = new DisorderLinkedMap<>();
        myMap.put("aa","aaaa");
        myMap.put("bb","bbbb");
        myMap.put("vv","vvvv");
        myMap.put("ff","ffff");

        myMap.remove("vv");
        myMap.print();
        System.out.println(myMap.size());
    }

}
