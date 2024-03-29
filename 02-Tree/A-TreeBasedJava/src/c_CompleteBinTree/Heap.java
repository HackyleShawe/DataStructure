package c_CompleteBinTree;

import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Random;

/**
 * <p>堆</p>
 * <p>注意：</p>
 * <ul>
 *     <li>大顶堆的定义：堆顶元素是整个堆中最大的</li>
 *     <li>小顶堆的定义：堆顶元素是整个堆中最小的</li>
 *     <li>创建完毕大顶堆后的数组不一定是有序的；创建完小顶堆的数组不一定是有序的</li>
 * </ul>
 */
public class Heap<T extends Number> {
    /** 保存堆操作后的数组 */
    private List<T> heapArray;

    /**
     * 构造器
     */
    public Heap() {
        heapArray = new ArrayList<>();
    }

    /**
     * <p>Function: 根据原始无序数组创建<b>大顶堆</b></p>
     * <p>Algorithm:</p>
     * <ol>
     *     <li>从数组的一半处（记为k）开始向数组头方向遍历。</li>
     *     <li>选择k节点和其左右子节点较大的放在k位置，直到k到数组头（堆顶）</li>
     * </ol>
     */
    public List<T> createBigHeap(List<T> sourceArr) {
        //把source中的元素拷贝到heap中，heap中的元素就形成一个无序的堆
        heapArray.add(null); //堆的第一个位置不存放具体元素
        heapArray.addAll(sourceArr);

        //1.从数组的一半处（记为k）开始向数组头方向遍历
        for (int i = (heapArray.size())/2; i > 0; i--){
            //2.选择k节点和其左右子节点较大的放在k位置，直到k到数组头（堆顶）
            createBigHeap(i, heapArray.size()-1);
        }

        return heapArray;
    }

    /**
     * <p>Function: 在heap堆中，选择target节点和其左右子节点中最大的值放在target位置，
     *              target的左右子节点范围为[1,range]</p>
     * <p>Algorithm：</p>
     *  <ol>
     *  <li>找出当前节点与其子节点的较大的子节点</li>
     *  <li>比较当前节点的值与较大子节点的值</li>
     *  <li>符合条件则交换</li>
     *  </ol>
     * @param target 想要对谁进行下沉操作
     * @param range 限制target的左右子节点的范围：[1,range]
     */
    private void createBigHeap(int target, int range) {
        while(2*target <= range) {
            //1.找出当前结点的较大的子结点
            int max;
            if (2 * target + 1 <= range) { //target节点如果还有子节点
                if (greater(2 * target, 2 * target + 1)) { //比较target节点的左右节点
                    max = 2 * target;
                } else {
                    max = 2 * target + 1;
                }
            } else { //target节点只有左子节点
                max = 2 * target;
            }

            //2.比较当前结点的值和较大子结点的值
            if (greater(target, max)) { //target已经是较大的，不交换
                break;
            }

            exchange(max, target); //符合条件，则交换
            target = max;
        }
    }


    /**
     * <p>Function：根据原始无序数组创建小顶堆</p>
     * <p>Algorithm:</p>
     * <ol>
     *     <li>从数组的一半处（记为k）开始向数组头方向遍历。</li>
     *     <li>选择k节点和其左右子节点较小的放在k位置，直到k到数组头（堆顶）</li>
     * </ol>
     */
    public List<T> createLittleHeap(List<T> sourceArr) {
        //把source中的元素拷贝到heap中，heap中的元素就形成一个无序的堆
        heapArray.add(null); //堆的第一个位置不存放具体元素
        heapArray.addAll(sourceArr);

        //1.从数组的一半处（记为k）开始向数组头方向遍历
        for (int i = (heapArray.size())/2; i > 0; i--){
            //2.选择k节点和其左右子节点较小的放在k位置，直到k到数组头（堆顶）
            createLittleHeap(i, heapArray.size()-1);
        }

        return heapArray;
    }

