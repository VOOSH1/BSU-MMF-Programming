package by.bsu.tasks;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        int n;
        Scanner input = new Scanner(System.in);
        do {
            System.out.print("Введите размер матрицы(n*n): ");
            n = input.nextInt();
            if (n <= 0) {
                System.out.println("Ошибка! Некорректные данные");
                continue;
            }
            break;
        } while (true);
        double[][] maxtrix = new double[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                maxtrix[i][j] = (Math.random() * 2 * n) - n;
            }
        }
        System.out.println("Матрица:");
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                System.out.print(maxtrix[i][j] + "\t");
            }
            System.out.println();
        }
        System.out.println();
        long[][] roundMatrix = new long[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                roundMatrix[i][j] = Math.round(maxtrix[i][j]);
            }
        }
        System.out.println("Матрица с округленными числами:");
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                System.out.print(roundMatrix[i][j] + "\t");
            }
            System.out.println();
        }
        System.out.println();
    }
}
