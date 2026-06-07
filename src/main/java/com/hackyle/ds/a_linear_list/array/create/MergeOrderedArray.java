package com.hackyle.ds.a_linear_list.array.create;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Random;

public class MergeOrderedArray {
    /**
     * 合并两个有序数组
     * 算法：
     *  用两个指针分别指向两个数组起点，比较元素大小，小的放入结果数组，对应指针后移；
     *  剩余元素直接追加；
     *  时间复杂度 O (m+n)，空间 O (m+n)。
     */
    public static int[] mergeOrderedArray(int[] arr, int[] brr) {
        int alen = arr.length;
        int blen = brr.length;

        int[] resultArr = new int[alen + blen];

        int i = 0, j = 0, k = 0;
        while(i < alen && j < blen) {
            if(arr[i] > brr[j]) {
                resultArr[k++] = brr[j];
                j++;
            } else {
                resultArr[k++] = arr[i];
                i++;
            }
        }

        while(i<alen) {
            resultArr[k++] = arr[i++];
        }
        while(j<blen) {
            resultArr[k++] = brr[j++];
        }

        return resultArr;
    }


    @Test
    public void testPartInterchange() {
        int lenBound = 10;
        int elementBound = 500;
        Random random = new Random();
        int alen = random.nextInt(lenBound);
        int blen = random.nextInt(lenBound);

        int[] arr = genRandomArr(alen, elementBound);
        int[] brr = genRandomArr(blen, elementBound);

        Arrays.sort(arr);
        Arrays.sort(brr);

        System.out.println("arr: " + Arrays.toString(arr) + "; length: " + arr.length);
        System.out.println("brr: " + Arrays.toString(brr) + "; length: " + brr.length);

        int[] orderedArray = MergeOrderedArray.mergeOrderedArray(arr, brr);
        System.out.println("orderedArray: " + Arrays.toString(orderedArray)  + "; length: " + orderedArray.length);
    }
    public int[] genRandomArr(int len, int bound) {
        len = len < 1 ? 10 : len;
        int[] arr = new int[len];
        Random random = new Random();
        for (int i = 0; i < len; i++) {
            int ranVal = random.nextInt(bound);
            arr[i] = ranVal;
        }
        return arr;
    }

}

