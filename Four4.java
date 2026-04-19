class Customer {
    public String name;
    public String membership;
    Customer(String name, String membership) {
        this.name = name;
        this.membership = membership;
    }
}

class Visit extends Customer {
    double service_spend;
    double product_spend;
    Visit(String name, String membership, int service_spend, int product_spend) {
        super(membership, name);
        this.product_spend = product_spend;
        this.service_spend = service_spend;
    }
}

class Discount extends Visit {

    Discount(String name, String membership, int service_spend, int product_spend) {
        super(name, membership, service_spend, product_spend);
    }

    public double calculateDiscount() {
        if(membership == "Premium") {
            service_spend = service_spend - (service_spend*0.2);
            product_spend = product_spend - (product_spend*0.1);
            return service_spend+product_spend;
        } else if (membership == "Gold") {
            service_spend = service_spend - (service_spend*0.15);
            product_spend = product_spend - (product_spend*0.1);
            return service_spend+product_spend;
        } else if (membership == "Silver") {
            service_spend = service_spend - (service_spend*0.1);
            product_spend = product_spend - (product_spend*0.1);
            return service_spend+product_spend;
        } else {
            return 0;
        }
    }
}

public class Four4 {
    public static void main(String[] args) {
        Discount d = new Discount("Premium", "ABC", 300, 100);
        System.out.println("Total Bill:");
        System.out.println("Name: " + d.name);
        System.out.println("Membership: " + d.membership);
        System.out.println("Total amount: " + d.calculateDiscount());
    }
}