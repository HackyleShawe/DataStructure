package a_graph.read;

import a_graph.creat.UndirectedGraphWithAdjacencyList;

public class DepthFirstSearch {
    private boolean[] marked; //数组下标代表顶点，值表示当前顶点是否已经被搜索
    private int count; //记录多少个顶点与start顶点相连通

    /**
     * 构造器
     * @param graph 图
     * @param start 从哪个节点开始搜索
     */
    public DepthFirstSearch(UndirectedGraphWithAdjacencyList graph, int start) {
        this.marked = new boolean[graph.getVertex()]; //初始化当前顶点是否被搜索过的标记数组
        this.count = 0;
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
            if(!marked(ver)) {
                System.out.print(ver+"  ");
                dfs(graph,ver);
            }
        }
        count++;
    }

    /**
     * 判断起始搜索顶点start是否与vertex顶点相连通
     */
    public boolean marked(int vertex) {
        return marked[vertex];
    }

    /**
     * 获取与顶点start相通的所有顶点数
     */
    public int getCount() {
        return count;
    }
}

/**
 * 测试
 */
class Test {
    public static void main(String[] args) {
        //准备Graph对象
        UndirectedGraphWithAdjacencyList graph = new UndirectedGraphWithAdjacencyList(13);
        graph.addEdge(0,5); //第一个图
        graph.addEdge(0,1);
        graph.addEdge(0,2);
        graph.addEdge(0,6);
        graph.addEdge(5,3);
        graph.addEdge(5,4);
        graph.addEdge(3,4);
        graph.addEdge(4,6);

        graph.addEdge(7,8); //第二个图，和第一个图示非连通的

        graph.addEdge(9,11); //第三个图
        graph.addEdge(9,10);
        graph.addEdge(9,12);
        graph.addEdge(11,12);

        //准备深度优先搜索对象
        DepthFirstSearch search = new DepthFirstSearch(graph, 0);
        System.out.println();

        //测试与某个顶点相通的顶点数量
        int count = search.getCount();
        System.out.println("与起点0相通的顶点的数量为:"+count);


        //测试某个顶点与起点是否相通
        boolean marked1 = search.marked(5);
        System.out.println("顶点5和顶点0是否相通："+marked1);

        boolean marked2 = search.marked(7);
        System.out.println("顶点7和顶点0是否相通："+marked2);
    }
}


