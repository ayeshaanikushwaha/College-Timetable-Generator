class Vehicle{
    protected String brand;
    protected String model;
    protected double price;

public Vehicle(String brand, String model, double price) {
        this.brand = brand;
        this.model = model;
        this.price = price;
    }
     @Override
    public String toString() {
        return "Vehicle " + brand + ":" + model + ":" + price;
    }
}
class ElectricVehicle extends Vehicle {
    private int batteryCapacity;

    public ElectricVehicle(String brand, String model, double price, int batteryCapacity) {
        super(brand, model, price); 
        this.batteryCapacity = batteryCapacity;
    }

    @Override
    public String toString() {
        return "ElectricVehicle " + brand + ":" + model + ":" + batteryCapacity + ":" + price;
    }
}

public class demo {
     public static void main(String[] args) {
        Vehicle[] vehicles = new Vehicle[3];
        
        vehicles[0] = new Vehicle("Toyota", "Corolla", 15000);
        vehicles[1] = new ElectricVehicle("Tesla", "Model 3", 35000, 75);
        vehicles[2] = new Vehicle("Honda", "Civic", 18000);

        for (Vehicle v : vehicles) {
            System.out.println(v);
        }
    }
}
