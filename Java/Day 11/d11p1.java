/*
There is a set of 'N' bags contains apples.
Each bag carries few number of apples.
You need to pick 'K' bags everytime from left to right.
and find the bag which contains max number of apples 'M'.
You need to return the value fo M each time.

Bags array indicates the apples count in each bag.

NOTE:
-----
Can you solve it in linear time?

Input Format:
-------------
Line-1: Two space separated integers, N and K
Line-2: N space separated integers, 

Output Format:
--------------
Print the (N-K+1) integer output.


Sample Input-1:
---------------
8 3
1 2 3 5 4 6 8 7

Sample Output-1:
----------------
3 5 5 6 8 8

Explanation:
------------

K Bags		Max
-----------    -----
1 2 3			3
2 3 5			5
3 5 4			5
5 4 6			6
4 6 8			8
6 8 7			8

*/

/**
 * d11p1
 */

import java.util.*;

// Time Complexity: O(n)
/**
 * d11p1
 */
public class d11p1 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] bags = new int[n];
        for (int i = 0; i < n; i++) {
            bags[i] = sc.nextInt();
        }
        sc.close();
        List<Integer> window = new ArrayList<>();
        int max = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            if (i < k) {
                max = Math.max(max, bags[i]);
                window.add(bags[i]);
            } else {
                System.out.print(max + " ");
                window.remove(0);
                window.add(bags[i]);
                max = Math.max(max, bags[i]);
                if (window.contains(max) == false) {
                    max = Collections.max(window);
                }
            }
        }
        System.out.println(max);
    }
}