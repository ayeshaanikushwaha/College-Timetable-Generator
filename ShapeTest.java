interface Shape {
    int IRREGULAR = 1;
    int REGULAR_POLYGON = 2;
    int ARC_TYPE = 3;
    int OTHER_TYPE = 4;

    void whoAmI();
    double calculateArea();

    default int getType() {
        return OTHER_TYPE;
    }
}

class Circle implements Shape {
    private double radius;

    Circle(double radius) {
        this.radius = radius;
    }

    @Override
    public void whoAmI() {
        System.out.println("I am a Circle");
    }

    @Override
    public double calculateArea() {
        return Math.PI * radius * radius;
    }

    @Override
    public int getType() {
        return ARC_TYPE;
    }
}

class Square implements Shape {
    private double side;

    Square(double side) {
        this.side = side;
    }

    @Override
    public void whoAmI() {
        System.out.println("I am a Square");
    }

    @Override
    public double calculateArea() {
        return side * side;
    }

    @Override
    public int getType() {
        return REGULAR_POLYGON;
    }
}

class Triangle implements Shape {
    private double base, height;

    Triangle(double base, double height) {
        this.base = base;
        this.height = height;
    }

    @Override
    public void whoAmI() {
        System.out.println("I am a Triangle");
    }

    @Override
    public double calculateArea() {
        return 0.5 * base * height;
    }

    @Override
    public int getType() {
        return IRREGULAR;
    }
}

public class ShapeTest {
    public static void main(String[] args) {
        Shape[] shapes = {
            new Circle(5),
            new Square(4),
            new Triangle(6, 8)
        };

        for (Shape s : shapes) {
            s.whoAmI();
            System.out.printf("Area: %.2f | Type: %d%n", s.calculateArea(), s.getType());
            System.out.println("-----------------------------------");
        }
    }
}

