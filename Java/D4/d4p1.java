/*
 * There are N people in a private party. Initially all are strangers to each other,
and the people are identified by unique ID from 0 to N-1.

In the party, whenever two persons (person-A and person-B) become friends, they 
took a photo. Each of the photo has some information, photos[i]=[T-i, P-j,P-k],
here T-i indicates time of the photo taken, P-j person with ID 'j', and 
P-k indicates person with ID 'k'.

Friendship is symmetric[i.e., If P-j is friend of P-k, then P-k is a friend of P-j].
Additionally, if person-A is "a friend of person-B OR a friend of someone who is 
friend of person-B", then person-A is friend of person-B.

You are given L photos information, Your task is to find the earliest time 
for which every person became friend with every other person in the party.
If there is no such earliest time, return -1.


Input Format:
-------------
Line-1: Two space separated integers, N and L.
Next L lines: Three space separated integers, log[i], 0<=i<L.

Output Format:
--------------
Print an integer result.


Sample Input-1:
---------------
6 8
5 0 1
7 3 4
12 2 3
21 1 5
34 2 4
37 0 3
42 1 2
93 4 5

Sample Output-1:
----------------
37


Sample Input-2:
---------------
7 6
2 0 3
5 1 5
8 2 5
7 3 6
9 4 6
6 4 5

Sample Output-2:
----------------
9

 */

import java.util.*;

class d4p1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int l = sc.nextInt();
        int[][] logs = new int[l][3];
        for (int i = 0; i < l; i++) {
            logs[i][0] = sc.nextInt();
            logs[i][1] = sc.nextInt();
            logs[i][2] = sc.nextInt();
        }
        sc.close();
        System.out.println(earliestTime(n, logs));
    }
    /* */
    static void union(int parent[], int x, int y) {
        int xset = find(parent, x);
        int yset = find(parent, y);
        parent[xset] = yset;
    }

    static int find(int parent[], int i) {
        if (parent[i] == i) {
            return i;
        }
        return find(parent, parent[i]);
    }

    static int earliestTime(int n, int logs[][]) {
        // print log
        for (int i[] : logs) {
            System.out.println(Arrays.toString(i));
        }
        Arrays.sort(logs, Comparator.comparingInt(a -> a[0]));
        for (int i[] : logs) {
            System.out.println(Arrays.toString(i));
        }
        int[] parent = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        int count = n;
        for (int i = 0; i < logs.length; i++) {
            if (find(parent, logs[i][1]) != find(parent, logs[i][2])) {
                union(parent, logs[i][1], logs[i][2]);
                count--;
            }
            if (count == 1) {
                return logs[i][0];
            }
        }
        return -1;
    }
    
}