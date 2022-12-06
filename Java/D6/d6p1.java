/*
Ibrahim is an interior designer wants to color wall of size M*N. 
He plans to color the wall and put lights of two different colors

The designer can lit the wall using M*N lights.The lights are Blue or pink
in color.Blue colored lights represented with digit-1 and pink colored lights 
represented with digit-0.

The Blue colored lights forms different shapes, that are connected 4 directonally.
The directons are upwards, downwards, left, and right. Ibrahim got an idea to 
count the unique shapes formed by blue colored lights.

You will be given the decorated wall as a matrix wall[][].
Your task is to help Ibrahim to count the unique shapes by the lights.

Input Format:
-------------
Line-1: Two space separated integers M and N, size of the wall.
Next M lines: N space separated integers, either 0 or 1.

Output Format:
--------------
Print an integer, Number of distinct shapes formed by Blue Lights.


Sample Input-1:
---------------
4 5
1 1 0 1 1
1 1 0 0 1
0 0 0 0 0
1 1 0 0 0

Sample Output-1:
----------------
3


Sample Input-2:
---------------
5 5
1 1 0 1 1
1 0 0 0 1
0 0 0 0 0
1 0 0 0 1
1 1 0 1 1

Sample Output-2:
----------------
4

Note: 
-------
The shapes, 
1 1  		  1 1
1      and      1
*/

// DFS method

import java.util.*;

public class d6p1 {

    static Set<String> set = new HashSet<>();

    static void dfs(int wall[][], int i, int j, StringBuilder sb, String dir) {
        if (i < 0 || i >= wall.length || j < 0 || j >= wall[0].length || wall[i][j] == 0) {
            return;
        }
        sb.append(dir);
        wall[i][j] = 0;
        dfs(wall, i + 1, j, sb, "D");
        dfs(wall, i - 1, j, sb, "U");
        dfs(wall, i, j + 1, sb, "R");
        dfs(wall, i, j - 1, sb, "L");
        sb.append("B");
    }

    static void countUniqueIslands(int wall[][]) {
        for (int i = 0; i < wall.length; i++) {
            for (int j = 0; j < wall[0].length; j++) {
                if (wall[i][j] == 1) {
                    StringBuilder sb = new StringBuilder();
                    dfs(wall, i, j, sb, "o");
                    set.add(sb.toString());
                }
            }
        }
        System.out.println(set.size()); 
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int n = sc.nextInt();
        int[][] wall = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                wall[i][j] = sc.nextInt();
            }
        }
        sc.close();
        countUniqueIslands(wall);

    }

}