import java.util.*;

class Laptop {
    private String brand;
    private String processor;
    private double price;

    public Laptop(String brand, String processor, double price) {
        setBrand(brand);
        setProcessor(processor);
        setPrice(price);
    }

    public String getBrand() {
        return brand;
    }

    public void setBrand(String brand) {
        this.brand = (brand == null || brand.isBlank()) ? "Unknown" : brand;
    }

    public String getProcessor() {
        return processor;
    }

    public void setProcessor(String processor) {
        this.processor = (processor == null || processor.isBlank()) ? "Not Specified" : processor;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = (price <= 0) ? 10000 : price;
    }

    @Override
    public String toString() {
        return String.format("Brand: %s | Processor: %s | Price: ₹%.2f", brand, processor, price);
    }
}

public class a54{
    public static void main(String[] args) {
        ArrayList<Laptop> laptops = new ArrayList<>();
        laptops.add(new Laptop("HP", "i5", 55000));
        laptops.add(new Laptop("Dell", "", -5000));
        laptops.add(new Laptop("Lenovo", "Ryzen 5", 65000));
        laptops.add(new Laptop(null, "i7", 0));

        System.out.println("All Laptops:");
        laptops.forEach(System.out::println);

        double threshold = 30000;
        System.out.println("\nLaptops above ₹" + threshold + ":");
        laptops.stream()
               .filter(l -> l.getPrice() > threshold)
               .sorted(Comparator.comparingDouble(Laptop::getPrice))
               .forEach(System.out::println);
    }
}
