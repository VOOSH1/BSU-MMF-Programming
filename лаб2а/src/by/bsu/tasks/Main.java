package by.bsu.tasks;

import java.util.Scanner;




public class Main {



    public static boolean isDigitsInAscOrder(String number) {
        for (int i = 1; i < number.length(); ++i) {
            if (number.charAt(i) <= number.charAt(i - 1)) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n;
        do {
            System.out.print("Введите размер массива: ");
            n = input.nextInt();
            if (n <= 0) {
                System.out.println("Ошибка! Некорректные данные");
                continue;
            }
            break;
        } while (true);
        String[] numbers = new String[n];
        System.out.println("Введите числа: ");
        for (int i = 0; i < n; ++i) {
            numbers[i] = input.next();
        }
        System.out.println();
        for (int i = 0; i < n; ++i) {
            if (isDigitsInAscOrder(numbers[i])) {
                System.out.println("Число, цифры в котором идут в строгом порядке возрастания: " + numbers[i]);
                System.exit(0);
            }
        }
        System.out.println("Нет чисел, цифры в которых идут в строгом порядке возрастания");
    }
}
