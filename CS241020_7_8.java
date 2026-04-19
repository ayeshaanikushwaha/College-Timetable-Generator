/*
Anshu Lakshkar
0801CS241020
Assignment number - 7 (Tree - I)
Problem number - 8
Date of submission - 22nd Feb 2026
*/

import java.util.*;
public class CS241020_7_8 {
    static class Node25 {
        int DA25;
        Node25 LF25, RT25;

        Node25(int DA25) {
            this.DA25 = DA25;
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

    // Level Order Traversal
    void LEV25(Node25 RT25) {
        if (RT25 == null) return;
        Queue<Node25> Q25 = new LinkedList<>();
        Q25.add(RT25);
        while (!Q25.isEmpty()) {
            Node25 TMP25 = Q25.poll();
            System.out.print(TMP25.DA25 + " ");
            if (TMP25.LF25 != null) Q25.add(TMP25.LF25);
            if (TMP25.RT25 != null) Q25.add(TMP25.RT25);
        }
    }

    public static void main(String[] args) {
        CS241020_7_8 TR25 = new CS241020_7_8();
        int ARR25[] = {3, 5, 1, 6, 2, 0, 8};
        TR25.RTN25 = BLD25(ARR25, 0);
        System.out.println("Level Order Traversal:");
        TR25.LEV25(TR25.RTN25);
    }

}
