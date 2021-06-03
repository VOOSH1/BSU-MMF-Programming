package ListHouse;

import java.util.ArrayList;
import java.util.List;
import House.House;

public class ListHouse {
    public List<House> houseList = new ArrayList<>();
    private int size = 0;

    public int getSize() {
        return size;
    }

    public void addHouse(House a) {
        houseList.add(a);
        this.size++;
    }

    public void Print(){
        for(House st:houseList) {
            System.out.println(st.toString());
        }
    }

    public void solveA(int numberOfRoom) {
        System.out.println("список квартир, имеющих заданное число комнат: ");
        for(House st:houseList) {
            if (st.getNumberOfRooms() == numberOfRoom) {
                System.out.println(st.toString());
            }
        }
    }

    public void solveB(int numberOfRoom, int lFlat, int rFlat) {
        System.out.println("список квартир, имеющих заданное число комнат и расположенных\n" +
                "на этаже, который находится в заданном промежутке: ");
        for(House st: houseList) {
            if (st.getNumberOfRooms() == numberOfRoom && lFlat <= st.getFlat() && st.getFlat() <= rFlat) {
                System.out.println(st.toString());
            }
        }
    }


    public void solveC(int square) {
        System.out.println("список квартир, имеющих площадь, превосходящую заданную: ");
        for(House st: houseList) {
            if (st.getSquare() > square) {
                System.out.println(st.toString());
            }
        }
    }

}
