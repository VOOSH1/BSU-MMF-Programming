package com.company;

public class Gemstone extends Gem {
    private int carats, price;

    public Gemstone(String name, double opacity, int carats, int price) {
        super(name, opacity);

        this.carats = carats;
        this.price = price;
    }

    public Gemstone() {
        this("", 1, 0, 0);
    }

    public int getCarats() { return this.carats; }

    public int getPrice() { return this.price; }

    @Override
    public String toString() {
        String res = null;
        try {
            res = super.getName() +
                    ", opacity: " + super.getOpacity() +
                    ", carats: " + this.carats +
                    ", price: " + this.price + " griven";
        } catch (GemException e) {
            e.printStackTrace();
        }

        return res;
    }

    @Override
    public boolean equals(Object obj) {
        if(!(obj instanceof Gemstone)) {
            return false;
        }

        Gemstone gemstone = (Gemstone) obj;
        return super.equals(gemstone) && this.price == gemstone.price && this.carats == gemstone.carats;
    }
}
