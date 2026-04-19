/*
Anshu Lakshkar
0801CS241020
Assignment number - 7 (Tree - I)
Problem number - 4
Date of submission - 22nd Feb 2026
*/

public class Cs241020_7_4 {
    static class Node25 {
        int DA25;
        Node25 LF25, RT25;

        Node25(int DA25) {
            this.DA25 = DA25;
            LF25 = null;
            RT25 = null;
        }
    }
    Node25 RTN25;
    // Build Tree from Array
    public static Node25 BLD25(int ARR25[], int IDX25) {
        if (IDX25 >= ARR25.length)
            return null;

        Node25 RT25 = new Node25(ARR25[IDX25]);

        RT25.LF25 = BLD25(ARR25, 2 * IDX25 + 1);
        RT25.RT25 = BLD25(ARR25, 2 * IDX25 + 2);

        return RT25;
    }

    // Height of Tree
    int HGHT25(Node25 RT25) {
        if (RT25 == null) return 0;

        return 1 + Math.max(HGHT25(RT25.LF25),HGHT25(RT25.RT25));
    }
    // Check Balanced
    boolean ISBAL25(Node25 RT25) {
        if (RT25 == null) return true;

        int LH25 = HGHT25(RT25.LF25);
        int RH25 = HGHT25(RT25.RT25);

        return Math.abs(LH25 - RH25) <= 1 && ISBAL25(RT25.LF25) && ISBAL25(RT25.RT25);
    }
     public static void main(String[] args) {
       Cs241020_7_4 TR25 = new Cs241020_7_4();
        int ARR25[] = {1, 2, 2, 3, 4, 4};
        TR25.RTN25 = BLD25(ARR25, 0);
        if (TR25.ISBAL25(TR25.RTN25))
            System.out.println("Tree is Balanced");
        else
            System.out.println("Tree is Not Balanced");

     }
}