    /**
     * <p>Function: 在heap堆中，选择target节点和其左右子节点中最小的值放在target位置，
     *              target的左右子节点范围为[1,range]</p>
     * <p>Algorithm：</p>
     *  <ol>
     *  <li>找出当前节点与其子节点的较小的子节点</li>
     *  <li>比较当前节点的值与较小子节点的值</li>
     *  <li>符合条件则交换</li>
     *  </ol>
     * @param target 想要对谁进行下沉操作
     * @param range 限制target的左右子节点的范围：[1,range]
     */
    private void createLittleHeap(int target, int range) {
        while(2*target <= range) {
            //1.找出当前结点的较大的子结点
            int min;
            if (2 * target + 1 <= range) { //target节点如果还有子节点
                if (smaller(2 * target, 2 * target + 1)) { //比较target节点的左右节点
                    min = 2 * target;
                } else {
                    min = 2 * target + 1;
                }
            } else { //target节点只有左子节点
                min = 2 * target;
            }

            //2.比较当前结点的值和较大子结点的值
            if (smaller(target, min)) { //target已经较小，不需要交换
                break;
            }

            exchange(min, target); //如果符合条件，则交换
            target = min;
        }
    }


    /**
     * <p>功能：大顶堆删除最大值，并返回</p>
     * 算法：
     * <ol>
     *  <li>交换完全二叉树最后一个节点与第一个节点的值</li>
     *  <li>删除最后一个节点</li>
     *  <li>将数组长度减一</li>
     *  <li>进行下沉调整</li>
     *  </ol>
     */
    public T deleteMax() {
        T max = heapArray.get(1); //大顶堆中的最大值
        exchange(1, heapArray.size() - 1); //交换第一个节点与最后一个节点
        heapArray.remove(heapArray.size() - 1); //删除最后一个节点
        sink(1);
        return max;
    }

    /**
     * Function：删除元素后，使用下沉思想调整为大顶堆
     * @param target 使用下沉算法，使得索引target处的元素能在堆中处于一个正确的位置
     */
    private void sink(int target) {
        //不断比较并交换当前节点与直接子节点
        while(2*target <= heapArray.size() - 1) {
            int max; //获取当前结点的直接子结点中的较大结点
            if(2*target+1 <= heapArray.size() -1) {
                if(smaller(2*target,2*target+1)) {
                    max = 2*target+1;
                } else {
                    max = 2*target;
                }
            } else {
                max = 2*target;
            }

            //比较当前结点和较大结点的值
            if (!smaller(target,max)){
                break;
            }

            exchange(target,max);
            target = max;
        }
    }


    /**
     * 插入元素
     * @param t 插入元素的值
     */
    public void insert(T t) {
        heapArray.add(t);
        swim(heapArray.size() - 1); //上浮算法，使得插入的元素能够构成大/小顶堆
    }

    /**
     * <p>功能：上浮调整</p>
     * <p>算法：不断比较交换当前节点与其直接父节点的值</p>
     * @param target 使用上浮算法，使索引target处的元素能在堆中处于一个正确的位置
     */
    private void swim(int target) {
        //不断比较当前节点与其直接父节点的值，进行交换
        while(target > 1) {
            if(smaller(target/2, target)) {
                exchange(target/2, target);
            }
            target = target/2;
        }
    }


    /**
     * 交换堆中的两个位置上的数字
     */
    private void exchange(int i, int j) {
        T tmp = heapArray.get(i);
        heapArray.set(i, heapArray.get(j));
        heapArray.set(j, tmp);
    }

    /**
     * i处的值比j处的值小，则返回true
     * @param i 值1
     * @param j 值2
     * @return i处的值更小，则为true
     */
    private boolean smaller(int i, int j) {
        //由于是Number类型，所以可以将其转换为BigDecimal进行最终的比较
        BigDecimal a = new BigDecimal(heapArray.get(i).toString());
        BigDecimal b = new BigDecimal(heapArray.get(j).toString());
        return a.compareTo(b) < 0 ;
    }

