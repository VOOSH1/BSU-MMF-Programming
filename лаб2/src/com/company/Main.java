package com.company;


import java.util.Arrays;
import java.util.Random;

import static java.util.Arrays.*;


public class Main {

    public static void main(String[] args) {
        int[][] arr=new int[3][5];
        fillArray(arr);
        showArray(arr);
        System.out.println();
        showArray(rotateLeft(arr, 3));
    }

    public static int[][] fillArray(int[][] arr) {
        Random rand = new Random();
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[i].length; j++) {
                arr[i][j]=rand.nextInt(100);
            }
        }
        return arr;
    }

    public static void showArray(int[][] arr) {
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[i].length; j++) {
                System.out.print(arr[i][j] + "\t");
            }
            System.out.println();
        }
    }

    public static int[][] rotateLeft(int[][] arr, int x) {
        int[][] newarr = new int[arr[0].length][arr.length];
        x = x - (x / 4) * 4;
        if (x != 0) {
            for (int j = 0; j < arr.length; j++) {
                for (int k = arr[j].length - 1; 0 <= k; k--) {
                    newarr[arr[j].length - k - 1][j] = arr[j][k];
                }
            }
            x--;
        } else newarr = arr;
        return (x!=0?rotateLeft(newarr,x):newarr);
    }

}