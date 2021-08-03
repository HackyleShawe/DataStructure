package b_BinTree.read;

import b_BinTree.common.AbstractBinaryTree;
import b_BinTree.common.BinaryTreeNode;
import b_BinTree.create.PreTraverseRecursionCreateOne;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Stack;
import java.util.function.BinaryOperator;

/**
 * 遍历二叉树：非递归实现
 */
public class NonRecursionTraverse {

    /**
     * <p>Function: 非递归实现前序遍历二叉树</p>
     * <p>algorithm: </p>
     * <ol>
     * <li>准备一个新的栈，记为stack</li>
     * <li>将根节点root压入stack中</li>
     * <li>每次从stack中弹出一个节点，记为cur，先打印cur节点的值；</li>
     *    <ul>
     *    <li>如果cur的右孩子不为空，则将cur的右孩子压入stack；</li>
     *    <li>如果cur的左孩子不为空，则将cur的左孩子压入stack</li>
     *    </ul>
     * <li>不断重复第三步，直到stack为空，则结束</li>
     * </ol>
     * @param node 二叉树的根节点
     */
    public void preTraverseByStack01(BinaryTreeNode node) {
        //入参校验
        if(node == null) {
            System.out.println("记录日志：入参为空");
            return;
        }

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
     * <p>Function: 非递归实现前序遍历二叉树</p>
     * <p>algorithm:</p>
     * <p>使用栈来模拟递归的过程，也即这种方式与递归其实差不多，只是将系统压栈变为了自己压栈。</p>
     * <p>将左子树不断的压入栈，直到null，然后处理栈顶节点的右子树。</p>
     * @param node 二叉树的根节点
     */
    public void preTraverseByStack02(BinaryTreeNode node) {
        //入参校验
        if(node == null) {
            System.out.println("记录日志：入参为空");
            return;
        }

        Stack<BinaryTreeNode> stack = new Stack<>();
        while(node != null || !stack.isEmpty()) {
            while(node != null) {
                System.out.print(node.getData() + " ");
                stack.push(node);
                node = node.getLeft();
            }

            node = stack.pop();
            node = node.getRight();
        }
    }


    /**
     * <p>Function: 非递归实现中序遍历二叉树</p>
     * <ol>
     * <li>申请一个新的栈，记为stack；申请一个变量cur，初始时令cur等于头节点</li>
     * <li>先把cur节点压入栈中，对以cur节点为头的整棵子树来说，依次把整棵树的每个节点的左子树（即以cur为根的树的左边界）压入栈中</li>
     * <li>不断重复步骤2，直到发现cur为空，此时从stack中弹出一个节点，记为node，打印node的值，并让cur=node->right，然后继续重复步骤2</li>
     * <li>当stack为空并且cur为空时，整个过程结束</li>
     * </ol>
     * @param node 二叉树的根节点
     */
    public void middleTraverseByStack01(BinaryTreeNode node) {
        //入参校验
        if(node == null) {
            System.out.println("记录日志：入参为空");
            return;
        }
        BinaryTreeNode cur = node;

        Stack<BinaryTreeNode> stack = new Stack<>();
        while(cur != null || !stack.isEmpty()) { //这段代码的写法很骚，注意体会
            if(cur != null) {
                stack.push(cur);
                cur = cur.getLeft();
            } else {
                cur = stack.pop();
                System.out.print(cur.getData() + " ");
                cur = cur.getRight();
            }
        }
    }

    /**
     * <p>Function: 非递归实现中序遍历二叉树</p>
     * <p>Algorithm: 使用栈来模拟递归的过程，也即这种方式与递归其实差不多，只是将系统压栈变为了自己压栈。</p>
     * <ol>
     * <li>将左子树不断的压入栈，直到null，然后处理栈顶节点的右子树。</li>
     * <li>跟前序遍历的非递归实现很类似。唯一的不同是访问当前节点的时机：前序遍历在入栈前访问，而中序遍历在出栈后访问。</li>
     * </ol>
     * @param node 二叉树的根节点
     */
    public void middleTraverseByStack02(BinaryTreeNode node) {
        //入参校验
        if(node == null) {
            System.out.println("记录日志：入参为空");
            return;
        }

        BinaryTreeNode cur = node;
        Stack<BinaryTreeNode> stack = new Stack<>();
        while(cur != null || !stack.isEmpty()) {
            while(cur != null) {
                stack.push(cur);
                cur = cur.getLeft();
            }

            cur = stack.pop();
            System.out.print(cur.getData() + " ");
            cur = cur.getRight();
        }
    }


    /**
     * <p>Function: 非递归实现后序遍历二叉树</p>
     * <ol>
     *  <li>申请两个栈stack1，stack2，然后将头结点压入stack1中；</li>
     *  <li>从stack1中弹出的节点记为cur，然后先把cur的左孩子压入stack1中，再把cur的右孩子压入stack1中；</li>
     *  <li>在整个过程中，每一个从stack1中弹出的节点都放在第二个栈stack2中；</li>
     *  <li>不断重复步骤2和步骤3，直到stack1为空，过程停止；</li>
     *  <li>从stack2中依次弹出节点并打印，打印的顺序就是后序遍历的顺序；</li>
     * </ol>
     * <p>算法本质：其实就是将先序的中左右变种为中右左，然后在打印的时机将数据存放到栈中，最后依次弹出就是左右中了。</p>
     * @param node 二叉树的根节点
     */
    public void postTraverseByDoubleStack(BinaryTreeNode node) {
        //入参校验
        if(node == null) {
            System.out.println("记录日志：入参为空");
            return;
        }

        Stack<BinaryTreeNode> stack01 = new Stack<>();
        Stack<BinaryTreeNode> stack02 = new Stack<>();

        stack01.push(node);
        while(!stack01.isEmpty()) {
            BinaryTreeNode cur = stack01.pop();
            stack02.push(cur);
            if(cur.getLeft() != null) {
                stack01.push(cur.getLeft());
            }
            if(cur.getRight() != null) {
                stack01.push(cur.getRight());
            }
        }

        while(!stack02.isEmpty()) {
            System.out.print(stack02.pop().getData() + " ");
        }
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
        System.out.println("前序遍历(preTraverseByStack01)：");
        nonRecursionTraverse.preTraverseByStack01(root);
        System.out.println();

        System.out.println("前序遍历(preTraverseByStack02)：");
        nonRecursionTraverse.preTraverseByStack02(root);
        System.out.println();

        System.out.println("中序遍历（middleTraverseByStack01）：");
        nonRecursionTraverse.middleTraverseByStack01(root);
        System.out.println();

        System.out.println("中序遍历（middleTraverseByStack02）：");
        nonRecursionTraverse.middleTraverseByStack02(root);
        System.out.println();

        System.out.println("后序遍历（postTraverseByDoubleStack）：");
        nonRecursionTraverse.postTraverseByDoubleStack(root);

    }
}