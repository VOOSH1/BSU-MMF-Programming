package com.company.connectors;

import com.company.Necklace;

import java.io.*;
import java.util.concurrent.locks.ReentrantLock;

public class NecklaceWriter extends Thread {
    private String fileName = "serializedFiles/necklaces.ser";
    private Necklace necklace;
    private ReentrantLock locker = new ReentrantLock();

    public NecklaceWriter(Necklace necklace) {
        this.necklace = necklace;
    }

    public Necklace getNecklace() {
        return necklace;
    }

    @Override
    public void run() {
        this.locker.lock();

        File file = new File(this.fileName);
        ObjectOutputStream objectOutputStream = null;

        try {
            FileOutputStream fileOutputStream = new FileOutputStream(file);
            objectOutputStream = new ObjectOutputStream(fileOutputStream);
            objectOutputStream.writeObject(this.necklace);
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                if (objectOutputStream != null) {
                    objectOutputStream.close();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        this.locker.unlock();
    }
}
