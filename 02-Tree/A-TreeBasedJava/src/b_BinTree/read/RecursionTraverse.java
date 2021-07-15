package b_BinTree.read;

import b_BinTree.common.AbstractBinaryTree;
import b_BinTree.common.BinaryTreeNode;
import b_BinTree.create.PreTraverseRecursionCreateOne;

import java.util.ArrayList;
import java.util.Arrays;

/**
 * <p>二叉树的递归遍历</p>
 * <p>前序递归、中序递归、后序递归</p>
 */
public class RecursionTraverse {

    /**
     * 递归方式：前序遍历
     */
    public void preTraverse(BinaryTreeNode node) {
        if(node == null) {
            return;
        }

        System.out.print(node.getData() + " ");
        preTraverse(node.getLeft());
        preTraverse(node.getRight());
    }


    /**
     * 递归方式：中序遍历
     */
    public void middleTraverse(BinaryTreeNode node) {
        if(node == null) {
            return;
        }

        middleTraverse(node.getLeft());
        System.out.print(node.getData() + " ");
        middleTraverse(node.getRight());
    }


    /**
     * 递归方式：后序遍历
     */
    public void postTraverse(BinaryTreeNode node) {
        if(node == null) {
            return;
        }

        postTraverse(node.getLeft());
        postTraverse(node.getRight());
        System.out.print(node.getData() + " ");
    }

}


/**
 * 测试：二叉树的递归遍历
 */
class RecursionTraverseTest {

    /**
     * <p>Function：生成一个二叉树</p>
     * <pre>
     * 测试用的二叉树示意图：
     *            A
     *      B           C
     *  D       F      # #
     * # E    G  #
     *  # #  # #
     * </pre>
     */
    public static AbstractBinaryTree createBinaryTree() {
        //ABD#E##FG###C##
        String[] nodeArray = "A,B,D,#,E,#,#,F,G,#,#,#,C,#,#".split(",");
        ArrayList<String> preTraverseList = new ArrayList<>(Arrays.asList(nodeArray));

        AbstractBinaryTree binaryTree = new PreTraverseRecursionCreateOne();
        binaryTree.createBinaryTree(preTraverseList);
        //System.out.println("将断点打到此行代码，查看binaryTree的链式结构是否是自己想要的二叉树结构");
        return binaryTree;
    }

    /**
     * 测试
     */
    public static void main(String[] args) {
        //生成一个二叉树
        AbstractBinaryTree binaryTreeRoot = createBinaryTree();
        RecursionTraverse recursionTraverse = new RecursionTraverse();

        System.out.println("前序遍历：");
        BinaryTreeNode root01 = binaryTreeRoot.getNode();
        recursionTraverse.preTraverse(root01);

        System.out.println("\n中序遍历：");
        BinaryTreeNode root02 = binaryTreeRoot.getNode();
        recursionTraverse.middleTraverse(root02);

        System.out.println("\n后序遍历：");
        BinaryTreeNode root03 = binaryTreeRoot.getNode();
        recursionTraverse.postTraverse(root03);
    }
}