import java.util.ArrayList;

class OnlineShoppingCart {
    private ArrayList<String> items = new ArrayList<>();
    private double totalAmount = 0.0;

    public void addItem(String item, double price) {
        if (item != null && !item.isBlank() && price > 0) {
            items.add(item + " - ₹" + price);
            totalAmount += price;
        } else {
            System.out.println("Invalid item or price!");
        }
    }

    public void removeItem(String item, double price) {
        if (items.remove(item + " - ₹" + price)) {
            totalAmount -= price;
        } else {
            System.out.println("Item not found in cart!");
        }
    }

    public void displayCart() {
        System.out.println("🛒 Cart Items:");
        for (String i : items) System.out.println(" - " + i);
        System.out.printf("Total Amount: ₹%.2f%n", totalAmount);
    }

    public static void main(String[] args) {
        OnlineShoppingCart cart = new OnlineShoppingCart();
        cart.addItem("Lipstick", 499.99);
        cart.addItem("Shampoo", 299.50);
        cart.displayCart();
        cart.removeItem("Lipstick", 499.99);
        cart.displayCart();
    }
}
