class Rectangle{
    int length;
    int breadth;
    // Method to calculate area
    int calcArea(){
        return length*breadth;
    }
    // 1. No-parameter constructor
    Rectangle(){
        length = 0;
        breadth = 0;
    }
    // 2. Constructor with two parameters
    Rectangle(int side){
        length = side;
        breadth = side;
    }
    // 3. Constructor with one parameter
    Rectangle(int l, int b){
        length = l;
        breadth = b;
    }
}
public class a34 {
    public static void main(String[] args) {
        // No-parameter constructor
        Rectangle r1 = new Rectangle();
        System.out.println("Area (no parameters): " + r1.calcArea());

        // Two-parameter constructor
        Rectangle r2 = new Rectangle(5, 3);
        System.out.println("Area (two parameters): " + r2.calcArea());

        // One-parameter constructor
        Rectangle r3 = new Rectangle(4);
        System.out.println("Area (one parameter): " + r3.calcArea());
    }
}
