package com.company;

import org.junit.Assert;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class GemTest {

    @Test
    void getName() {
        Gem stone = new Gem("diamond", 0.35);
        String expected = "diamond";
        String actual = stone.getName();
        Assert.assertEquals(expected, actual);
    }
}