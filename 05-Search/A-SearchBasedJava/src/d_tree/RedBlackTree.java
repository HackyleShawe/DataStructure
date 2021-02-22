package d_tree;

import com.sun.jdi.Value;

/**
 * 红黑树(基于二叉排序树和2-3树)
 */
public class RedBlackTree<Key extends Comparable<Key>, Value> {
    private Node root; //根节点
    private int N; //节点个数

    //红黑树节点的定义
    private class Node {
        public Key key;
        public Value value;
        public Node left;
        public Node right;
        public boolean parentLinkThisNodeIsRed; //由其父结点指向它的链接的颜色
        public Node(Key key, Value value, Node left, Node right, boolean linkChildIsRed) {
            this.key = key; this.value = value; this.left = left;
            this.right = right; this.parentLinkThisNodeIsRed = linkChildIsRed;
        }
    }

    /**
     * 红黑树的元素个数
     * @return 元素个数
     */
    public int size() {
        return N;
    }

    /**
     * 判断node节点与父节点的 链接 是否为红色
     * @return true:确为红色；false:为黑色
     */
    private boolean linkWithParentIsRed(Node node) {
        if(node == null) {
            return false;
        }
        return node.parentLinkThisNodeIsRed;
    }

    /**
     *
     * high：左旋之前较高的节点；low：左旋之前较低的节点
     * @return
     */
    private Node rotateLeft(Node high) {
        Node low = high.right; //取得high节点的右子节点
        high.right = low.left;
        low.left = high;
        low.parentLinkThisNodeIsRed = high.parentLinkThisNodeIsRed; //右斜红链接变为左斜红链接
        high.parentLinkThisNodeIsRed = true;

        return low; //因为左旋完成后，原来较低的节点会上去成为较高节点
    }

    private Node rotateRight(Node high) {
        Node low = high.left;
        high.left = low.right;
        low.right = high;
        low.parentLinkThisNodeIsRed = high.parentLinkThisNodeIsRed;
        high.parentLinkThisNodeIsRed = true;

        return low; //因为右旋完成后，原来较低的节点会上去成为较高的节点
    }

    /**
     * 颜色反转
     * @param node 对node节点的红链接变为黑链接，黑链接变为红链接
     */
    private void flipColor(Node node) {
        node.parentLinkThisNodeIsRed = true;
        node.left.parentLinkThisNodeIsRed = false;
        node.right.parentLinkThisNodeIsRed = false;
    }

    /**
     * 值的插入操作(插入一个键值对)
     * @param key
     * @param value
     */
    public void put(Key key, Value value) {
        root = put(root,key,value);
        //根结点的颜色总是黑色
        root.parentLinkThisNodeIsRed = false;
    }

    private Node put(Node node, Key key, Value value) {
        //如果为空则直接返回一个红色的结点就可以了
        if(node == null) {
            N++;
            return new Node(key,value,null,null,true);
        }

        //比较：待插入元素的值与node的值
        int cmp = key.compareTo(node.key);
        if(cmp<0) { //待插入的元素值较小，继续往左找
            node.left = put(node.left,key,value);
        } else if(cmp>0) { //待插入的元素值较大，继续往右找
            node.right = put(node.right,key,value);
        } else { //找到了一样的，则直接替换
            node.value = value;
        }

        //进行左旋:当前结点node的左子结点为黑色，右子结点为红色，需要左旋
        if (linkWithParentIsRed(node.right) && !linkWithParentIsRed(node.left)){
            node = rotateLeft(node);
        }
        //进行右旋：当前结点node的左子结点和左子结点的左子结点都为红色，需要右旋
        if (linkWithParentIsRed(node.left) && linkWithParentIsRed(node.left.left)){
            rotateRight(node);
        }
        //颜色反转：当前结点的左子结点和右子结点都为红色时，需要颜色反转
        if (linkWithParentIsRed(node.left) && linkWithParentIsRed(node.right)){
            flipColor(node);
        }

        return node;
    }

    /**
     * 根据key，从树中找出对应的值
     * @param key 根据key查找
     * @return key对应的值
     */
    public Value get(Key key) {
        return get(root,key);
    }
    private Value get(Node node, Key key) {
        if(node == null) {
            return null;
        }

        int cmp = key.compareTo(node.key); //比较待查找的key与当前节点的key
        if(cmp < 0 ) { //待查找的值更小，继续向左查找
            return get(node.left,key);
        } else if(cmp > 0) { //待查找的值更大，继续向右查找
            return get(node.right, key);
        } else { //找到了
            return node.value;
        }
    }

}

class RedBlackTreeTest {
    public static void main(String[] args){
        RedBlackTree<Integer,String> redBlackTree = new RedBlackTree<>();
        redBlackTree.put(33,"前田可奈子");
        redBlackTree.put(24,"枫力恋");
        redBlackTree.put(55,"波多老师");
        redBlackTree.put(19,"桃乃木香奈");
        //注意：插入的顺序不一定能构成一个二叉查找树
        //例如：33 24 55 19 20目前还构不成一个二叉查找树

        System.out.println(redBlackTree.get(19));
        redBlackTree.put(19,"衣吹花音");
        System.out.println(redBlackTree.get(19));

        System.out.println(redBlackTree.size());
    }

}