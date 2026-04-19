class Member {
    String name;
    int age;
    String phoneNumber;
    String address;
    double salary;

    public void printSalary() {
        System.out.println("Salary: " + salary);
    }

    public void displayDetails() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Phone Number: " + phoneNumber);
        System.out.println("Address: " + address);
        printSalary();
    }
}

class Employee extends Member {
    String specialization;
}

class Manager extends Member {
    String department;
}
public class a33{
    public static void main(String[] args) {
        Employee emp = new Employee();
        emp.name = "John Doe";
        emp.age = 30;
        emp.phoneNumber = "9876543210";
        emp.address = "123, Green Street";
        emp.salary = 50000;
        emp.specialization = "Software Development";

        Manager mgr = new Manager();
        mgr.name = "Alice Smith";
        mgr.age = 40;
        mgr.phoneNumber = "9123456780";
        mgr.address = "456, Blue Avenue";
        mgr.salary = 80000;
        mgr.department = "IT Department";

        System.out.println("Employee Details:");
        emp.displayDetails();
        System.out.println("Specialization: " + emp.specialization);

        System.out.println("\nManager Details:");
        mgr.displayDetails();
        System.out.println("Department: " + mgr.department);
    }
}
