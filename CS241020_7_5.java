/*
Anshu Lakshkar
0801CS241020
Assignment number - 7 (Tree - I)
Problem number - 5
Date of submission - 22nd Feb 2026
*/

public class CS241020_7_5 {
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
    boolean CHSUM25(Node25 RT25) {

        if (RT25 == null || 
           (RT25.LF25 == null && RT25.RT25 == null))
            return true;

        int L25 = (RT25.LF25 != null) ? RT25.LF25.DA25 : 0;
        int R25 = (RT25.RT25 != null) ? RT25.RT25.DA25 : 0;

        return (RT25.DA25 == L25 + R25) && CHSUM25(RT25.LF25) && CHSUM25(RT25.RT25);
    }

    public static void main(String[] args) {
        CS241020_7_5 TR25 = new CS241020_7_5();
        int ARR25[] = {10, 8, 2, 3, 5};
        TR25.RTN25 = BLD25(ARR25, 0);
        if (TR25.CHSUM25(TR25.RTN25))
            System.out.println("Tree satisfies Children Sum Property");
        else
            System.out.println("Tree does NOT satisfy Children Sum Property");
    }   
}
