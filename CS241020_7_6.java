/*
Anshu Lakshkar
0801CS241020
Assignment number - 7 (Tree - I)
Problem number - 6
Date of submission - 22nd Feb 2026
*/

public class  CS241020_7_6{
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

    public static void main(String[] args) {
        CS241020_7_6 TR25 = new CS241020_7_6();
        int ARR25[] = {1, 2, 2, 3, 4, 4, 3};
        TR25.RTN25 = BLD25(ARR25, 0);

        System.out.println("Height = " + TR25.HGHT25(TR25.RTN25));
    }
}