    /**
     * i处的值比j处的值大，则返回true
     * @param i 值1
     * @param j 值2
     * @return i处的值更da，则为true
     */
    private boolean greater(int i, int j) {
        //由于是Number类型，所以可以将其转换为BigDecimal进行最终的比较
        BigDecimal a = new BigDecimal(heapArray.get(i).toString());
        BigDecimal b = new BigDecimal(heapArray.get(j).toString());
        return a.compareTo(b) > 0 ;
    }
}


/**
 * 测试类：堆的创建以及操作
 */
class HeapTest {

    public static void main(String[] args) {
        testCreateHeap();
        System.out.println();
        testOperateHeap();
    }

    /**
     * 测试：创建堆
     */
    public static void testCreateHeap() {
        Random random = new Random();
        int len = Math.abs(random.nextInt(20));
        Integer[] intArr = new Integer[len];
        for (int i = 0; i < len; i++) {
            intArr[i] = random.nextInt(1000);
        }
        List<Integer> intList = new ArrayList<>(Arrays.asList(intArr));

        Double[] douArr = new Double[len];
        for (int i = 0; i < len; i++) {
            douArr[i] = random.nextDouble()*1000;
        }
        List<Double> doubleList = new ArrayList<>(Arrays.asList(douArr));

        BigDecimal[] bigDecimalArr = {new BigDecimal("1000"), new BigDecimal("2134"),
                new BigDecimal("22222"), new BigDecimal("23432134"),
                new BigDecimal("234345"), new BigDecimal("1112")};
        List<BigDecimal> bigDecimalList = new ArrayList<>(Arrays.asList(bigDecimalArr));

        Heap<Integer> intHeap = new Heap<>();
        List<Integer> bigHeap = intHeap.createBigHeap(intList);
        System.out.println("Big Heap:" + bigHeap);

        Heap<Double> doubleHeap = new Heap<>();
        List<Double> littleHeap = doubleHeap.createLittleHeap(doubleList);
        System.out.println("Little Heap:" + littleHeap);

        Heap<BigDecimal> bigDecimalMyHeap01 = new Heap<>();
        List<BigDecimal> bigDecimalHeap01 = bigDecimalMyHeap01.createBigHeap(bigDecimalList);
        System.out.println("Big Heap:" + bigDecimalHeap01);

        Heap<BigDecimal> bigDecimalMyHeap02 = new Heap<>();
        List<BigDecimal> bigDecimalHeap02 = bigDecimalMyHeap02.createLittleHeap(bigDecimalList);
        System.out.println("Little Heap:" + bigDecimalHeap02);
    }

    /**
     * 测试堆的操作：插入、删除
     */
    public static void testOperateHeap() {
        BigDecimal[] bigDecimalArr = {new BigDecimal("1000"), new BigDecimal("2134"),
                new BigDecimal("22222"), new BigDecimal("23432134"),
                new BigDecimal("234345"), new BigDecimal("1112")};
        List<BigDecimal> bigDecimalList = new ArrayList<>(Arrays.asList(bigDecimalArr));

        Heap<BigDecimal> bigDecimalHeap = new Heap<>();
        List<BigDecimal> bigDecimalHeapList = bigDecimalHeap.createBigHeap(bigDecimalList);
        System.out.println("大顶堆：" + bigDecimalHeapList);

        bigDecimalHeap.insert(new BigDecimal("1"));
        bigDecimalHeap.insert(new BigDecimal("999999999"));
        System.out.println("插入了新值后：" + bigDecimalHeapList);

        bigDecimalHeap.deleteMax();
        System.out.println("移除了堆顶的最大值后：" + bigDecimalHeapList);

        bigDecimalHeap.deleteMax();
        System.out.println("移除了堆顶的最大值后：" + bigDecimalHeapList);
    }

}