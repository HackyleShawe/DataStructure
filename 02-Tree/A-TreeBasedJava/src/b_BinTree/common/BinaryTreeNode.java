package b_BinTree.common;

/**
 * 树节点定义
 */
public class BinaryTreeNode {
    /** 节点元素 */
    private String data;
    /** 左子树 */
    private BinaryTreeNode left;
    /** 右子树 */
    private BinaryTreeNode right;

    public BinaryTreeNode() {
    }

    public BinaryTreeNode(String data, BinaryTreeNode left, BinaryTreeNode right) {
        this.data = data;
        this.left = left;
        this.right = right;
    }

    public String getData() {
        return data;
    }

    public void setData(String data) {
        this.data = data;
    }

    public BinaryTreeNode getLeft() {
        return left;
    }

    public void setLeft(BinaryTreeNode left) {
        this.left = left;
    }

    public BinaryTreeNode getRight() {
        return right;
    }

    public void setRight(BinaryTreeNode right) {
        this.right = right;
    }
}
