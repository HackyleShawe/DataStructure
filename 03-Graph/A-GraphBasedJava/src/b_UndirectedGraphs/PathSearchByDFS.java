package b_UndirectedGraphs;

import a_graph.creat.UndirectedGraphWithAdjacencyList;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Stack;

/**
 * 路径搜索：A顶点与B顶点之间是否存在一条路径，即是否连通
 */
public class PathSearchByDFS {
    private boolean[] marked; //数组下标代表顶点，值表示当前顶点是否已经被搜索
    private int start; //搜索的起点
    private int[] edgeTo; //数组下标代表顶点，值道标从起点start到当前顶点路径上的最后一个顶点

    /**
     * 构造器
     * @param graph 图
     * @param start 从哪个节点开始搜索
     */
    public PathSearchByDFS(UndirectedGraphWithAdjacencyList graph, int start) {
        this.marked = new boolean[graph.getVertex()]; //初始化当前顶点是否被搜索过的标记数组
        this.start = start;
        this.edgeTo = new int[graph.getVertex()];
        dfs(graph,start); //深度优先搜索
    }

    /**
     * 使用深度优先搜索找出graph图中start顶点的所有相通顶点
     * @param graph 图
     * @param start 起始搜索顶点
     */
    private void dfs(UndirectedGraphWithAdjacencyList graph, int start) {
        marked[start] = true; //把顶点start标记为已被搜索

        //遍历邻接表，判断顶点start有没有被搜索过。如果没有，则递归调用dfs
        for(Integer ver: graph.adj(start)) {
            if(!marked[ver]) { //如果顶点还没有被搜索过
                //System.out.print(ver+"  "); //打印出遍历顶点
                edgeTo[ver] = start; //到达顶点ver的路径上最后一个顶点是start
                dfs(graph,ver);
            }
        }
    }

    /**
     * 判断起始搜索顶点start是否与vertex顶点是否存在路径
     */
    public boolean hasPathTo(int vertex) {
        return marked[vertex];
    }

    //找出从起点start到顶点ver的路径(就是该路径经过的顶点)
    public Stack<Integer> pathTo(int ver) {
        if(!hasPathTo(ver)) {
            return null;
        }

        Stack<Integer> path = new Stack<>(); //创建栈对象，保存路径中的所有顶点
        //在辅助数组edgeTo中，从顶点ver开始，知道找到起点为止
        for (int tmp = ver; tmp != start; tmp=edgeTo[tmp]) {
            path.push(tmp);
        }

        path.push(start); //把起点s放到栈中
        return path;
    }
}

class Test {
    public static void main(String[] args) throws  Exception {
        BufferedReader bufferedReader = new BufferedReader(new FileReader("c:/users/kyle/desktop/aa.txt")); //aa.txt见末尾
        int vertexNumber = Integer.parseInt(bufferedReader.readLine()); //顶点数
        int edgeNumber = Integer.parseInt(bufferedReader.readLine()); //边数

        //构建图
        UndirectedGraphWithAdjacencyList graph = new UndirectedGraphWithAdjacencyList(vertexNumber);
        for (int i = 0; i < edgeNumber; i++) {
            String edge = bufferedReader.readLine();
            String[] edgeArray = edge.split(" ");
            graph.addEdge(Integer.parseInt(edgeArray[0]),Integer.parseInt(edgeArray[1])); //向图中添加边
        }

        //进行深度优先查找
        PathSearchByDFS pathFind = new PathSearchByDFS(graph,0);
        //调用 pathTo(4)，找到从起点0到终点4的路径，返回Stack
        Stack<Integer> path = pathFind.pathTo(4);

        for (int i = path.size(); i > 0; i--) {
            System.out.print(path.pop()+ "  "); //输出：0  2  3  4
        }
    }

}

/*
aa.txt：
6
8
0 2
0 1
2 1
2 3
2 4
3 5
3 4
0 5
*/