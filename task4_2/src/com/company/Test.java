package com.company;

public class Test {
    private Necklace neck;
    private boolean mistakesDetected = false;

    public Test(Necklace neck) {
        this.neck = neck;
    }

    public boolean getMistakesDetected() { return this.mistakesDetected; }

    public void testOpacityRange() throws GemException {
        for(Gemstone g : this.neck.getGemStones()) {
            double currentOpacity = g.getOpacity();

            if(currentOpacity <= 0 || currentOpacity > 1) {
                this.mistakesDetected = true;
                break;
            }
        }

        for(Semiprecious s : this.neck.getSemipreciousStones()) {
            double currentOpacity = s.getOpacity();

            if(currentOpacity <= 0 || currentOpacity > 1) {
                this.mistakesDetected = true;
                break;
            }
        }
    }

    public void testGemCarats() {
        for(Gemstone g : this.neck.getGemStones()) {
            int currentCarats = g.getCarats();

            if(currentCarats <= 0) {
                this.mistakesDetected = true;
            }
        }
    }
}
