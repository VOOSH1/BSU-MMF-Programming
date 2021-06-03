package com.company.dbconnectors;

import com.company.Gemstone;
import com.company.Main;
import com.company.Semiprecious;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class DBUtils {
    private DBConnector dbConnector;
    private Connection connection;

    static Logger logger = LogManager.getLogger(Main.class.getName());

    public DBUtils() {
        this.dbConnector = new DBConnector();
        this.connection = this.dbConnector.getConnection();
    }

    public ResultSet getQueryResultAsResultSet(String query) {
        Statement statement = null;
        try {
            statement = this.connection.createStatement();
            return statement.executeQuery(query);
        } catch (SQLException e) {
            System.out.println(e.getMessage());
            return null;
        }
    }

    public void executeInsertOrUpdateOrDeleteQuery(String query) {
        Statement statement = null;
        try {
            statement = this.connection.createStatement();
            statement.executeUpdate(query);
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
    }

    public Gemstone getGemstoneByName(String gemstoneName) {
        Gemstone gemstone = new Gemstone();

        String gemstoneQuery = new StringBuilder("SELECT * FROM GEMSTONE WHERE NAME = '")
                .append(gemstoneName)
                .append("'").toString();
        ResultSet resultSet = this.getQueryResultAsResultSet(gemstoneQuery);

        try {
            resultSet.next();

            String name = resultSet.getString("NAME");
            double opacity = resultSet.getDouble("OPACITY");
            int carats = resultSet.getInt("CARATS");
            int price = resultSet.getInt("PRICE");

            gemstone = new Gemstone(name, opacity, carats, price);

        } catch (SQLException e) {
            logger.error(e.getMessage());
        }

        return gemstone;
    }

    public Semiprecious getSemipreciousByName(String semipreciousName) {
        Semiprecious semiprecious = new Semiprecious();

        String semipreciousQuery = new StringBuilder("SELECT * FROM SEMIPRECIOUS WHERE NAME = '")
                .append(semipreciousName)
                .append("'").toString();
        ResultSet resultSet = this.getQueryResultAsResultSet(semipreciousQuery);

        try {
            resultSet.next();

            String name = resultSet.getString("NAME");
            double opacity = resultSet.getDouble("OPACITY");
            int price = resultSet.getInt("PRICE");

            semiprecious = new Semiprecious(name, opacity, price);

        } catch (SQLException e) {
            logger.error(e.getMessage());
        }

        return semiprecious;
    }

    public void closeConnection() {
        try {
            this.connection.close();
        } catch (SQLException e) {
            logger.error(e.getMessage());
        }
    }
}
