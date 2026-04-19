/*
Anshu Lakshkar
0801CS241020
Assignment number - 7 (Tree - I)
Problem number - 1
Date of submission - 22nd Feb 2026
*/
import java.util.*;

public class CS241020_7_1 {
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

    // Insert using Level Order
    public void INS25(int VAL25) {

        Node25 NEW25 = new Node25(VAL25);

        if (RTN25 == null) {
            RTN25 = NEW25;
            return;
        }

        Queue<Node25> Q25 = new LinkedList<>();
        Q25.add(RTN25);

        while (!Q25.isEmpty()) {

            Node25 TMP25 = Q25.poll();

            if (TMP25.LF25 == null) {
                TMP25.LF25 = NEW25;
                return;
            } else Q25.add(TMP25.LF25);

            if (TMP25.RT25 == null) {
                TMP25.RT25 = NEW25;
                return;
            } else Q25.add(TMP25.RT25);
        }
    }

    // Inorder Traversal
    public void INO25(Node25 ND25) {
        if (ND25 == null) return;

        INO25(ND25.LF25);
        System.out.print(ND25.DA25 + " ");
        INO25(ND25.RT25);
    }

    // Level Order Traversal
    public void LEV25() {
        if (RTN25 == null) return;

        Queue<Node25> Q25 = new LinkedList<>();
        Q25.add(RTN25);

        while (!Q25.isEmpty()) {
            Node25 TMP25 = Q25.poll();
            System.out.print(TMP25.DA25 + " ");

            if (TMP25.LF25 != null) Q25.add(TMP25.LF25);
            if (TMP25.RT25 != null) Q25.add(TMP25.RT25);
        }
    }

    // Build Tree from Array
    public static Node25 BLD25(int ARR25[], int IDX25) {

        if (IDX25 >= ARR25.length)
            return null;

        Node25 RT25 = new Node25(ARR25[IDX25]);

        RT25.LF25 = BLD25(ARR25, 2 * IDX25 + 1);
        RT25.RT25 = BLD25(ARR25, 2 * IDX25 + 2);

        return RT25;
    }
    // Check Identical Trees
    boolean ISIDENT25(Node25 A25, Node25 B25) {
        if (A25 == null && B25 == null)
            return true;
        if (A25 == null || B25 == null)
            return false;

        return (A25.DA25 == B25.DA25)&& ISIDENT25(A25.LF25, B25.LF25)&& ISIDENT25(A25.RT25, B25.RT25);
    }

    public static void main(String[] args) {
        CS241020_7_1 TR25 = new CS241020_7_1();
        int ARR125[] = {1, 2, 2, 3, 4, 4, 3};
        int ARR225[] = {1, 2, 2, 3, 4, 4, 3};
        Node25 T125 = BLD25(ARR125, 0);
        Node25 T225 = BLD25(ARR225, 0);
        if (TR25.ISIDENT25(T125, T225))
            System.out.println("Trees are Identical");
        else
            System.out.println("Trees are Not Identical");
    }
   
}
