/*
 * Given an array of integer elements, ele[], YOur task is to find and print 
the number of the subarrays, which gives you an even value after multiplication
of the elements in it.

Input Format:
-------------
Line-1: An integer N, number of elements.
Line-2: Space separated elements.

Output Format:
--------------
Print number of possible subarrays.


Sample Input-1:
---------------
4
5 8 9 17

Sample Output-1:
----------------
6

Explanation:
------------
5 x 8 = 40
5 x 8 x 9 = 360
5 x 8 x 9 x 17 = 6120
8 = 8
8 x 9 = 72
8 x 9 x 17 = 1224
Hence we got 6 even subarray multiplications.



Sample Input-2:
---------------
3
5 7 11

Sample Output-2:
----------------
0

Explanation:
------------
No subarrays which will give you even value after multiplication.

*/

import java.util.*;

/**
 * d41p3
 */
public class d41p3 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int arr[] = new int[n];
        boolean flag = true;
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
            flag = flag && arr[i] % 2 == 0;
        }
        sc.close();
        if (flag) {
            System.out.println(0);
            return;
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            int mul = 1;
            for (int j = i; j < n; j++) {
                mul *= arr[j];
                if (mul % 2 == 0) {
                    count++;
                }
            }
        }
        System.out.println(count);
    }
}