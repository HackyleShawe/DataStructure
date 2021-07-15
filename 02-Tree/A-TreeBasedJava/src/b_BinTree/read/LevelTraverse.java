package b_BinTree.read;

import b_BinTree.common.AbstractBinaryTree;
import b_BinTree.common.BinaryTreeNode;
import b_BinTree.create.PreTraverseRecursionCreateOne;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/**
 * 层次遍历：非递归实现
 */
public class LevelTraverse {

    /**
     * <p>Function: 层次遍历非递归实现</p>
     * <p>Algorithm: </p>
     * <li>创建队列，存储每一层的结点；刚开始时把根节点放入队列；</li>
     * <li>使用循环，每次从队列中弹出一个结点：</li>
     * <ol>
     *     <li>获取当前结点的key；</li>
     *     <li>如果当前结点的左子结点不为空，则把左子结点放入到队列中</li>
     *     <li>如果当前结点的右子结点不为空，则把右子结点放入到队列中</li>
     * </ol>
     */
    public List<String> LevelTraverseByNonRecursion(BinaryTreeNode root) {
        Queue<BinaryTreeNode> queue = new LinkedList<>();
        queue.add(root);
        List<String> levelSequence = new ArrayList<>();

        while(!queue.isEmpty()) {
            BinaryTreeNode cur = queue.poll();
            levelSequence.add(cur.getData());
            if(cur.getLeft() != null) {
                queue.add(cur.getLeft());
            }
            if(cur.getRight() != null) {
                queue.add(cur.getRight());
            }
        }

        return levelSequence;
    }

}


class LevelTraverseTest {
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

    public static void main(String[] args) {
        AbstractBinaryTree binaryTree = createBinaryTree(); //创建一个二叉树
        BinaryTreeNode root = binaryTree.getNode(); //获取二叉树的根节点

        LevelTraverse levelTraverse = new LevelTraverse();

        System.out.println("层次非递归遍历：");
        List<String> nonRecursionList = levelTraverse.LevelTraverseByNonRecursion(root);
        for (String ele : nonRecursionList) {
            System.out.print(ele + "  ");
        }
    }
}