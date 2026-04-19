abstract class Animal{
    abstract void move();
    abstract void makesound();
}
class Bird extends Animal{
    void move(){
        System.out.println("Bird flies in the Sky");
    }
    void makesound(){
        System.out.println("Bird Chirps");
    }
}
class Panthera extends Animal{
    void move(){
        System.out.println("Panthera walks");
    }
    void makesound(){
        System.out.println("Panthera roars");
    }
}
public class A43{
    public static void main(String[] args) {
        Animal p=new Panthera();
        p.makesound();
        p.move();
        Animal b=new Bird();
        b.makesound();
        b.move();
        
    }
    
}