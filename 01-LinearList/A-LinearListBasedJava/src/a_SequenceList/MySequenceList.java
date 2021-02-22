package a_SequenceList;


import java.util.Iterator;

/**
 * 顺序表（即数组、相关写法有ArrayList）
 */
public class MySequenceList<T> implements Iterable<T> {

    private T[] elements; //存储数组
    private int N; //数组中元素的个数，注意N不是下标

    /* 构造器 */
    public MySequenceList(int capacity) {
        this.elements = (T[])new Object[capacity]; //强制类型转换
        this.N = 0;
    }

    /* 增 */
    public void insert(T t) {
        if(N == this.elements.length) { //判断数组是否是要满了
            resize(2 * this.elements.length);
        }
        this.elements[N++] = t; //插入元素的同时增加线性表的数量
    }
    public void insert(T t, int index) {
        if(index<0 || index>=this.N) {
            throw new RuntimeException("下标参数"+index+"越界");
        }
        if(N == this.elements.length) { //判断是否是要满了
            resize(2 * this.elements.length);
        }

        int k = N-1;
        while(k>=index) {
            this.elements[k+1] = this.elements[k];
            k--;
        }
        this.elements[index] = t;
        this.N++; //顺序表的元素增加
    }

    /* 删 */
    public void clear() {
        this.N = 0;
    }
    public T remove(int index) {
        if(index>=N) { //越界
            throw new RuntimeException("参数"+index+"越界");
        }
        T current = this.elements[index];
        for(int k=index+1; k<N; k++) {
            this.elements[k-1] = this.elements[k];
        }
        this.N--;
        return current;
    }

    /* 改 */
    private void resize(int newSize) {
        T[] temp = this.elements; //指向原数组
        elements = (T[])new Object[newSize]; //elements指向一块新的内存区域
        for(int i=0; i<N; i++) {
            elements[i] = temp[i];
        }
    }

    /* 查 */
    public int length() {
        return this.N;
    }
    public int indexOf(T t) {
        for (int i=0; i<N; i++) {
            if(this.elements[i].equals(t)) {
                return i;
            }
        }
        return -1;
    }
    public boolean isEmpty() {
        return this.N == 0;
    }

    /* 实现迭代器：可参考AbstractList抽象类中的写法 */
    @Override
    public Iterator<T> iterator() {
        return new SIterator();
    }
    private class SIterator implements Iterator{
        private int cusor;
        public SIterator(){
            this.cusor=0;
        }
        @Override
        public boolean hasNext() {
            return cusor<N;
        }

        @Override
        public Object next() {
            return elements[cusor++];
        }
    }

}

class MySequenceListTest {
    public static void main(String[] args) throws Exception {
        MySequenceList<Integer> list = new MySequenceList<>(3);
        list.insert(2);
        list.insert(3);
        list.insert(4);
        list.insert(11,1);

        list.remove(1);
        System.out.println(list.remove(1));

        System.out.println(list.indexOf(2));
        System.out.println(list.length());

        //普通遍历
        for(Integer e:list) {
            System.out.println(e);
        }

        //迭代器遍历
        Iterator<Integer> it = list.iterator();
        while (it.hasNext()) {
            System.out.println(it.next());
        }

    }

}