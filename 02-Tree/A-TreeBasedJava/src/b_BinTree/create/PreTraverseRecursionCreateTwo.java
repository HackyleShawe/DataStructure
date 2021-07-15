package b_BinTree.create;

import b_BinTree.common.AbstractBinaryTree;
import b_BinTree.common.BinaryTreeNode;

/**
 * 创建二叉树：使用前序递归遍历的思想
 */
public class PreTraverseRecursionCreateTwo extends AbstractBinaryTree {

    /**
     * 构造器
     */
    public PreTraverseRecursionCreateTwo() {
        node = new BinaryTreeNode();
        N = 0;
    }

    /**
     * <p>Function：根据前序遍历的思想创建链式的二叉树 </p>
     * @param nodeArr 前序遍历数组
     */
    @Override
    public void createBinaryTree(String[] nodeArr) {
        //入参校验
        if(nodeArr == null || nodeArr.length == 0) {
            System.out.println("记录日志：入参为空");
            return;
        }
        createByPreTraverse(node, nodeArr, 0);
    }

    /**
     * <p>Function：根据前序遍历的思想，以递归的方式创建链式二叉树</p>
     * <p>Notice: 据前序遍历来创建二叉树，必须输入二叉树的前序遍历序列</p>
     *
     * @param node 节点
     * @param preTraverseArr 前序遍历序列
     * @param index 当前的节点在序列中的索引
     */
    public int createByPreTraverse(BinaryTreeNode node, String[] preTraverseArr, int index) {
        if ("#".equals(preTraverseArr[index]))
            return index + 1;

        node.setData(preTraverseArr[index]);
        N++;

        node.setLeft(new BinaryTreeNode());
        int left = createByPreTraverse(node.getLeft(), preTraverseArr, index + 1);

        node.setRight(new BinaryTreeNode());
        int right = createByPreTraverse(node.getRight(), preTraverseArr, left);

        return right;
    }

}


/**
 * 测试类：测试前序遍历的方式创建二叉树
 */
class PreTraverseRecursionTwoTest {
    /**
     * <p>测试用的二叉树示意图：</p>
     * <pre>
     *       A
     *    B    C
     *   D #  # E
     *  # #    # #
     *  </pre>
     */
    public static void main(String[] args) {
        String[] nodeArray = "A,B,D,#,#,#,C,#,E,#,#".split(",");

        PreTraverseRecursionCreateTwo binaryTree = new PreTraverseRecursionCreateTwo();
        binaryTree.createBinaryTree(nodeArray);
        System.out.println("将断点打到此行代码，查看binaryTree的链式结构是否是自己想要的二叉树结构");
    }
}