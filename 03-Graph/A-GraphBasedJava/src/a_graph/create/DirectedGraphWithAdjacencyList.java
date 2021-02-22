package a_graph.creat;

import java.util.LinkedList;
import java.util.List;

/**
 * 有向图，邻接表实现
 * 注意：在有向图中，使用邻接表来保存某个结点的出度；用逆邻接表来保存某结点的入度；
 */
public class DirectedGraphWithAdjacencyList {
    private int vertex; //顶点数
    private int edge; //边数
    private List<Integer>[] adj; //邻接表

    public DirectedGraphWithAdjacencyList(int vertex) {
        this.vertex = vertex;
        this.edge = 0; //初始化时边数为0
        this.adj = new List[vertex];

        for (int ver = 0; ver < vertex; ver++) {
            adj[ver] = new LinkedList<Integer>(); //初始化邻接表为链表
        }
    }

    public int getEdge() {
        return edge;
    }
    public int getVertex() {
        return vertex;
    }

    /**
     * 添加一条由start顶点指向end顶点的边
     * @param start 起始顶点
     * @param end 终止顶点
     */
    public void addEdge(int start, int end) {
        //只需要让顶点end出现在顶点start的邻接表中（邻接表保存出度，逆邻接表表示入度）
        adj[start].add(end);
        edge++;
    }

    /**
     * 获取顶点vertex的邻接表，即所有连接顶点
     */
    public List<Integer> adj(int vertex) {
        return adj[vertex];
    }

    /**
     * 该图的反向图
     */
    private DirectedGraphWithAdjacencyList reverse() {
        DirectedGraphWithAdjacencyList reverseDGraph = new DirectedGraphWithAdjacencyList(vertex); //创建一个反向图
        for(int ver=0; ver<vertex; ver++) { //遍历每个顶点
            for(Integer verTmp:adj(ver)) { //遍历每个顶点的链接顶点
                reverseDGraph.addEdge(verTmp,ver); //将链接的边加入到反向图中
            }
        }
        return reverseDGraph;
    }

}
