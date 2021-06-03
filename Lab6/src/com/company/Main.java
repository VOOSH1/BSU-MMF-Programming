package com.company;


import java.sql.SQLOutput;
import java.util.ArrayList;
import java.util.List;

interface Ship{
    public void start();
    public void stop();

}

abstract class Warship implements Ship{
    private String name;
    private String color;
    private long weight;
    private double speed;

    public abstract void start();
    public abstract void stop();


    public abstract String toString();

    public Warship(String name, String color, long weight, double speed) {
        this.name = name;
        this.color = color;
        this.weight = weight;
        this.speed = speed;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public long getWeight() {
        return weight;
    }

    public void setWeight(long weight) {
        this.weight = weight;
    }

    public double getSpeed() {
        return speed;
    }

    public void setSpeed(double speed) {
        this.speed = speed;
    }


}

class Carrier extends Warship{
    private List<String> planes;
    public Carrier(String name, String color, long weight, double speed) {
        super(name, color, weight, speed);
        planes = new ArrayList<String>();
    }
    public void addPlane(String plane)
    {
        planes.add(plane);
    }
    public String getPlane(int index){
        return planes.get(index);
    }
    public List<String> getPlanes(){
        return planes;
    }
    public void deletePlane(int index){// Удвление по индексу
        planes.remove(index);
    }
    public void deletePlane(String plane) { // Удаление по имени
        planes.remove(plane);
    }

    @Override
    public void start() {
        System.out.println("Корабль спущен на воду");
    }

    @Override
    public void stop() {
        System.out.println("Корабль вернулся в порт");
    }

    @Override
    public String toString() {
        return "Warship{" +
                "name='" + this.getName() + '\'' +
                ", color='" + this.getColor() + '\'' +
                ", weight=" + this.getWeight() +
                ", speed=" + this.getSpeed() +
                '}';
    }
}
public class Main {

    public static void main(String[] args) {
        Carrier carrier = new Carrier("Egor", "Black", 49,400);
        carrier.start();
        carrier.addPlane("1");
        carrier.addPlane("2");
        carrier.addPlane("3");
        System.out.println(carrier);
        System.out.println(carrier.getPlanes());
        carrier.deletePlane(0);
        System.out.println(carrier.getPlanes());
        carrier.stop();
    }
}
