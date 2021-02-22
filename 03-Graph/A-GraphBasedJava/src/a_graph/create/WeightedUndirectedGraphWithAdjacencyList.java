package a_graph.creat;

import java.util.LinkedList;
import java.util.List;

/**
 * 加权无向图（邻接表实现）
 */
public class WeightedUndirectedGraphWithAdjacencyList {
    private final int vertex; //顶点
    private int edge; //边
    private List<UndirectedEdge>[] adj; //顶点的邻接表

    public WeightedUndirectedGraphWithAdjacencyList(int vertex) {
        this.vertex = vertex;
        this.edge = 0;
        this.adj = new List[vertex]; //邻接表的大小和顶点一样大
        for (int i = 0; i < vertex; i++) {
            this.adj[i] = new LinkedList<UndirectedEdge>();
        }
    }

    //获取顶点数
    public int getVertex() {
        return vertex;
    }

    //获取边数
    public int getEdge() {
        return edge;
    }

    /**
     * 在无向图中添加一条边
     */
    public void addWeightEdge(UndirectedEdge noDirectEdge) {
        //需要让边e同时出现在e这个边的两个顶点的邻接表中
        int vertex01 = noDirectEdge.getVertex();
        int vertex02 = noDirectEdge.getOtherVertex(vertex01);

        this.adj[vertex01].add(noDirectEdge);
        this.adj[vertex02].add(noDirectEdge);
        this.edge++; //边的数量加一
    }

    /**
     * 获取顶点vertex的邻接表，即顶点vertex的连接顶点
     */
    public List<UndirectedEdge> adj(int vertex) {
        return this.adj[vertex];
    }

    /**
     * 获取加权五向图的所有边
     *
     */
    public List<UndirectedEdge> getAllWeightEdges() {
        List<UndirectedEdge> edgeList = new LinkedList<>();
        //算法：
        //1.遍历图中的每一个顶点，找到该顶点的邻接表，邻接表中存储了该顶点关联的每一条边
        //2.因为这是无向图，所以同一条边同时出现在了它关联的两个顶点的邻接表中，需要让一条边只记录一次；
        for (int vertex = 0; vertex < getVertex(); vertex++) { //遍历所有顶点
            for (UndirectedEdge noDirectEdge : adj(vertex)) { //遍历该顶点的连接顶点
                if(noDirectEdge.getOtherVertex(vertex) < vertex) { //将最小的顶点放进去
                    edgeList.add(noDirectEdge);
                }
            }
        }

        return edgeList;
    }

}

/**
 * 无向图的加权边
 */
class UndirectedEdge implements Comparable<UndirectedEdge> {
    private final int vertex01; //边的一个顶点
    private final int vertex02; //边的另一个顶点
    private final double weight; //边的权重

    public UndirectedEdge(int vertex01,int vertex02,double weight) {
        this.vertex01 = vertex01; this.vertex02 = vertex02;
        this.weight = weight;
    }

    /**
     * 获取权重
     */
    public double getWeight() {
        return weight;
    }

    /**
     * 获取这边的任意个顶点
     */
    public int getVertex() {
        return vertex01;
    }

    /**
     * 获取vertex顶点所在边的另一个顶点
     */
    public int getOtherVertex(int vertex) {
        if(vertex == getVertex()) {
            return vertex02;
        } else {
            return vertex01;
        }
    }

    /**
     * 比较：当前边的权重和另外一条边的权重
     * 参数：that：另外一条边；this：本条边
     * @return 1：本条边打；-1：另外一条边打；0：一样大；
     */
    @Override
    public int compareTo(UndirectedEdge that) {
        if(this.getWeight() > that.getWeight()) {
            return 1;
        } else if(this.getWeight() < that.getWeight()) {
            return -1;
        } else {
            return 0;
        }
        //IDEA代码优化提示：return Double.compare(this.getWeight(), that.getWeight());
    }
}
