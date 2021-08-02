package tree;

import java.util.Random;
import java.util.UUID;

/**
 * 二叉排序树：在二叉排序查找树的基础上，进行中序遍历(左根右)就是一个递增的序列
 */
public class BinarySortTree<Key extends  Comparable<Key>, Value> {
    /** 根节点 */
    private Node root;
    /** 节点个数 */
    private int N;

    /**
     * 节点定义
     */
    private class Node {
        /** 进行排序的键 */
        public Key key;
        /** 存储业务的值 */
        public Value value;
        public Node left;
        public Node right;
        public Node(Key key, Value value, Node left, Node right) {
            this.key = key; this.value = value;
            this.left = left; this.right = right;
        }
    }

    /**
     * 构造器
     */
    public BinarySortTree() {
        root = null;
        N = 0;
    }

    /**
     * 插入操作
     */
    public void put(Key key, Value value) {
        root = putElement(root,key,value);
    }
    private Node putElement(Node node, Key key, Value value) {
        if(node == null) {
            N++;
            return new Node(key,value,null,null);
        }
        int cmp = key.compareTo(node.key);
        if(cmp>0) { //要插入的值大于当前节点，则需要在当前节点的右子树继续找
            node.right = putElement(node.right, key, value);
        } else if(cmp<0) { //要插入的值小于当前节点，则需要在当前节点的左子树中继续找
            node.left = putElement(node.left, key, value);
        } else {
            node.value = value;
        }
        return node;
    }

    /**
     * 获取操作
     */
    public Value get(Key key) {
        return getElement(root,key);
    }
    private Value getElement(Node node, Key key) {
        if(node == null) {
            return null;
        }
        int cmp = key.compareTo(node.key);
        if(cmp > 0) { //要查找的节点值大于当前节点，则需要继续向当前节点的右子树继续查找
            return getElement(node.right, key);
        } else if(cmp < 0) {
            return getElement(node.left, key);
        } else {
            return node.value;
        }
    }

    /**
     * 删除操作
     */
    public void delete(Key key) {
        deleteElement(root, key);
    }
    public Node deleteElement(Node node, Key key) {
        if(node == null) {
            return  null;
        }
        int cmp = key.compareTo(node.key);
        if(cmp > 0) { //要删除的值大于当前节点的值，则继续向当前节点的右子树中查找
            node.right = deleteElement(node.right, key);
        } else if(cmp < 0) { //要删除的值小于当前节点的值，则继续向当前节点的左子树中查找
            node.left = deleteElement(node.left, key);
        } else { //找到了
            N--;
            if(node.right == null) {
                return node.left;
            }
            if(node.left == null) {
                return node.right;
            }
            Node minNode = node.right;
            while(minNode.left != null) {
                minNode = minNode.left;
            }

            //删除右子树中最小的节点
            Node tmp = node.right;
            while(node.left != null){
                if(node.left.left == null) {
                    node.left = null;
                } else {
                    node = node.left;
                }
            }

            minNode.left = node.left;
            minNode.right = node.right;
            node = minNode;
        }
        return node;
    }

    /**
     * 元素个数
     */
    public int size() {
        return N;
    }

    /**
     * 找最大的值：最左边的叶子节点
     */
    public Key max(){
        //入参校验
        if(root == null) {
            System.out.println("记录日志：树为空，无法获取max");
            return null;
        }
        return maxElement(root).key;
    }
    private Node maxElement(Node node){
        if (node.right!=null){
            return maxElement(node.right);
        }else{
            return node;
        }
    }

    /**
     * 找最小的值：最右边的叶子节点
     */
    public Key min() {
        //入参校验
        if(root == null) {
            System.out.println("记录日志：树为空，无法获取min");
            return null;
        }
        return minElement(root).key;
    }
    private Node minElement(Node node) {
        if(node.left != null) {
            return minElement(node.left);
        } else {
            return node;
        }
    }

    /**
     * 对二叉排序树进行中序遍历(左根右)就是升序序列
     */
    public void midTravel() {
        midTravel(root);
        System.out.println();
    }
    private void midTravel(Node node) {
        if(node == null) {
            return;
        }
        midTravel(node.left);
        System.out.print(node.key+ ":" +node.value+"  ");
        midTravel(node.right);
    }
}


/**
 * 测试：二叉排序树
 */
class BinarySortTreeTest {
    public static void main(String[] args) {
        Random random = new Random();
        int len = Math.abs(random.nextInt(20));

        BinarySortTree<Integer, String> binaryTree = new BinarySortTree<>();
        for (int i = 0; i < len; i++) {
            binaryTree.put(random.nextInt(100), UUID.randomUUID().toString()); //生成[97,122]之间的随机数
        }

        System.out.println("将断点打至此处，调试模式查看binaryTree是否为自己想要构造的二叉排序查找树");

        System.out.println("MIN: "+binaryTree.min());
        System.out.println("MAX: "+binaryTree.max());

        System.out.println("升序（二叉排序树的中序遍历）：");
        binaryTree.midTravel();
    }
}

