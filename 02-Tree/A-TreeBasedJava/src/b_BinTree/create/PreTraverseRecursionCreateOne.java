package b_BinTree.create;

import b_BinTree.common.AbstractBinaryTree;
import b_BinTree.common.BinaryTreeNode;

import java.util.ArrayList;
import java.util.Arrays;

/**
 * 创建二叉树：使用前序递归遍历的思想
 */
public class PreTraverseRecursionCreateOne extends AbstractBinaryTree {
    /** 在创建节点时，保存节点数组的索引 */
    private int index;

    /**
     * 构造器
     */
    public PreTraverseRecursionCreateOne() {
        node = new BinaryTreeNode();
        N = 0;
        index = 0;
    }

    /**
     * <p>Function：根据前序遍历的思想创建链式的二叉树 </p>
     *
     * @param nodeList 二叉树的前序遍历序列
     */
    @Override
    public void createBinaryTree(ArrayList<String> nodeList) {
        //入参校验
        if(nodeList == null || nodeList.isEmpty()) {
            System.out.println("记录日志：入参为空");
            return;
        }

        node = createByPreTraverse(node, nodeList);
    }

    /**
     * <p>Function：根据前序遍历的思想，以递归的方式创建链式二叉树</p>
     * <p>Notice: 据前序遍历来创建二叉树，必须输入二叉树的前序遍历序列</p>
     *
     * @param node 节点
     * @param preTraverseList 二叉树的前序遍历序列
     * @return 二叉树创建完毕后的根节点
     */
    private BinaryTreeNode createByPreTraverse(BinaryTreeNode node, ArrayList<String> preTraverseList) {
        /*
         * 用#表示当前节点为NULL
         */
        if("#".equals(preTraverseList.get(index))) { //#表明此节点为NULL
            return null;
        } else {
            node.setData(preTraverseList.get(index));
            N++;
        }

        /*
         * 左子树
         */
        BinaryTreeNode leftChild = new BinaryTreeNode();
        index++;
        node.setLeft(createByPreTraverse(leftChild, preTraverseList));

        /*
         * 右子树
         */
        BinaryTreeNode rightChild = new BinaryTreeNode();
        index++;
        node.setRight(createByPreTraverse(rightChild, preTraverseList));

        return node;
    }

}

/**
 * 测试类：测试前序遍历的方式创建二叉树
 */
class PreTraverseRecursionOneTest {
    /**
     * <p>测试用的二叉树示意图：</p>
     * <pre>
     *            A
     *      B           C
     *  D       F      # #
     * # E    G  #
     *  # #  # #
     *  </pre>
     */
    public static void main(String[] args) {
        //ABD#E##FG###C##
        String[] nodeArray = "A,B,D,#,E,#,#,F,G,#,#,#,C,#,#".split(",");
        ArrayList<String> preTraverseList = new ArrayList<>(Arrays.asList(nodeArray));

        PreTraverseRecursionCreateOne binaryTree = new PreTraverseRecursionCreateOne();
        binaryTree.createBinaryTree(preTraverseList);
        System.out.println("将断点打到此行代码，查看binaryTree的链式结构是否是自己想要的二叉树结构");
    }
}

