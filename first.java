
public class first {
        public static void main(String[] args){
        //car object
        Cars c1 = new Cars();
        Cars c2 = new Cars();
        c1.display("Honda","grey",8000);
        c2.display("ABC","Black",8000);
    }
}
class Cars{
        String model;
        String color;
        int prize;
        //method for display car details
        void display(String m,String c,int p){
        System.out.println("Model pf the car is "+m);
        System.out.println("Color of the car is "+c);
        System.out.println("Prize of the car is "+p);
    }
}
