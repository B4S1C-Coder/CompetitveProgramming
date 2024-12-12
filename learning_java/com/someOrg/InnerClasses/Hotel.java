package com.someOrg.InnerClasses;

public class Hotel {
    private String name;
    private int totalRooms;
    private int reservedRooms;

    public Hotel(String name, int totalRooms, int reservedRooms) {
        this.name = name;
        this.totalRooms = totalRooms;
        this.reservedRooms = reservedRooms;
    }

    public void reserveRoom(String guestName, int numOfRooms) {
        // This is a local member class used to encapsulate the validation logic.
        // This class would be accessible only within this method
        class ReservationValidator {
            boolean validate() {
                if (guestName == null || guestName.isBlank()) {
                    return false;
                }
                if (numOfRooms < 0) {
                    return false;
                }
                if (reservedRooms + numOfRooms > totalRooms) {
                    return false;
                }
                return true;
            }
        }
        
        ReservationValidator validator = new ReservationValidator();
        if (validator.validate()) {
            reservedRooms += numOfRooms;
            System.out.println("CNF GU: "+guestName+" RC: "+numOfRooms);
        } else {
            System.out.println("FLD");
        }
    }
}
