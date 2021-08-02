package tree;


/**
 * 并查集
 */
public class DisjointSet {
    /** 记录节点元素和所在分组标识 */
    private int[] elementAndGroup;
    /** 记录并查集中数据的分组个数 */
    private int count;

    /**
     * 构造器
     */
    public DisjointSet(int N) {
        this.count = N; //初始化分组的数量，初始化时，有多少个元素，就有多少个分组
        this.elementAndGroup = new int[N];

        //初始化elementAndGroup中的元素及其所在的组的标识符,让elementAndGroup数组的索引作为并查集的每个结点的元素;
        //并且让每个索引处的值(该元素所在的组的标识符)就是该索引
        for (int i = 0; i < elementAndGroup.length; i++) {
            elementAndGroup[i] = i;
        }
    }

    /**
     * 获取当前并查集中的数据有多少个分组
     */
    public int groupCount() {
        return count;
    }

    /**
     * 元素ele所在分组的标识符
     */
    public int findGroup(int ele) {
        while(true) {
            if(ele == elementAndGroup[ele]) {
                return ele;
            } else {
                ele = elementAndGroup[ele]; //用当前下标中的值继续查找
            }
        }
    }

    /**
     * 判断两个元素是否为同一个分组
     */
    public boolean isSameGroup(int a, int b) {
        return findGroup(a) == findGroup(b);
    }

    /**
     * 把a元素所在分组和b元素所在分组合并
     */
    public void union(int a,int b) {
        int rootA = findGroup(a);
        int rootB = findGroup(b);
        if(rootA == rootB) { //a元素和b元素本来就是在同一个分组
            return;
        }

        //合并组：让a所在的树的根结点的父结点为b所在树的根结点即可
        elementAndGroup[rootA] = rootB;
        this.count--; //分组数减少
    }
}


/**
 * 测试：并查集
 */
class DisjointSetTest {
    public static void main(String[] args){
        DisjointSet unionFind = new DisjointSet(10); //初始化并查集中有10个元素
        System.out.println("初始状态并查集中的元素个数："+unionFind.groupCount());

        System.out.println(unionFind.isSameGroup(5,6)); //false
        unionFind.union(3,4);
        unionFind.union(7,8);
        unionFind.union(7,9);
        System.out.println(unionFind.isSameGroup(3,4)); //true
        System.out.println(unionFind.groupCount()); //7
    }

}