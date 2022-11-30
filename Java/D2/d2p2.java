/**
 * There are N cities, the cities are connected through one way routes and 
there is no cycle between the routes. Each city is numbered from 0 to N-1.

The map of the cities is given as follows: 
map[i] is a list of all the cities you can travel from city[i].
(i.e., there is a one-way route from city[i] to node[map[i][j]]).

Your task is to findout all the possible travel routes between city-[0] to 
city-[N-1]. 
 
Input Format:
-------------
Line-1: An integer N , number of cities.
Line-2: N space separated integers, number of outgoing routes from city[i], 0<=i<N.
Next N lines: "out[i]" space separated integers, routes from city[i] where 0<=i<N
 
Output Format:
--------------
Print the list of travel routes.

Hint: find the routes in the input order.

 
Sample Input-1:
---------------
4
2 1 1 0
1 2
3
3

Sample Output-1:
----------------
[[0, 1, 3], [0, 2, 3]]
 

Sample Input-2:
---------------
5
3 3 1 1 0
4 3 1
3 2 4
3
4
 
Sample Output-2:
----------------
[[0, 4], [0, 3, 4], [0, 1, 3, 4], [0, 1, 2, 3, 4], [0, 1, 4]]

*/
import java.util.*;

public class d2p2 {

    static void dfs(int[][] map, int src, int dest, List<Integer> path, List<List<Integer>> res) {
        if (src == dest) {
            res.add(new ArrayList<>(path));
            return;
        }
        for (int i = 0; i < map[src].length; i++) {
            path.add(map[src][i]);
            dfs(map, map[src][i], dest, path, res);
            path.remove(path.size() - 1);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] out = new int[n];
        for (int i = 0; i < n; i++) {
            out[i] = sc.nextInt();
        }
        int[][] map = new int[n][];
        for (int i = 0; i < n; i++) {
            map[i] = new int[out[i]];
            for (int j = 0; j < out[i]; j++) {
                map[i][j] = sc.nextInt();
            }
        }
        sc.close();
        // System.out.println(Arrays.toString(out));
        // for(int i = 0; i < n; i++) {
        //     System.out.println(Arrays.toString(map[i]));
        // }
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> path = new ArrayList<>();
        path.add(0);
        dfs(map, 0, n-1, path, res);
        System.out.println(res);
    }
}