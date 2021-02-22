package a_graph.creat;

import java.util.LinkedList;
import java.util.Queue;

/**
 * 无向图（邻接表实现）
 */
public class UndirectedGraphWithAdjacencyList {
    private final int vertex; //顶点数
    private int edge; //边数
    private Queue<Integer>[] adj; //邻接表

    public UndirectedGraphWithAdjacencyList(int vertex) {
        this.vertex = vertex; //初始化顶点数
        this.edge = 0; //初始化边为0
        this.adj = new Queue[vertex];

        for (int i = 0; i < adj.length; i++) {
            adj[i] = new LinkedList<Integer>(); //LinkedList是Queue的实现类
        }
    }

    public int getVertex() {
        return vertex;
    }

    public int getEdge() {
        return edge;
    }

    /**
     * 给两个顶点加边
     * @param v 顶点
     * @param w 另一个顶点
     */
    public void addEdge(int v, int w) {
        //在无向图中，边是没有方向的，所以该边既可以说是从v到w的边，又可以说是从w到v的边，
        //因此，需要让w出现在v的邻接表中，并且还要让v出现在w的邻接表中
        adj[v].add(w);
        adj[w].add(v);
        this.edge++;
    }

    /**
     * 获取和顶点v相邻的所有顶点
     * @param v 顶点
     */
    public Queue<Integer> adj(int v) {
        return adj[v];
    }

}
