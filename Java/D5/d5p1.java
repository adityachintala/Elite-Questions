/*
 * Sudheer Ali participated in a treasure-hunt conatins N boxes in it.
Each box is numbered from 0,1,2,3,...,N-1. 
All the boxes are intially locked with the passcodes, except Box-0.
The passcode is written in a envolope and marked with its concern box number.

Each box in the treasure hunt contains a list of envelopes, which has 
passcodes to open the other boxes. He can open the boxes in any order, 
but he has to start from box-0 intially.

The rule to win the treasure-hunt is to open all the boxes.
Your task is to find out, whether Mansood Ali win the treasure hunt or not.
If he win, print "Win", Otherwise, print "Lost"


Input Format:
-------------
Line-1: An integer, number of boxes.
Next N lines: space separated integers, box numbers.

Output Format:
--------------
Print a string value, Win or Lost


Sample Input-1:
---------------
5
1
2
3
4
3

Sample Output-1:
----------------
Win


Sample Input-2:
---------------
4
1 3
3 0 1
2
0

Sample Output-2:
----------------
Lost

 */

import java.util.*;

/**
 * d5p1
 */
public class d5p1 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        int parent[] = new int[n];
        Arrays.fill(parent, -1);
        int array[][] = new int[n][];
        for (int i = 0; i < n; i++) {
            int arr[] = Arrays.stream(sc.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            array[i] = arr;
        }
        sc.close();
        // bfs
        boolean vis[] = new boolean[n];
        Queue<Integer> q = new LinkedList<>();
        q.add(0);
        vis[0] = true;
        while (!q.isEmpty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int curr = q.poll();
                for (int j = 0; j < array[curr].length; j++) {
                    if (!vis[array[curr][j]]) {
                        vis[array[curr][j]] = true;
                        parent[array[curr][j]] = curr;
                        q.add(array[curr][j]);
                    }
                }
            }
        }
        boolean flag = true;
        for (int i = 0; i < n; i++) {
            flag = flag && vis[i];
        }
        // print array
        if (flag) {
            System.out.println("Win");
        } else {
            System.out.println("Lost");
        }

    }
}