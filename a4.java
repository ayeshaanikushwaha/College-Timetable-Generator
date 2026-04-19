import java.util.*;

public class a4 {
    public static void main(String[] args) {
        int income;
        int age;
        System.out.print("Enter age of person: ");
        Scanner sc = new Scanner(System.in);
        age = sc.nextInt();
        System.out.print("Enter income of person: ");
        income = sc.nextInt();

        float tax;

        if(age <= 59) {
            if(income <= 250000) {
                System.out.println("No tax");
            } else if(income > 250000 && income <= 500000) {
                tax = (9*income)/100;   
                System.out.println("Amount of income tax is " + tax);
            } else if(income > 500000 && income <= 1000000) {
                tax = (24*income)/100;
                System.out.println("Amount of income tax is " + tax);
            } else if(income > 1000000) {
                tax = (34*income)/100;
                System.out.println("Amount of income tax is " + tax);
            }
        } else {
            if(income <= 300000) {
                System.out.println("No income tax");
            } else if(income > 300000 && income <= 500000) {
                tax = (9*income)/100;
                System.out.println("Amount of income tax is " + tax);
            } else if(income > 500000 && income <= 1000000) {
                tax = (24*income)/100;
                System.out.println("Amount of income tax is " + tax);
            } else if(income > 1000000) {
                tax = (34*income)/100;
                System.out.println("Amount of income tax is " + tax);
            }
        }
        sc.close();
    }
}