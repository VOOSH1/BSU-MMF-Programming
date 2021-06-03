package com.company;

import java.io.Serializable;

public class Necklace implements Serializable {
    public Semiprecious[] semipreciousStones;
    public Gemstone[] gemStones;

    public Necklace(Semiprecious semipreciousStones[], Gemstone gemStones[]) {
        this.semipreciousStones = semipreciousStones;
        this.gemStones = gemStones;
    }

    public Necklace() {
        this(new Semiprecious[0], new Gemstone[0]);
    }

    public Semiprecious[] getSemipreciousStones() {
        return this.semipreciousStones;
    }

    public Gemstone[] getGemStones() {
        return this.gemStones;
    }

    public Necklace provideNecklaceSample() {
        Semiprecious amber = new Semiprecious("amber", 0.7, 100);
        Semiprecious apatite = new Semiprecious("apatite", 0.65, 140);
        Semiprecious rhodochrosis = new Semiprecious("rhodochrosis", 0.82, 95);
        Semiprecious euclase = new Semiprecious("euclase", 0.42, 210);

        Semiprecious[] semipreciousStones = {amber, apatite, rhodochrosis, euclase};



        Gemstone diamond = new Gemstone("diamond", 0.15, 12, 10000);
        Gemstone emerald = new Gemstone("emerald", 0.5, 7, 14500);
        Gemstone ruby = new Gemstone("ruby", 0.52, 14, 8200);
        Gemstone sapphire = new Gemstone("sapphire", 0.37, 9, 17100);

        Gemstone[] gemStones = {diamond, emerald, ruby, sapphire};



        return new Necklace(semipreciousStones, gemStones);
    }

    public int sumCarats() {
        int res = 0;

        for(Gemstone g : this.gemStones) {
            res += g.getCarats();
        }

        return res;
    }

    public int sumPrice() {
        int res = 0;

        for(Gemstone g : this.gemStones) {
            res += g.getPrice();
        }

        for(Semiprecious s : this.semipreciousStones) {
            res += s.getPrice();
        }

        return res;
    }

    public void sortGemstones() {
        int n = this.gemStones.length;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n - i - 1; j++) {
                if(this.gemStones[j].getPrice() > this.gemStones[j + 1].getPrice()) {
                    Gemstone temp = this.gemStones[j];
                    this.gemStones[j] = this.gemStones[j + 1];
                    this.gemStones[j + 1] = temp;
                }
            }
        }
    }

    public void sortSemiprecious() {
        int n = this.semipreciousStones.length;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n - i - 1; j++) {
                if(this.semipreciousStones[j].getPrice() > this.semipreciousStones[j + 1].getPrice()) {
                    Semiprecious temp = this.semipreciousStones[j];
                    this.semipreciousStones[j] = this.semipreciousStones[j + 1];
                    this.semipreciousStones[j + 1] = temp;
                }
            }
        }
    }

    public Necklace sortByOpacity(double startOpacity, double endOpacity) throws GemException {
        int gLength = 0;
        int sLength = 0;

        for(Gemstone g : this.gemStones) {
            double currentOpacity = g.getOpacity();
            if(currentOpacity >= startOpacity && currentOpacity <= endOpacity) {
                gLength++;
            }
        }

        for(Semiprecious s : this.semipreciousStones) {
            double currentOpacity = s.getOpacity();
            if(currentOpacity >= startOpacity && currentOpacity <= endOpacity) {
                sLength++;
            }
        }

        Gemstone[] newGemstones = new Gemstone[gLength];
        Semiprecious[] newSemipreciousStones = new Semiprecious[sLength];
        int gCounter = 0;
        int sCounter = 0;

        for(int i = 0; i < this.gemStones.length; i++) {
            double currentOpacity = this.gemStones[i].getOpacity();
            if(currentOpacity >= startOpacity && currentOpacity <= endOpacity) {
                newGemstones[gCounter] = this.gemStones[i];
                gCounter++;
            }
        }

        for(int i = 0; i < this.semipreciousStones.length; i++) {
            double currentOpacity = this.semipreciousStones[i].getOpacity();
            if(currentOpacity >= startOpacity && currentOpacity <= endOpacity) {
                newSemipreciousStones[sCounter] = this.semipreciousStones[i];
                sCounter++;
            }
        }

        return new Necklace(newSemipreciousStones, newGemstones);
    }

    @Override
    public String toString() {
        String res = "-----------------------------\n";
        res += "gemstones:";

        for(Gemstone g : this.gemStones) {
            res += "\n\t" + g.toString();
        }

        res += "\nsemiprecious stones:";

        for(Semiprecious s : this.semipreciousStones) {
            res += "\n\t" + s.toString();
        }

        return res + "\n";
    }

    @Override
    public boolean equals(Object obj) {
        if(!(obj instanceof Necklace)) {
            return false;
        }

        Necklace necklace = (Necklace) obj;
        Gemstone[] gemstones = necklace.getGemStones();
        Semiprecious[] semiprecious = necklace.getSemipreciousStones();

        Gemstone[] thisGemstones = this.getGemStones();
        Semiprecious[] thisSemiprecios = this.getSemipreciousStones();

        if(!(semiprecious.length == thisSemiprecios.length && gemstones.length == thisGemstones.length)) {
            return false;
        }

        for(int i = 0; i < gemstones.length; i ++) {
            if(!thisGemstones[i].equals(gemstones[i])) {
                return false;
            }
        }

        for(int i = 0; i < semiprecious.length; i ++) {
            if(!thisSemiprecios[i].equals(semiprecious[i])) {
                return false;
            }
        }

        return true;
    }
}
