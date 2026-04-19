class A {
    static void show() {
        System.out.println("Parent");
    }
}

class B extends A {
    static void show() {
        System.out.println("Child");
    }
}

public class a31 {
    public static void main(String[] args) {
        A objA = new A();    
        B objB = new B();    
        A objRef = new B();  

        objA.show();
        objB.show();
        objRef.show();
    }
}

