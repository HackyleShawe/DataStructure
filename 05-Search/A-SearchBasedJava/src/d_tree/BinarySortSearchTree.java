package d_tree;

/**
 * 二叉查找排序树
 */
public class BinarySortSearchTree<K extends Comparable<K>, V> {
    private Node root; //根节点
    private Long N; //节点的个数

    /*树的节点*/
    private class Node {
        private K key; //该节点的键
        private V value; //该节点的值
        private Node left; //左子树
        private Node right; //右子树
        public Node(K key, V value, Node left, Node right) {
            this.key = key;
            this.value = value;
            this.left = left;
            this.right = right;
        }
    }

    /*增*/
    public void put(K key, V value) {
        root = putElement(root,key,value);
    }
    private Node putElement(Node node, K key, V value) {
        //如果树为空，则新建一个树结点返回
        if(node == null) {
            return new Node(key, value, null, null);
        }

        //比较要插入的结点和树结点的大小，从而确定应该插入的位置
        int cmp = key.compareTo(node.key);
        if(cmp>0) { //插入的结点值要大，则继续找该树的右子树
            node.right = putElement(node.right, key, value);
        } else if(cmp <0) { //插入的节点值要小，则继续找该树的左子树
            node.left = putElement(node.left, key, value);
        } else { //插入的节点值等于该树当前的结点值，则替换(这就是二叉查找树的修改操作)
            node.value = value;
        }
        return node;
    }

    /*查*/
    public V get(K key) {
        return getElement(root,key);
    }
    private V getElement(Node node, K key) {
        //如果当前树结点为空，则返回null
        if(node == null) {
            return null;
        }

        //如果当前树结点不为空
        int cmp = key.compareTo(node.key);
        if(cmp > 0) { //要查找的值大于当前结点的值，则继续向右子树查找
            return getElement(node.right,key);
        } else if(cmp <0) { //要查找的值小于当前结点的值，则继续向左子树查找
            return getElement(node.left,key);
        } else { //找到要查找的值
            return node.value;
        }
    }

    /*删*/
    public void delete(K key) {
        deleteElement(root,key);
    }
    private Node deleteElement(Node node, K key) {
        if(node == null) { //如果当前树结点为空，则返回null
            return null;
        }

        //如果当前树结点不为空
        int cmp = key.compareTo(node.key);
        if(cmp > 0) { //要查找的值大于当前结点的值，则继续向右子树查找
            node.right = deleteElement(node.right, key);
        } else if(cmp <0) { //要查找的值小于当前结点的值，则继续向左子树查找
            node.left = deleteElement(node.left, key);
        } else { //找到要删除的结点，把该结点的左子树最大或右子树最小结点取下，放在要删除的位置
            if(node.right == null) { //要删除的结点没有右子树，则直接把左子树取下放在将要删除的位置
                return node.left;
            }
            if(node.left == null) { //要删除的结点没有左子树，则直接把右子树取下放在将要删除的位置
                return node.right;
            }

            //左右子树都不为空：则找右子树的最左结点(右子树中最左的结点为最小值)，取下后放置到将要删除的位置
            Node minNode = node.right; //找右子树的最左结点
            while(minNode.left!=null){
                minNode = minNode.left;
            }

            Node tmp = node.right; //删除右子树中最小的结点
            while(tmp.left != null){
                //当前节点的下一个左节点的下一个左节点为空，则说明到了倒数第二个节点了
                if (tmp.left.left==null){
                    tmp.left=null;
                }else{
                    tmp = tmp.left;
                }
            }

            //把右子树中最小的结点放置在将要删除的结点位置
            minNode.left = node.left;
            minNode.right = node.right;
            node = minNode;
        }
        return node;
    }
}

class BinarySortSearchTreeTest {
    public static void main(String[] args) throws Exception {
        BinarySortSearchTree<Integer,String> binaryTree = new BinarySortSearchTree<>();
        binaryTree.put(20,"bbb"); //注意，插入的顺序决定是否能够一颗排序二叉树，例如：3,1,2暂时构不成一棵排序二叉树
        binaryTree.put(30,"cccc");
        binaryTree.put(10,"aaaa");

        System.out.println(binaryTree.get(10));
        System.out.println(binaryTree.get(20));
        binaryTree.delete(30);
        System.out.println(binaryTree.get(30));

    }

}