package com.company;

import org.junit.Assert;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class GemstoneTest {

    @Test
    void getCarats() {
        Gemstone gemstone = new Gemstone("ruby", 0.65, 12, 13000);
        int expected = 12;
        int actual = gemstone.getCarats();
        Assert.assertEquals(expected, actual);
    }
}