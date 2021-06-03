package com.company;

import com.company.dbconnectors.DBUtils;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.util.Scanner;

public class Main {
    static Logger logger = LogManager.getLogger(Main.class.getName());

    public static void main(String[] args) throws GemException {
        Scanner scanner = new Scanner(System.in);
        DBUtils dbUtils = new DBUtils();

        Semiprecious[] semiprecious = {
                dbUtils.getSemipreciousByName("amber"),
                dbUtils.getSemipreciousByName("apatite"),
                dbUtils.getSemipreciousByName("rhodochrosis"),
                dbUtils.getSemipreciousByName("euclase")};

        Gemstone[] gemstones = {
                dbUtils.getGemstoneByName("diamond"),
                dbUtils.getGemstoneByName("emerald"),
                dbUtils.getGemstoneByName("ruby"),
                dbUtils.getGemstoneByName("sapphire")
        };

        Necklace neck = new Necklace(semiprecious, gemstones);
        System.out.println(neck.toString() + "\n");

        System.out.println("Type:\n\t1 to find weight of a necklace\n\t2 to find the price of a necklace\n\t3 to sort gems on a necklace by price\n\t4 to filter gems by the opacity range\n");
        int option = scanner.nextInt();

        switch (option) {
            case 1:
                System.out.println("weight: " + neck.sumCarats() + " carats\n");
                break;
            case 2:
                System.out.println("necklace price: " + neck.sumPrice() + " griven\n");
                break;
            case 3:
                neck.sortGemstones();
                neck.sortSemiprecious();
                System.out.println(neck.toString() + "\n");
                break;
            case 4:
                System.out.println("filtered by opacity range:");
                System.out.println(neck.sortByOpacity(0.2, 0.75).toString() + "\n");
                break;
            default:
                System.out.println("Input option doesn't match any");
                break;
        }

        dbUtils.closeConnection();
        logger.info("completed without errors");
    }
}
