import java.util.Scanner;

public class a37 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter array length:");
        int n = sc.nextInt();
        int num=0;

        int arr[]= new int[n];
        System.out.print("Enter array elements:");
        for(int i=0;i<arr.length;i++){
            arr[i]=sc.nextInt();
        }
        for(int i=0;i<arr.length;i++){
            int lastD=arr[i]%10;
            num= num*10+ lastD;
        }
        if(num%10==0){
            System.out.println("YES");
        }else{
            System.out.println("NO");
        }
        sc.close();
    }
}
