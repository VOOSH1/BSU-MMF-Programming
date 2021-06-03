

package com.company.models;

import java.util.Objects;

public class Gem {
    private double weight;
    private double price;
    private double visibility;
    private String name;

    public Gem() {
    }

    public Gem(double weight, double price, double visibility, String name) {
        this.weight = weight;
        this.price = price;
        this.visibility = visibility;
        this.name = name;
    }

    public double getWeight() {
        return weight;
    }

    public void setWeight(double weight) {
        this.weight = weight;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public double getVisibility() {
        return visibility;
    }

    public void setVisibility(double visibility) {
        this.visibility = visibility;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Gem gem = (Gem) o;
        return Double.compare(gem.weight, weight) == 0 &&
                Double.compare(gem.price, price) == 0 &&
                Double.compare(gem.visibility, visibility) == 0 &&
                Objects.equals(name, gem.name);
    }

    @Override
    public int hashCode() {
        return Objects.hash(weight, price, visibility, name);
    }

    @Override
    public String toString() {
        return "Gem{" +
                "weight=" + weight +
                ", price=" + price +
                ", visibility=" + visibility +
                ", name='" + name + '\'' +
                '}';
    }
}