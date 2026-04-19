/*
Anshu Lakshkar
0801CS241020
Assignment number - 7 (Tree - I)
Problem number - 2
Date of submission - 22nd Feb 2026
*/

import java.util.*;

public class CS241020_7_2{
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

    // Delete Node
    public void DEL25(int KEY25) {

        if (RTN25 == null) return;

        Queue<Node25> Q25 = new LinkedList<>();
        Q25.add(RTN25);

        Node25 KEYN25 = null;
        Node25 TMP25 = null;

        while (!Q25.isEmpty()) {

            TMP25 = Q25.poll();

            if (TMP25.DA25 == KEY25)
                KEYN25 = TMP25;

            if (TMP25.LF25 != null) Q25.add(TMP25.LF25);
            if (TMP25.RT25 != null) Q25.add(TMP25.RT25);
        }

        if (KEYN25 != null) {
            KEYN25.DA25 = TMP25.DA25;
            DELDEE25(TMP25);
        }
    }

    // Delete Deepest Node
    private void DELDEE25(Node25 DELN25) {

        Queue<Node25> Q25 = new LinkedList<>();
        Q25.add(RTN25);

        while (!Q25.isEmpty()) {

            Node25 TMP25 = Q25.poll();

            if (TMP25.LF25 == DELN25) {
                TMP25.LF25 = null;
                return;
            }
            if (TMP25.RT25 == DELN25) {
                TMP25.RT25 = null;
                return;
            }

            if (TMP25.LF25 != null) Q25.add(TMP25.LF25);
            if (TMP25.RT25 != null) Q25.add(TMP25.RT25);
        }
    }

    // Mirror Tree
    Node25 MIR25(Node25 RT25) {

        if (RT25 == null) return null;

        Node25 TMP25 = RT25.LF25;
        RT25.LF25 = MIR25(RT25.RT25);
        RT25.RT25 = MIR25(TMP25);

        return RT25;
    }

    public static void main(String[] args) {
        CS241020_7_2 TR25 = new CS241020_7_2();
        int ARR25[] = {11, 12, 3, 14, 15};

        TR25.RTN25 = BLD25(ARR25, 0);
        System.out.println("Original Tree (Level Order):");
        TR25.LEV25();

        TR25.RTN25 = TR25.MIR25(TR25.RTN25);
        System.out.println("\nMirror Tree (Level Order):");
        TR25.LEV25();
    }
}
