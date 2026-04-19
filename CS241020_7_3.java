/*
Anshu Lakshkar
0801CS241020
Assignment number - 7 (Tree - I)
Problem number - 3
Date of submission - 22nd Feb 2026
*/
public class  CS241020_7_3{
      static class Node25 {
        int DA25;
        Node25 LF25, RT25;

        Node25(int DA25) {
            this.DA25 = DA25;
            LF25 = null;
            RT25 = null;
        }
    }

    Node25 RTN25;   // root

    // Build Tree from Array
    public static Node25 BLD25(int ARR25[], int IDX25) {
        if (IDX25 >= ARR25.length)
            return null;

        Node25 RT25 = new Node25(ARR25[IDX25]);

        RT25.LF25 = BLD25(ARR25, 2 * IDX25 + 1);
        RT25.RT25 = BLD25(ARR25, 2 * IDX25 + 2);

        return RT25;
    }
    boolean ISMIR25(Node25 A25, Node25 B25) {
        if (A25 == null && B25 == null) return true;
        if (A25 == null || B25 == null) return false;

        return (A25.DA25 == B25.DA25)
                && ISMIR25(A25.LF25, B25.RT25)
                && ISMIR25(A25.RT25, B25.LF25);
    }
    boolean ISSYM25(Node25 RT25) {
        if (RT25 == null) return true;

        return ISMIR25(RT25.LF25, RT25.RT25);
    }

    public static void main(String[] args) {
        CS241020_7_3 TR25 = new CS241020_7_3();
        int ARR25[] = {1, 2, 2, 3, 4, 4, 3};
        TR25.RTN25 = BLD25(ARR25, 0);
    
        boolean RES25 = TR25.ISSYM25(TR25.RTN25);
        if (RES25)
            System.out.println("Tree is Symmetric");
        else
            System.out.println("Tree is Not Symmetric");
    }
}
