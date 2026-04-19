
public class fifth {
    public static void main(String args[]){
        int num =1;
        //outer loop(for rows)
        for(int i=1; i<=4; i++){
            // inner loop(for columns)
            for(int j=1; j<=i; j++){
                System.out.print(num+" ");
                num++;
            }
            System.out.println();
        }
    }
}
