/*
 * You are given a set of N integers, and a value to find F. Initially a variable, 
'total' is set to 0. You can perform either addition(+) or subtraction(-)
of every integer from the set to the 'total'. The resultant total should be
equal to the value F.

Your task is to find out the number of ways, you can make the 'total' equal to
the value F.

Input Format:
-------------
Line-1: Two integers N and F.
Line-2: N space separated integers 

Output Format:
--------------
Print an integer, number of ways.


Sample Input:
---------------
5 3
1 1 1 1 1

Sample Output:
----------------
5

Explanation:
------------
total = -1+1+1+1+1 = 3 -> total=value-F
total = +1-1+1+1+1 = 3 -> total=value-F
total = +1+1-1+1+1 = 3 -> total=value-F
total = +1+1+1-1+1 = 3 -> total=value-F
total = +1+1+1+1-1 = 3 -> total=value-F

NOTE: + means addition, - means subtraction

*/

import java.util.*;

/**
 * d64p3
 */
public class d64p3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int f = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }
        int[][] dp = new int[n + 1][2001];
        dp[0][1000] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= 2000; j++) {
                if (j - nums[i - 1] >= 0) {
                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
                }
                if (j + nums[i - 1] <= 2000) {
                    dp[i][j] += dp[i - 1][j + nums[i - 1]];
                }
            }
        }
        System.out.println(dp[n][f + 1000]);
        sc.close();
    }
}

// Leetcode 494. Target Sum