package b_BinTree.read;

import b_BinTree.common.AbstractBinaryTree;
import b_BinTree.common.BinaryTreeNode;
import b_BinTree.create.PreTraverseRecursionCreateOne;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Stack;

/**
 * 遍历二叉树：非递归实现
 */
public class NonRecursionTraverse {

    /**
     * <p>Function: 非递归实现前序遍历二叉树</p>
     * <p>algorithm: </p>
     * <p>1、先申请一个新的栈，记为stack</p>
     * <p>2、然后将头节点head压入stack中</p>
     * <p>3、每次从stack中弹出栈顶节点，记为cur，先打印cur节点的值，再判断：</p>
     *    <p>如果cur的右孩子不为空的话，将cur的右孩子先压入stack中；</p>
     *    <p>如果cur的左孩子不为空的话，将cur的左孩子压入stack中。</p>
     * <p>4、不断重复步骤3，直到stack为空，全部过程结束</p>
     *
     * @param node 二叉树的根节点
     */
    public void preTraverse(BinaryTreeNode node) {
        Stack<BinaryTreeNode> stack = new Stack<>();
        stack.push(node);
        while(!stack.isEmpty()) {
            BinaryTreeNode cur = stack.pop();
            System.out.print(cur.getData() + " ");

            //注意，必须是先压入右孩子，再压如左孩子；因为前序遍历是根左右
            if(cur.getRight() != null) {
                stack.push(cur.getRight());
            }
            if(cur.getLeft() != null) {
                stack.push(cur.getLeft());
            }
        }
    }


    /**
     * <p>Function: 非递归实现中序遍历二叉树</p>
     *
     * @param node 二叉树的根节点
     */
    public void middleTraverse(BinaryTreeNode node) {

    }


    /**
     * <p>Function: 非递归实现后序遍历二叉树</p>
     *
     * @param node 二叉树的根节点
     */
    public void postTraverse(BinaryTreeNode node) {

    }
}


/**
 * 测试：非递归创建的二叉树
 */
class NonRecursionTraverseTest {
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
        AbstractBinaryTree binaryTree = createBinaryTree(); //创建二叉树
        BinaryTreeNode root = binaryTree.getNode(); //获取根节点

        NonRecursionTraverse nonRecursionTraverse = new NonRecursionTraverse();
        System.out.println("前序遍历：");
        nonRecursionTraverse.preTraverse(root);

    }
}