//Все трехзначные числа, в десятичной записи которых нет одинаковых цифр.
package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        int[] arr1, arr2;
        int n;
        Scanner scanner = new Scanner(System.in);
        cout("Введите количество эелментов массива: ");
        n = scanner.nextInt();
        arr1 = new int[n];
        arr2 = new int[n];
        cout("Введите элементы массива через пробел: ");
        for (int i = 0; i < n; i++)
        {
            arr1[i] = scanner.nextInt();
        }
        for (int i = 0; i < n; i++)
        {
            arr2[i] = arr1[i];
            for( int j = 0; j < 2; j++)
            {
                arr1[i] /= 10;
                if(arr1[i] == 0)
                {
                    coutln("Число номер " + (i+1) +" не трехзначное.");
                }
            }
            arr1[i] /= 10;
            if(arr1[i] != 0)
            {
                coutln("Число номер " + (i + 1) + " не трехзначное.");
            }
        }
        int temp1,temp2,temp3, number;
        for (int i = 0; i < n; i ++)
        {
            number = arr2[i];
            temp1 = arr2[i]%10;
            arr2[i] /= 10;
            temp2 = arr2[i]%10;
            arr2[i] /= 10;
            temp3 = arr2[i];
            if(temp1 != temp2 && temp2 != temp3 && temp1 != temp3)
            {
                cout(number);
            }

        }
    }

    public static void cout(String s)
    {
        System.out.print(s + " ");
    }
    public static void cout(int i)
    {
        System.out.print(i + " ");
    }
    public static void coutln(String s)
    {
        System.out.println(s);
    }
    public static void coutln(int i)
    {
        System.out.println(i);
    }
}
