/*
Anshu Lakshkar
0801CS241020
Assignment number - 7 (Tree - I)
Problem number - 10
Date of submission - 22nd Feb 2026
*/
public class CS241020_7_10 {
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
    // Count Leaf Nodes
    int CNTLEAF25(Node25 RT25) {
        if (RT25 == null) return 0;
        if (RT25.LF25 == null && RT25.RT25 == null)
            return 1;

        return CNTLEAF25(RT25.LF25)+ CNTLEAF25(RT25.RT25);
    }

    public static void main(String[] args) {
        CS241020_7_10 TR25 = new CS241020_7_10();
        int ARR25[] = {3, 5, 1, 6, 2, 0, 8};
        TR25.RTN25 = BLD25(ARR25, 0);
        System.out.println("Number of Leaf Nodes = "+ TR25.CNTLEAF25(TR25.RTN25));
    }
}
