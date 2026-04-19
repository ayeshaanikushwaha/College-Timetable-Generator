import java.util.*;
public class a5 {
    //duplicate elements in a array
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter length of array: ");
        int n = sc.nextInt();
        int arr[]=new int[n];
        System.out.print("Enter array elements: ");
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        int x = arr.length;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]==arr[j]){
                    for(int k=j;k<n-1;k++){
                        int temp= arr[k];
                        arr[k+1]=arr[k];
                    }
                    x--;
                }
            }
        }
        System.out.println("Array:");
        for(int i=0;i<x;i++){
            System.out.println(arr[i]);
        }
        sc.close();
    }
}
