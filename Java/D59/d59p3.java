/*
 * Students are given  magical string consists of only'1' and '2'.
and has to follow  the following rules:


The string s is magical because concatenating the number of contiguous occurrences of characters '1' and '2'
generates the string s itself.
The first few elements of s is s = "1221121221221121122……". If we group the consecutive 1's and 2's in s, it
will be "1 22 11 2 1 22 1 22 11 2 11 22 ......" and the occurrences of 1's or 2's in each group are
"1 2 2 1 1 2 1 2 2 1 2 2 ......". You can see that the occurrence sequence is s itself.

Given an integer n, return the number of 1's in the first n number in the magical string s.

Input Format
------------
Line1:An integer 

Output Format
-------------
An integer represents number of 1's in the first n number

Example 1:

Input1:  6
Output1: 3
Explanation: The first 6 elements of magical string s is "122112" and it contains three 1's, so return 3.
Example 2:

Input2: 1
Output2:1
*/
/**
 * d59p3
 */

import java.util.*;

class d59p3 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.close();
        String s = " 122";
        for (int i = 3; i <= n; ++i) {
            if ((i & 1) != 0) {
                s += "1".repeat(s.charAt(i) - '0');
            } else {
                s += "2".repeat(s.charAt(i) - '0');
            }
        }
        System.out.println(s.substring(0, n + 1).chars().filter(ch -> ch == '1').count());
    }
}