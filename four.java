import java.util.Scanner;

public class four {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        //scanning height
        System.out.print("Enter persons height:");
        int h=sc.nextInt();
        //checking height
        if(h>=175){
            System.out.println("Person is tall");
        }
        else if(h<175 && h>=155){
            System.out.println("Person is average");
        }
        else{
            System.out.println("Person is dwarf");
        }
        sc.close();
    }
}