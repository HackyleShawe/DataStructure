package d_DirectedGraphs;

import a_graph.creat.DirectedGraphWithAdjacencyList;

import java.util.Stack;

/**
 * 有向图的拓扑排序
 */
public class TopologicalSort {
    private Stack<Integer> order; //排序后的序列

    public TopologicalSort(DirectedGraphWithAdjacencyList graph) {
        DirectGraphCycle graphCycle = new DirectGraphCycle(graph); //检测改图是否有环
        if(!graphCycle.isHasCycle()) { //该图不存在环，才进行拓扑排序
            GraphOrderByDepthFirst graphOrder = new GraphOrderByDepthFirst(graph);
            order = graphOrder.getReversePost();
        } else { //该图存在环
            order = null; //将排序序列容器置空
        }
    }

    public Stack<Integer> getOrder() {
        return order;
    }
}


/**
 * 有向图的基于深度优先的排序
 */
class GraphOrderByDepthFirst {
    private boolean[] marked; //下标代表顶点，值表示当前顶点是否已经被搜索
    private Stack<Integer> reversePost; //存储顶点序列

    public GraphOrderByDepthFirst(DirectedGraphWithAdjacencyList graph) {
        this.marked = new boolean[graph.getVertex()];
        this.reversePost = new Stack<Integer>();

        //遍历图中的每一个顶点，让每个顶点作为入口，完成一次深度优先搜索
        for (int vertex = 0; vertex < graph.getVertex(); vertex++) {
            if(!marked[vertex]) { //该顶点没有搜索过，则进行一次深度优先搜索
                dfs(graph, vertex);
            }
        }
    }

    /**
     * 基于深度优先搜索，把顶点排序
     * @param graph 对谁搜索
     * @param currentVertex 起始顶点
     */
    private void dfs(DirectedGraphWithAdjacencyList graph, int currentVertex) {
        marked[currentVertex] = true; //标记当前节点已经被搜索

        //循环遍历顶点currentVertex的邻接表，对连接currentVertex顶点的顶点进行搜索
        for (Integer tmpVertex : graph.adj(currentVertex)) {
            if(!marked[tmpVertex]) { //如果还没有被搜索，则进行搜索
                dfs(graph,tmpVertex);
            }
        }
        reversePost.push(currentVertex); //搜索完毕后才入栈
    }

    /**
     * 获取拓扑排序的顶点线性序列
     */
    public Stack<Integer> getReversePost() {
        return reversePost;
    }
}

/**
 * 检测图中是否存在有环（拓扑排序中不需要图中存在环）
 */
class DirectGraphCycle {
    private boolean[] marked; //下标代表顶点，值表示当前顶点是否已经被搜索
    private boolean hasCycle; //是否有环
    private boolean[] metFlag; //下标代表顶点，值代表当前顶点是否已经遇到过(met，meet过去式)

    public DirectGraphCycle(DirectedGraphWithAdjacencyList graph) {
        this.marked = new boolean[graph.getVertex()];
        this.hasCycle = false;
        this.metFlag = new boolean[graph.getVertex()]; //数组默认就是初始化为false

        //遍历图的顶点：让每一个顶点作为入口，调用一次dfs进行搜索
        for(int ver=0; ver< graph.getVertex(); ver++) {
            if(!marked[ver]) { //该顶点还没有搜索过
                dfs(graph,ver); //把图的每一个顶点作为入口，进行深度搜索
            }
        }
    }

    /**
     * 深度搜索
     * @param graph 要搜索的图
     * @param currentVertex 入口顶点
     */
    private void dfs(DirectedGraphWithAdjacencyList graph, int currentVertex) {
        marked[currentVertex] = true; //当前节点已经被搜索过
        metFlag[currentVertex] = true; //当前节点已经被遇到过了

        //遍历每个顶点的邻接表
        for(Integer ver:graph.adj(currentVertex)) {
            //判断如果当前顶点currentVertex没有被搜索过，则继续递归调用dfs方法完成深度优先搜索
            if(!marked[ver]) {
                dfs(graph,ver);
            }
            //判断当前顶点currentVertex是否已经遇到过了，如果为true则说明已经遇到过了，则发生了环，立即返回
            if(metFlag[ver]) {
                hasCycle = true;return;
            }
        }
        metFlag[currentVertex] = false; //以当前节点为起始节点的搜索完成了
    }

    public boolean isHasCycle() {
        return hasCycle;
    }
}


class Test {
    public static void main(String[] args) {
        //准备有向图
        DirectedGraphWithAdjacencyList directedGraph = new DirectedGraphWithAdjacencyList(6);
        directedGraph.addEdge(0,2);
        directedGraph.addEdge(0,3);
        directedGraph.addEdge(2,4);
        directedGraph.addEdge(3,4);
        directedGraph.addEdge(4,5);
        directedGraph.addEdge(1,3);

        TopologicalSort sort = new TopologicalSort(directedGraph);

        Stack<Integer> order = sort.getOrder();
        System.out.print("图的拓扑排序结果：");
        for (int i = order.size(); i > 0 ; i--) {
            System.out.print(order.pop()+ " "); //图的拓扑排序结果：1 0 3 2 4 5
        }
    }

}