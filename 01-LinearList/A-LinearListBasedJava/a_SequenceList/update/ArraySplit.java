package ds;

import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.List;

public class ArraySplit {

    /**
     * Function: 将数组dataList分割成一个个以count大小的小数组
     * Input：dataList：待分割的数组；count：分割的大小
     * Output：分割后的小数组的集合
     */
    public List<List<String>> arraySplit01(List<String> dataList, int count) {
        System.out.println("arraySplit-Input：dataList:"+dataList.toString() + " count:"+count);

        List<List<String>> resultList = new ArrayList<List<String>>(); //保存分割后的小数组的集合

        int length = dataList.size();
        List<String> tmpList = new ArrayList<>();
        int x = 0;

        for (int i = 0; i < length; i++) {
            if(x++ < count) {
                tmpList.add(dataList.get(i));
            }
            //收集到了count个 或者 到dataList中最后一个元素
            if(x==count || i==length-1){
                x = 0;
                resultList.add(tmpList);
                tmpList = new ArrayList<>();
            }
        }

        System.out.println("arraySplit-Output: " + resultList.toString());

        return resultList;
    }

    @Test
    public void testarraySplit01() {
        List<String> dataList = new ArrayList<>();
        for (int i = 0; i < 10; i++) {
            dataList.add(String.valueOf(Math.random()));
        }

        List<List<String>> stringLists = arraySplit01(dataList, 4);
        for (List<String> stringList : stringLists) {
            System.out.println(stringList.toString());
        }

    }


    /**
     * Function：将一个List的元素分割成以count个一组并拼接为String
     * Input：dataList：待分割的List；count：多少个元素为一租
     * Output：分割拼接后的List<String>
     */
    public List<String> arraySplit02(List<String> dataList, int count) {
        System.out.println("arraySplit-Input：dataList:"+dataList.toString() + " count:"+count);

        int len = dataList.size();
        List<String> resultList = new ArrayList<>();
        StringBuilder stringBuilder = new StringBuilder();
        int x = 0;
        
        for (int i = 0; i < len; i++) {
            if(x++ < 4) {
                stringBuilder.append(dataList.get(i)).append("、");
            }
            
            //收集到了count个 或者 到dataList中最后一个元素
            if(x == 4 || i==len-1) {
                x = 0;
                resultList.add(stringBuilder.deleteCharAt(stringBuilder.length()-1).toString());
                stringBuilder = new StringBuilder();
            }
        }

        System.out.println("arraySplit-Output: " + resultList.toString());
        return resultList;
    }

    @Test
    public void testarraySplit02() {
        List<String> dataList = new ArrayList<>();
        for (int i = 0; i < 10; i++) {
            dataList.add(String.valueOf(Math.random()));
        }

        List<String> stringList = arraySplit02(dataList, 4);
        for (String s : stringList) {
            System.out.println(s);
        }
    }


}
