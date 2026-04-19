/*
Anshu Lakshkar
0801CS241020
Assignment number - 7 (Tree - I)
Problem number - 7
Date of submission - 22nd Feb 2026
*/

public class CS241020_7_7 {
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

    Node25 LCA25(Node25 RT25, int N125, int N225) {
        if (RT25 == null) return null;
        if (RT25.DA25 == N125 || RT25.DA25 == N225)
            return RT25;
        Node25 LFRES25 = LCA25(RT25.LF25, N125, N225);
        Node25 RTRES25 = LCA25(RT25.RT25, N125, N225);
        if (LFRES25 != null && RTRES25 != null)
            return RT25;

        return (LFRES25 != null) ? LFRES25 : RTRES25;
    }

    public static void main(String[] args) {
        CS241020_7_7 TR25 = new CS241020_7_7();
        int ARR25[] = {3,5,1,6,2,0,8};
        TR25.RTN25 = BLD25(ARR25, 0);
        Node25 RES25 = TR25.LCA25(TR25.RTN25, 0, 6);
        if (RES25 != null)
            System.out.println("LCA = " + RES25.DA25);
        else
            System.out.println("Nodes not found");
    }
}
