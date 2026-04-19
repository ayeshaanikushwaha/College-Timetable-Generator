public class chain {
    public static void main(String[] args) {
        Chaining c= new Chaining(2);
    }
}
class Chaining{
    Chaining(){
        System.out.println("No arguement");
    }
    Chaining(int a){
        System.out.println("One arguement");
    }
    Chaining(int a, int b){
        System.out.println("Two arguement");
    }
}