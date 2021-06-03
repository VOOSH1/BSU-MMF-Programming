package com.company;

import java.io.Serializable;

public class Gem implements Serializable {
    private String name;
    private double opacity;

    public Gem(String name, double opacity) {
        this.name = name;
        this.opacity = opacity;
    }

    public Gem(String name) {
        this.name = name;
        this.opacity = 1;
    }

    public Gem() {
        this("", 1);
    }

    public String getName() { return this.name; }

    public double getOpacity() throws GemException {
        if(this.opacity < 0 || this.opacity > 1) {
            throw new GemException("Wrong opacity value", this.opacity);
        }

        return this.opacity;
    }

    @Override
    public String toString() {
        return "Gem " + this.name + ", opacity: " + this.opacity;
    }

    @Override
    public boolean equals(Object obj) {
        if(!(obj instanceof Gem)) {
            return false;
        }

        Gem gem = (Gem) obj;
        return gem.name.equals(this.name) && gem.opacity == this.opacity;
    }
}
