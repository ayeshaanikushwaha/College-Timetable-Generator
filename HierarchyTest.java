import java.util.*;

interface Hierarchy {
    boolean isSupervisorOf(Employee e);
    List<Employee> getSubordinates();
    List<Employee> getSupervisors();
}

class Employee implements Hierarchy {
    private String name;
    private List<Employee> subordinates = new ArrayList<>();
    private List<Employee> supervisors = new ArrayList<>();

    public Employee(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void addSubordinate(Employee e) {
        subordinates.add(e);
        e.supervisors.add(this);
    }

    @Override
    public boolean isSupervisorOf(Employee e) {
        return subordinates.contains(e);
    }

    @Override
    public List<Employee> getSubordinates() {
        return subordinates;
    }

    @Override
    public List<Employee> getSupervisors() {
        return supervisors;
    }

    @Override
    public String toString() {
        return name;
    }
}

// ---------------- Driver ----------------
public class HierarchyTest{
    public static void main(String[] args) {
        Employee manager = new Employee("Ravi");
        Employee lead = new Employee("Anita");
        Employee dev1 = new Employee("Karan");
        Employee dev2 = new Employee("Tina");

        manager.addSubordinate(lead);
        lead.addSubordinate(dev1);
        lead.addSubordinate(dev2);

        printHierarchy(manager);
        printHierarchy(lead);
        printHierarchy(dev1);
    }

    private static void printHierarchy(Employee e) {
        System.out.println("\nEmployee: " + e.getName());
        System.out.println("Supervisors: " + (e.getSupervisors().isEmpty() ? "None" : e.getSupervisors()));
        System.out.println("Subordinates: " + (e.getSubordinates().isEmpty() ? "None" : e.getSubordinates()));
    }
}

