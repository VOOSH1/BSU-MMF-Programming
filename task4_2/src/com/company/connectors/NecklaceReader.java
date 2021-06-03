package com.company.connectors;

import com.company.Necklace;

import java.io.*;
import java.util.concurrent.locks.ReentrantLock;

public class NecklaceReader extends Thread {
    private String fileName = "serializedFiles/necklaces.ser";
    private Necklace necklace = new Necklace();
    private ReentrantLock locker = new ReentrantLock();

    public Necklace getNecklace() {
        return this.necklace;
    }

    @Override
    public void run() {
        this.locker.lock();

        File file = new File(this.fileName);
        ObjectInputStream objectInputStream = null;

        try {
            FileInputStream fileInputStream = new FileInputStream(file);
            objectInputStream = new ObjectInputStream(fileInputStream);
            this.necklace = (Necklace) objectInputStream.readObject();
        } catch (ClassNotFoundException | IOException e) {
            e.printStackTrace();
        } finally {
            try {
                if (objectInputStream != null) {
                    objectInputStream.close();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        this.locker.unlock();
    }
}
