package a_SequenceList;

import java.util.Iterator;

/**
 * 顺序表（即数组、ArrayList）
 */
public class SequenceList<T> implements Iterable<T> {
    /**
     * 存储数组
     */
    private T[] elements;
    /**
     * 数组中元素的个数，注意N不是下标
     */
    private int N;

    /**
     * 构造器
     * @param capacity 初始化顺序表中的容量
     */
    public SequenceList(int capacity) {
        this.elements = (T[]) new Object[capacity]; //强制类型转换
        this.N = 0;
    }

    /**
     * 增: 新插入数据
     */
    public void insert(T t) {
        if (N == this.elements.length) { //判断数组是否是要满了
            resize(2 * this.elements.length);
        }
        this.elements[N++] = t; //插入元素的同时增加线性表的数量
    }

    /**
     * 增：在指定位置新插入数据
     * @param t 要插入的数据
     * @param index 位置
     */
    public void insert(T t, int index) {
        if (index < 0 || index >= this.N) {
            throw new RuntimeException("下标参数" + index + "越界");
        }
        if (N == this.elements.length) { //判断是否是要满了
            resize(2 * this.elements.length);
        }

        int k = N - 1;
        while (k >= index) { //从尾到头遍历数组
            this.elements[k + 1] = this.elements[k]; //移出将要插入数据的空间
            k--;
        }
        this.elements[index] = t;
        this.N++; //顺序表的元素增加
    }

    /**
     * 删除所有
     */
    public void clear() {
        this.N = 0;
    }

    /**
     * 删除指定位置的元素
     * @param index 位置
     * @return 刚刚删除的元素
     */
    public T remove(int index) {
        if (index >= N) { //越界
            throw new RuntimeException("下标参数" + index + "越界");
        }
        T current = this.elements[index];
        for (int k = index + 1; k < N; k++) {
            this.elements[k - 1] = this.elements[k];
        }
        this.N--;
        return current;
    }

    /**
     * 重新调整顺序表的大小
     * @param newSize 更改后的顺序表大小
     */
    private void resize(int newSize) {
        T[] temp = this.elements; //指向原数组
        elements = (T[]) new Object[newSize]; //elements指向一块新的内存区域
        for (int i = 0; i < N; i++) {
            elements[i] = temp[i];
        }
    }

    /**
     * 获取当前元素的个数
     */
    public int length() {
        return this.N;
    }

    /**
     * 搜索元素在顺序表中的位置
     * @param t 带搜索的元素
     * @return 在顺序表的位置
     */
    public int indexOf(T t) {
        for (int i = 0; i < N; i++) {
            if (this.elements[i].equals(t)) {
                return i;
            }
        }
        return -1;
    }

    /**
     * 判断是否为空
     */
    public boolean isEmpty() {
        return this.N == 0;
    }


    /**
     * 实现迭代器：可参考AbstractList抽象类中的写法
     * @return 单向迭代器
     */
    @Override
    public Iterator<T> iterator() {
        return new SequenceListIterator();
    }
    private class SequenceListIterator implements Iterator<T> {
        private int index;

        public SequenceListIterator() {
            this.index = 0;
        }

        @Override
        public boolean hasNext() {
            return index < N;
        }

        @Override
        public T next() {
            return elements[index++];
        }
    }
}



/**
 * 测试
 */
class SequenceListTest {
    public static void main(String[] args) throws Exception {
        SequenceList<Integer> list = new SequenceList<>(3);
        list.insert(2);
        list.insert(3);
        list.insert(4);
        list.insert(11, 1);

        list.remove(1);
        System.out.println(list.remove(1));

        System.out.println(list.indexOf(2));
        System.out.println(list.length());

        //普通遍历
        for (Integer e : list) {
            System.out.println(e);
        }

        //迭代器遍历
        Iterator<Integer> it = list.iterator();
        while (it.hasNext()) {
            System.out.println(it.next());
        }
    }
}