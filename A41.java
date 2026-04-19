abstract class Shape {
    abstract public void whoAmI();

    abstract public double calculateArea();
}

class Circle extends Shape {
    double radius;

    public void whoAmI() {
        System.out.println("I am  a circle");
    }

    public double calculateArea() {
        return Math.PI * radius * radius;
    }

    Circle(int r) {
        this.radius = r;
    }
}

class Square extends Shape {
    double side;

    public void whoAmI() {
        System.out.println("I am  a square");
    }

    public double calculateArea() {
        return side * side;
    }

    Square(int s) {
        this.side = s;
    }
}

class Triangle extends Shape {
    double height;
    double base;

    public void whoAmI() {
        System.out.println("I am  a triangle");
    }

    public double calculateArea() {
        return 0.5 * base * height;
    }

    Triangle(double b, double h) {
        this.height = h;
        this.base = b;
    }
}

public class A41 {
    public static void main(String[] args) {
        Shape t = new Triangle(3, 4);
        double area = t.calculateArea();
        System.out.println(area);
    }
}
write a java program to create a banking system with 3 classes banking account and current acount ,
saving acount the bank should have a list of acounts and methods for adding them acount should be an 
interface with methods to deposit , withdraw , calculate interest and view balance , saving acount and current 
account should implement the account interface and their own unique method 
