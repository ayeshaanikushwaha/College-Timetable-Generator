class Reservation {
    int reservationId;
    String customerName;
    String date;

    Reservation(int reservationId, String customerName, String date) {
        this.reservationId = reservationId;
        this.customerName = customerName;
        this.date = date;
    }

    void checkStatus() {
        System.out.println("Reservation ID: " + reservationId + " is confirmed.");
    }

    void modifyDetails(String newName, String newDate) {
        this.customerName = newName;
        this.date = newDate;
        System.out.println("Reservation details updated.");
    }

    void displayDetails() {
        System.out.println("Reservation ID: " + reservationId);
        System.out.println("Customer Name: " + customerName);
        System.out.println("Date: " + date);
    }
}
class ResortReservation extends Reservation {
    int roomNumber;

    ResortReservation(int reservationId, String customerName, String date, int roomNumber) {
        super(reservationId, customerName, date);
        this.roomNumber = roomNumber;
    }
    @Override
    void displayDetails() {
        super.displayDetails();
        System.out.println("Room Number: " + roomNumber);
    }
}

class RailwayReservation extends Reservation {
    int seatNumber;

    RailwayReservation(int reservationId, String customerName, String date, int seatNumber) {
        super(reservationId, customerName, date);
        this.seatNumber = seatNumber;
    }

    @Override
    void displayDetails() {
        super.displayDetails();
        System.out.println("Seat Number: " + seatNumber);
    }
}

public class a32{
    public static void main(String[] args) {
        ResortReservation resort = new ResortReservation(101, "Apoorv", "20-Aug-2025", 205);
        resort.checkStatus();
        resort.displayDetails();
        resort.modifyDetails("Anshika jharia", "21-Aug-2025");
        resort.displayDetails();

        System.out.println();

        RailwayReservation railway = new RailwayReservation(202, "Rahul", "25-Aug-2025", 45);
        railway.checkStatus();
        railway.displayDetails();
        railway.modifyDetails("anshu lakshkar", "26-Aug-2025");
        railway.displayDetails();
    }
}