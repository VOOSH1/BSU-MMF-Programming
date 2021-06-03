package com.company;

import org.junit.Assert;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class NecklaceTest {

    Necklace getNecklace() {
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



        Necklace neck = new Necklace(semipreciousStones, gemStones);
        return neck;
    }

    Necklace getSortedNecklace() {
        Semiprecious amber = new Semiprecious("amber", 0.7, 100);
        Semiprecious apatite = new Semiprecious("apatite", 0.65, 140);
        Semiprecious euclase = new Semiprecious("euclase", 0.42, 210);

        Semiprecious[] semipreciousStones = {amber, apatite, euclase};

        Gemstone emerald = new Gemstone("emerald", 0.5, 7, 14500);
        Gemstone ruby = new Gemstone("ruby", 0.52, 14, 8200);
        Gemstone sapphire = new Gemstone("sapphire", 0.37, 9, 17100);

        Gemstone[] gemStones = {emerald, ruby, sapphire};

        Necklace neck = new Necklace(semipreciousStones, gemStones);
        return neck;
    }

    @Test
    void sumCarats() {
        Necklace neck = this.getNecklace();
        int expected = 42;
        int actual = neck.sumPrice();
        Assert.assertEquals(expected, actual);
    }

    @Test
    void sumPrice() {
        Necklace neck = this.getNecklace();
        int expected = 50_345;
        int actual = neck.sumPrice();
        Assert.assertEquals(expected, actual);
    }

    @Test
    void sortByOpacity() throws GemException {
        Necklace neck = this.getNecklace();
        Necklace expected = this.getSortedNecklace();
        Necklace actual = neck.sortByOpacity(0.2, 0.75);
        Assert.assertEquals(expected, actual);
    }
}
