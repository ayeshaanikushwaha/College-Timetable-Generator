import java.util.*;
public class a3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of two-wheelers:");
        int tw=sc.nextInt();
        System.out.print("Enter number of four-wheelers:");
        int fw=sc.nextInt();
        int v=tw+fw;
        System.out.print("Enter total numbers of wheels:");
        int w = sc.nextInt();
        if(2<=w||w%2==0||v<w){
            System.out.println("Total number of vehicles are:"+v);
            System.out.println("Total number of wheels are:"+w);
        }else{
            System.out.println("Invalid input");
        }
    }
}
