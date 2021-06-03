
/* Камни. Определить иерархию драгоценных и полудрагоценных камней.
Отобрать камни для ожерелья. Подсчитать общий вес (в каратах) и стоимость.
Провести сортировку камней ожерелья на основе ценности. Найти камни в ожерелье,
соответствующие заданному диапазону параметров прозрачности.
 */
        package com.company;

        import com.company.models.Gem;
        import com.company.models.Gems;
        import com.company.models.Necklace;

        import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Gems gems = new Gems();
        Scanner scanner = new Scanner(System.in);
        System.out.println("Введите общее количество камней: ");
        int n= scanner.nextInt();
        for(int i = 0; i<n; i++){
            System.out.println("Введите данные для "+ (i+1) + " камня");
            System.out.print("Укажите имя камня: ");
            scanner.nextLine();
            String name = scanner.nextLine();
            System.out.print("Укажите прозрачность камня: ");
            double visibility = scanner.nextDouble();
            System.out.print("Укажите цену камня: ");
            double price = scanner.nextDouble();
            System.out.print("Укажите вес камня(в каратах): ");
            double weight = scanner.nextDouble();
            gems.addGem(new Gem(weight,price,visibility,name));
        }
        System.out.println(gems.toString());
        Necklace necklace = new Necklace();
        System.out.print("Какое колчество камней вы хотите отобрать для ожерелья: ");
        n = scanner.nextInt();
        for (int i = 0 ; i < n ; i ++)
        {
            System.out.print("Введите номер камня который добавить в ожерелье: ");
            necklace.addGem(gems.getGem(scanner.nextInt()-1));
        }
        System.out.println("Ожерелье: ");
        System.out.println(necklace.toString());
        System.out.print("Введите диапазон параметра прозрачности( начало и конец ): ");
        System.out.println(necklace.getRange(scanner.nextDouble(),scanner.nextDouble()));
        System.out.println("Отcортированные камни в ожерельи: ");
        necklace.sortGems();
        System.out.println(necklace.toString());

    }
}
