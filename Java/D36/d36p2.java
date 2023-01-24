/*
 * Given a matrix of dimension rows X cols with the elements 0's and 1's,

Your task is to convert all matrix elements to 0's by following 
the condition given below.

The condition is, in every operation, you could select any 
row or any column of the given matrix and toggle each element 
in that row or column.

Note: Toggle means changing all 0's to 1's and all 1's to 0's.

Print true if you could change all matirix elements to 0's 
by following given condition else print false.


Input Format
-------------
Line-1: Read two integers rows and cols(space separated).
Line-2: Read the matrix of dimension rows X cols.

Output Format
--------------
Print a boolean result.



Sample input-1:
---------------
5 5
0 0 1 0 0
0 0 1 0 0
1 1 0 1 1
0 0 1 0 0
0 0 1 0 0

Sample output-1:
----------------
true

Explanation:
------------
0 0 1 0 0          0 0 1 0 0           0 0 0 0 0
0 0 1 0 0   row-3  0 0 1 0 0   cols-3  0 0 0 0 0
1 1 0 1 1   --->   0 0 1 0 0   --->    0 0 0 0 0
0 0 1 0 0          0 0 1 0 0           0 0 0 0 0
0 0 1 0 0          0 0 1 0 0           0 0 0 0 0 


Sample input-2
--------------
2 2
1 1
0 1

Sample output-2
---------------
false

*/

import java.util.*;

/**
 * d36p2
 */
public class d36p2 {

    public static String getMatrix(int[][] matrix) {
        if (matrix.length == 0 || matrix[0].length == 0) {
            return "true";
        }

        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                if ((matrix[i][j] ^ matrix[0][j]) != (matrix[0][0] ^ matrix[i][0])) {
                    return "false";
                }
            }
        }
        return "true";
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int r = sc.nextInt();
        int c = sc.nextInt();
        int[][] matrix = new int[r][c];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                matrix[i][j] = sc.nextInt();
            }
        }
        sc.close();
        System.out.println(getMatrix(matrix));
    }
}