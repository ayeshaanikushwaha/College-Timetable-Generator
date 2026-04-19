import java.util.*;

public class third {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();
        // input numbers
        int num[] = new int[n];
        System.out.print("Enter numbers: ");
        for(int i=0;i<n;i++){
         num[i]=sc.nextInt();
        }
        int sumo=0;
        int sume=0;
        for(int i=0;i<n;i++){
            // sum of even numbers
            if(num[i]%2==0){
                sume+=num[i];
            }
            // sum of odd numbers
            if(num[i]%2!=0){
                sumo+=num[i];
            }
        }
        System.out.println("Sum of odd numbers are: "+sumo);
        System.out.println("Sum of even numbers are: "+sume);
        sc.close();
    }
}
