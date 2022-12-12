/*
 * Budget Padmanabham planned to visit the tourist places. There are N tourist 
places in the city. The tourist places are numbered from 1 to N.

You are given the routes[] to travel between the tourist places in the city.
where routes[i]=[place-1, place-2, price], A route is a bi-directional route.
You can travel from place-1 to place-2 or place-2 to place-1 with the given price.
 
Your task is to help Budget Padmanabham to find the cheapest route plan, to 
visit all the tourist places in the city. If you are not able to find such plan, 
print -1.
 
Input Format:
-------------
Line-1: Two space separated integers N and R,number of places and routes.
Next R lines: Three space separated integers, start, end and price.
  
Output Format:
--------------
Print an integer, minimum cost to visit all the tourist places.
 
 
Sample Input-1:
---------------
4 5
1 2 3
1 3 5
2 3 4
3 4 1
2 4 5
 
Sample Output-1:
----------------
8
 
Explanation:
------------
The cheapest route plan is as follows:
1-2, 2-3, 3-4 and cost is 3 + 4 + 1 = 8
 
 
Sample Input-2:
---------------
4 3
1 2 3
1 3 5
2 3 4
 
Sample Output-2:
----------------
-1

*/
import java.util.*;

/**
 * d8p2
 */
public class d8p2 {

    static void union(int parent[], int x, int y) {
        int xset = find(parent, x);
        int yset = find(parent, y);
        if (xset != yset) {
            if(xset < yset) {
                parent[yset] = xset;
            } else {
                parent[xset] = yset;
            }
        }
    }

    static int find(int parent[], int x) {
        if (parent[x] == x) {
            return x;
        }
        return find(parent, parent[x]);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int r = sc.nextInt();
        int[][] routes = new int[r][3];
        for (int i = 0; i < r; i++) {
            routes[i][0] = sc.nextInt();
            routes[i][1] = sc.nextInt();
            routes[i][2] = sc.nextInt();
        }
        sc.close();
        // using union and find
        Arrays.sort(routes, Comparator.comparingInt(a -> a[2]));
        int[] parent = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        int cost = 0;
        for (int i = 0; i < routes.length; i++) {
            if (find(parent, routes[i][0] - 1) != find(parent, routes[i][1] - 1)) {
                cost += routes[i][2];
                union(parent, routes[i][0] - 1, routes[i][1] - 1);
            }
            Set<Integer> set = new HashSet<>();
            for (int j = 0; j < n; j++) {
                set.add(find(parent, j));
            }
            if (set.size() == 1) {
                System.out.println(cost);
                return;
            }
        }
        System.out.println(-1);
    }
}