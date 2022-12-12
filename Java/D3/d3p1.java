/*
 * There are N computers in a network, all the computers are connected as tree 
structure. And one new connection is added in the Network. The computers in 
the network are identified with their IDs, the IDs are numbered between 1 to N.

The connections in the network is given as coonection[i] = [comp-A, comp-B], 
there is a connection between comp-A and comp-B.

Your task is to remove a connection in the network and print it, so that 
all the computers are connected as tree structure. If there are multiple 
options to remove, remove the connection that occurs last in the input.


Input Format:
-------------
Line-1: Two space separated integers N, number of computers.
Next N lines: Two space separated integers, comp-A & comp-B.

Output Format:
--------------
Print the connection which is removed.


Sample Input-1:
---------------
6
1 2
3 4
3 6
4 5
5 6
2 3

Sample Output-1:
---------------
5 6


Sample Input-2:
---------------
4
1 2
2 3
3 4
2 4

0 1
1 2
2 3
1 3

Sample Output-2:
---------------
2 4

 */

import java.util.*;

/**
 * d3p1
 */
public class d3p1 {
    
    static int x = 0, y = 0;

    static void union(int parent[], int u, int v) {
        int x = find(parent, u);
        int y = find(parent, v);
        if (x != y) {
            parent[x] = y;
        } else {
            d3p1.x = u+1;
            d3p1.y = v+1;
        }
    }

    static int find(int parent[], int u) {
        if (parent[u] == u) {
            return u;
        }
        return parent[u] = find(parent, parent[u]);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int parent[] = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (int i = 0; i < n; i++) {
            int u = sc.nextInt()-1;
            int v = sc.nextInt()-1;
            if (v == n) {
                x = u;
                y = v;
            }
            union(parent, u, v);
        }
        System.out.println(x + " " + y);
        sc.close();
    }
}