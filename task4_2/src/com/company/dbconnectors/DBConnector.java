package com.company.dbconnectors;

import java.sql.*;

public class DBConnector {
    private String url = "jdbc:mysql://localhost:3306/jewelry?useSSL=false";
    private String user = "root";
    private String password = "mysql123";
    private Connection connection;

    public DBConnector() {
        try {
            Class.forName("com.mysql.jdbc.Driver");
        } catch (ClassNotFoundException e) {
            System.out.println(e.getMessage());
        }
    }

    public Connection getConnection() {
        try {
            this.connection = DriverManager.getConnection(this.url, this.user, this.password);
            return this.connection;
        } catch (SQLException e) {
            System.out.println(e.getMessage());
            return null;
        }
    }

    public void closeConnection() {
        try {
            this.connection.close();
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
    }
}
