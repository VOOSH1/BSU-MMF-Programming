package com.company;

public class Semiprecious extends Gem{
    private int price;

    public Semiprecious(String name, double opacity, int price) {
        super(name, opacity);

        this.price = price;
    }

    public Semiprecious() {
        this("", 1, 0);
    }

    public int getPrice() { return this.price; }

    @Override
    public String toString() {
        String res = null;
        try {
            res = super.getName() +
                    ", opacity: " + super.getOpacity() +
                    ", price: " + this.price + " griven";
        } catch (GemException e) {
            e.printStackTrace();
        }
        return res;
    }

    @Override
    public boolean equals(Object obj) {
        if(!(obj instanceof Semiprecious)) {
            return false;
        }


        Semiprecious semiprecious = (Semiprecious) obj;
        return super.equals(semiprecious) && this.price == semiprecious.price;
    }
}
