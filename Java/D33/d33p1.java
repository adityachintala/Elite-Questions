/*
Students are asked to stand in the ground in rows and cols with their roll numbers. 
Given this you have to sort each matrix diagonal in ascending order of their 
roll numbers

A Matrix diagonal is a diagonal line of cells starting from some cell in 
either the topmost row or leftmost column and going in the bottom-right 
direction until reaching the matrix's end.
 
For example, the matrix diagonal starting from mat[2][0], where mat is 
a 6 x 3 matrix, includes cells mat[2][0], mat[3][1], and mat[4][2].

Input Format
-------------
Line1: M, N integers representing row and col size
Line2: space separated integers of size M*N

Output Format
-------------
space separated integers  of size M*N


Sample Input1:
3 4 
3 3 1 1
2 2 1 2
1 1 1 2
Sample Output1: 
1 1 1 1
1 2 2 2
1 2 3 3
        

Sample Input2:   
5 6
11 25 66 1 69 7
23 55 17 45 15 52
75 31 36 44 58 8
22 27 33 25 68 4
84 28 14 11 5 50

Sample Output2:
5 17 4 1 52 7
11 11 25 45 8 69
14 23 25 44 58 15
22 27 31 36 50 66 
84 28 75 33 55 68

*/
import java.util.*;

public class d33p1 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int[][] nums = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                nums[i][j] = in.nextInt();
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int l = 0; l < n - i - 1; l++) {
                    for (int k = 0; k < m - j - 1; k++) {
                        if (nums[l][k] > nums[l + 1][k + 1]) {
                            int temp = nums[l][k];
                            nums[l][k] = nums[l + 1][k + 1];
                            nums[l + 1][k + 1] = temp;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                System.out.print(nums[i][j] + " ");
            }
            System.out.println();
        }
        // System.out.println(Arrays.toString(nums));
    }
}