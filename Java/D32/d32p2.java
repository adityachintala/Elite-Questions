/*
There are n cartons of binary string of length n, where carton[i] is '0' if the ith
carton is empty and '1' if it contains one product.

In one operation, you can move one product from a carton to an adjacent carton.
cartoon i is adjacent to carton j if abs(i - j) == 1. Note that after doing so, there
may be more than one product in some cartons.

Return an array answer of size n, where answer[i] is the minimum number of operations
needed to move all the products to the ith carton

Each answer[i] is calculated considering the initial state of the cartons.


Input Format
------------
A string of zeroes and ones

Output Format
-------------
An integer array which is minimum no of operations

Example 1:

Input: cartons = "110"
Output: 1 1 3
Explanation: The answer for each cartoon is as follows:
1) First carton: you will have to move one product from the second carton to the first
carton in one operation.
2) Second carton: you will have to move one product from the first carton to the second 
carton in one operation.
3) Third carton: you will have to move one product from the first carton to the third carton 
in two operations, and move one product from the second product to the third carton in
one operation.

Example 2:

Input: cartoons = "001011"
Output: 11 8 5 4 3 4 
*/

import java.util.*;

/**
 * d32p2
 */
public class d32p2 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int arr[] = Arrays.stream(sc.nextLine().split("")).mapToInt(Integer::parseInt).toArray();
        // int arr[] = { 0, 0, 1, 0, 1, 1 };
        sc.close();
        int n = arr.length;
        int left[] = new int[n];
        int right[] = new int[n];

        int count = arr[0];

        for (int i = 1; i < n; i++) {
            left[i] += left[i - 1] + count;
            count += arr[i];
        }

        count = arr[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            right[i] += right[i + 1] + count;
            count += arr[i];
        }

        System.out.println("Left : " + Arrays.toString(left));
        System.out.println("Right : " + Arrays.toString(right));
        
        for (int i = 0; i < n; i++) {
            System.out.print(left[i] + right[i] + " ");
        }
    }
}