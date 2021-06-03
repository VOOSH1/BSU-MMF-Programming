package com.company;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;



class Catalog   {
    public interface MonitoringSystem{
        void startMonitoring();
    }
    MonitoringSystem addModule = () -> System.out.println("Книга добавлена");



    MonitoringSystem delModule = () -> System.out.println("Книга удалена");

    MonitoringSystem getAllModule = () -> System.out.println("Все книги возвращены");

    public static class Book{
        String name;
        String date;
        long countOfPages;

        public Book(String name, String date, long countOfPages) {
            this.name = name;
            this.date = date;
            this.countOfPages = countOfPages;
        }

        public String getName() {
            return name;
        }

        public void setName(String name) {
            this.name = name;
        }

        public String getDate() {
            return date;
        }

        public void setDate(String date) {
            this.date = date;
        }

        public Long getCountOfPages() {
            return countOfPages;
        }

        public void setCountOfPages(long countOfPages) {
            this.countOfPages = countOfPages;
        }

        @Override
        public String toString() {
            return "Book{" +
                    "name='" + name + '\'' +
                    ", date='" + date + '\'' +
                    ", countOfPages=" + countOfPages +
                    '}';
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Book book = (Book) o;
            return Objects.equals(name, book.name) &&
                    Objects.equals(date, book.date) &&
                    Objects.equals(countOfPages, book.countOfPages);
        }

        @Override
        public int hashCode() {
            return Objects.hash(name, date, countOfPages);
        }
    }
    private List<Book> books = new ArrayList<Book>();

    public class AddAndGetBooks{
        public void addBook(String name, String date, long countOfPages)
        {
            Book book = new Book(name,date, countOfPages);
            books.add(book);
            addModule.startMonitoring();
        }
        public Book getBook (int index){
            return books.get(index);
        }
        public List<Book> getAllBooks()
        {
            getAllModule.startMonitoring();
            return books;

        }
        public void delBook(int index){
            books.remove(index);
            delModule.startMonitoring();
        }
    }




}

public class Main {

    public static void main(String[] args) {
        Catalog catalog = new Catalog();
        Catalog.AddAndGetBooks addAndGetBooks = catalog.new AddAndGetBooks();
        addAndGetBooks.addBook("1","1",1);
        addAndGetBooks.addBook("2","2",2);
        System.out.println(addAndGetBooks.getAllBooks());
        addAndGetBooks.delBook(0);
        System.out.println(addAndGetBooks.getAllBooks());


    }
}
