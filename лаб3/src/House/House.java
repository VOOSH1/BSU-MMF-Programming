package House;

public class House {
    private String id, apartmentNumber, street, typeOfBuilding, lifeTime;
    private int square, flat, numberOfRooms;

    public House(String id, String apartmentNumber, int square, int flat, int numberOfRooms, String street, String typeOfBuilding, String lifeTime) {
        this.id = id;
        this.apartmentNumber = apartmentNumber;
        this.square = square;
        this.flat = flat;
        this.numberOfRooms = numberOfRooms;
        this.street = street;
        this.typeOfBuilding = typeOfBuilding;
        this.lifeTime = lifeTime;
    }

    public void setId(String id) {
        this.id = id;
    }
    public String getId() {
        return this.id;
    }

    public void setApartmentNumber(String apartmentNumber) {
        this.apartmentNumber = apartmentNumber;
    }
    public String getApartmentNumber() {
        return this.apartmentNumber;
    }

    public void setSquare(int square) {
        this.square = square;
    }
    public int getSquare() {
        return this.square;
    }

    public void setFlat(int flat) {
        this.flat = flat;
    }
    public int getFlat() {
        return this.flat;
    }

    public void setNumberOfRooms(int numberOfRooms) {
        this.numberOfRooms = numberOfRooms;
    }
    public int getNumberOfRooms() {
        return this.numberOfRooms;
    }

    public void setStreet(String street) {
        this.street = street;
    }
    public String getStreet() {
        return this.street;
    }

    public void setTypeOfBuilding(String typeOfBuilding) {
        this.typeOfBuilding = typeOfBuilding;
    }
    public String getTypeOfBuilding() {
        return this.typeOfBuilding;
    }

    public void setLifeTime(String lifeTime) {
        this.lifeTime = lifeTime;
    }
    public String getLifeTime() {
        return this.lifeTime;
    }

    @Override
    public String toString() {
        return "ID: " + this.id + "\n" +
                "apartmentNumber: " + this.apartmentNumber + "\n" +
                "square: " + this.square + "\n" +
                "flat: " + this.flat + "\n" +
                "numberOfRooms: " + this.numberOfRooms + "\n" +
                "street: " + this.street + "\n" +
                "typeOfBuilding: " + this.typeOfBuilding + "\n" +
                "lifeTime: " + this.lifeTime + "\n";
    }

}
