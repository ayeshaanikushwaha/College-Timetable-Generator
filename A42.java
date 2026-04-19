abstract class Shape {
    abstract double area();

    abstract void whoAmI();
}

class Circle extends Shape {
    double radius;

    Circle(double r) {
        this.radius = r;
    }

    @Override
    double area() {
        return Math.PI * radius * radius;
    }

    @Override
    void whoAmI() {
        System.out.println("I am a Circle");
    }
}

class Rectangle extends Shape {
    double length, width;

    Rectangle(double l, double w) {
        this.length = l;
        this.width = w;
    }

    @Override
    double area() {
        return length * width;
    }

    @Override
    void whoAmI() {
        System.out.println("I am a Rectangle");
    }
}

public class A42 {

    static void printShapeDetails(Shape[] shapes) {
        for (Shape s : shapes) {
            s.whoAmI();
            System.out.println("Area = " + s.area());
        }
    }

    public static void main(String[] args) {

        Shape[] shapes = new Shape[3];
        shapes[0] = new Circle(5);
        shapes[1] = new Rectangle(4, 6);
        shapes[2] = new Circle(3);

        printShapeDetails(shapes);
    }
}