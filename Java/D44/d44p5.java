/*
 * Pranav has a puzzle board filled with square boxes in the form of a grid.
Some cells in the grid may be empty. '0' - indicates empty, '1' - indicates a box. 

Pranav wants to find out the number of empty spaces which are completely 
surrounded by the square boxes (left, right, top, bottom) in the board.

You are given the board in the form of a grid M*N, filled wth 0's and 1's.
Your task is to help Pranav to find the number of empty groups surrounded by
the boxes in the puzzle board.

Input Format:
-------------
Line-1: Two integers M and N, the number of rows and columns in the board.
Next M lines: contains N space-separated either 0 or 1.

Output Format:
--------------
Print an integer, the number of empty spaces in the puzzle board.


Sample Input-1:
---------------
6 7
1 1 1 1 0 0 1
1 0 0 0 1 1 0
1 0 0 0 1 1 0
0 1 1 1 0 1 0
1 1 1 0 0 1 1
1 1 1 1 1 1 1

Sample Output-1:
----------------
2


Sample Input-2:
---------------
6 6
1 1 0 0 1 1
1 0 1 1 0 1
0 1 0 1 0 0
1 1 0 0 0 1
0 0 1 0 1 1
1 1 0 1 0 0

Sample Output-2:
----------------
1



*/

import java.util.*;

/**
 * d44p5
 */
public class d44p5 {

    static int[] di = { 0, 0, -1, 1 };
    static int[] dj = { 1, -1, 0, 0 };

    static void dfs(int x, int y, int n, int m, boolean[][] vis, int[][] a) {

        vis[x][y] = true;

        for (int i = 0; i < 4; i++) {
            int nr = x + di[i];
            int nc = y + dj[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && a[nr][nc] == 0) {
                dfs(nr, nc, n, m, vis, a);
            }
        }

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] a = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = sc.nextInt();
            }
        }
        sc.close();
        boolean[][] vis = new boolean[n][m];
        for (int j = 0; j < m; j++) {
            if (!vis[0][j] && a[0][j] == 0) {
                dfs(0, j, n, m, vis, a);
            }
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i][m - 1] && a[i][m - 1] == 0) {
                dfs(i, m - 1, n, m, vis, a);
            }
        }
        for (int j = 0; j < m; j++) {
            if (!vis[n - 1][j] && a[n - 1][j] == 0) {
                dfs(n - 1, j, n, m, vis, a);
            }
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i][0] && a[i][0] == 0) {
                dfs(i, 0, n, m, vis, a);
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && a[i][j] == 0) {
                    dfs(i, j, n, m, vis, a);
                    count++;
                }
            }
        }

        System.out.println(count);
    }
}