/*
 * Given a matrix of 0's and 1's of dimension rows X cols.

We could traverse from one element(row, col) to any other element(row + 1, col) or (row, col + 1).

Print 'true' if there is any path from first element(0,0) of the matrix to the last element(rows - 1, cols - 1) 
of the matrix that visits the same number of 1's and 0's.
Print 'false' otherwise.


Input Format
-------------
Line-1: Read two integers rows and cols(space separated).
Line-2: Read the matrix of dimension rows X cols.

Output Format
--------------
If the required path exist print 'true' otherwise 'false'.


Sample input-1
3 4
0 1 1 0
0 0 0 0
0 0 1 0
Sample output-1
true

Explanation: In the given matrix there is a path that is having three 0's and three 1's.

Sample input-2
4 3
0 0 1
1 0 0
0 0 0
0 0 1
Sample output-2
false

Explanation: There is NO path that is having same number of 0's and 1's.

*/

import java.util.*;

/**
 * d39p3
 */
public class d39p3 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int rows = sc.nextInt();
        int cols = sc.nextInt();
        int[][] matrix = new int[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = sc.nextInt();
            }
        }
        // int matrix[][] = new int[][] {
        //     {0, 0, 1},
        //     {1, 0, 0},
        //     {0, 0, 0},
        //     { 0, 0, 1 }
        // };
        sc.close();
        // using dfs
        System.out.println(isPath(matrix, matrix.length, matrix[0].length, 0));
    }

    public static boolean isPath(int[][] matrix, int rows, int cols, int count) {
        boolean[][] visited = new boolean[rows][cols];
        return dfs(matrix, rows, cols, 0, 0, visited, count);
    }

    public static boolean dfs(int[][] matrix, int rows, int cols, int i, int j, boolean[][] visited, int count) {
        if (i < 0 || i >= rows || j < 0 || j >= cols || visited[i][j]) {
            return false;
        }
        if (i == rows - 1 && j == cols - 1) {
            if(matrix[i][j] == 0) count--;
            else count++;
            return count == 0;
        }
        visited[i][j] = true;
        if (matrix[i][j] == 0) {
            count--;
        } else {
            count++;
        }
        boolean ans = dfs(matrix, rows, cols, i + 1, j, visited, count)
                || dfs(matrix, rows, cols, i, j + 1, visited, count);
        visited[i][j] = false;
        return ans;
    }
}