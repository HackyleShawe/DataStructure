package b_BinTree.common;

import java.util.ArrayList;

/**
 * <p>定义一个二叉树的抽象类，方便组合、依赖</p>
 * <p>注意：根据面向对象的一些原则，抽象类中存放的是所有子类的共有部分</p>
 */
public abstract class AbstractBinaryTree {
    /** 二叉树的节点 */
    protected BinaryTreeNode node;
    /** 二叉树的元素个数 */
    protected int N;

    /**
     * 获取二叉树的当前节点
     */
    public BinaryTreeNode getNode() {
        return node;
    }
    public void setNode(BinaryTreeNode node) {
        this.node = node;
    }

    public int getN() {
        return N;
    }
    public void setN(int n) {
        N = n;
    }

    /**
     * <p>创建二叉树，入参为ArrayList</p>
     * <p>使用空实现而不适用抽象类的原因是：有些实现类只会重写其中的一个方法</p>
     */
    public void createBinaryTree(ArrayList<String> nodeList) {
        throw new UnsupportedOperationException("严禁直接调用抽象类的createBinaryTree方法，" +
                "应该调用子类已经重写了的此方法");
    }

    /**
     * <p>创建二叉树，入参为数组</p>
     * <p>使用空实现而不适用抽象类的原因是：有些实现类只会重写其中的一个方法</p>
     */
    public void createBinaryTree(String[] nodeArr) {
        throw new UnsupportedOperationException("严禁直接调用抽象类的createBinaryTree方法，" +
                "应该调用子类已经重写了的此方法");
    }

}
