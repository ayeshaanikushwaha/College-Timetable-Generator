interface Animal {
    void move();
    void makeSound();
}

class Bird implements Animal {
    @Override
    public void move() {
        System.out.println("Bird flies in the sky.");
    }

    @Override
    public void makeSound() {
        System.out.println("Bird chirps melodiously.");
    }
}

class Panthera implements Animal {
    @Override
    public void move() {
        System.out.println("Panthera prowls swiftly on land.");
    }

    @Override
    public void makeSound() {
        System.out.println("Panthera roars loudly!");
    }
}

public class AnimalTest {
    public static void main(String[] args) {
        Animal[] animals = { new Bird(), new Panthera() };

        for (Animal a : animals) {
            a.move();
            a.makeSound();
            System.out.println("------------------");
        }
    }
}
