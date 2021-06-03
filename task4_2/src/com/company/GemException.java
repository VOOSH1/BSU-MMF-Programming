package com.company;

public class GemException extends Exception {
    private double opacity;

    public GemException(String message, double opacity) {
        super(message);
        this.opacity = opacity;
    }
}
