/*
 * Clavius, the person who suggested grouping of data using brackets.
He has suggested that the group of brackets should be Well-Formed.

A string is said to be Well-Formed, if:
    - Any open bracket must have corresponding two consecutive close brackets.
    - Open bracket must appear before the corresponding close brackets.

You will be given a string B, consists of square brackets only '[' , ']'.
In one operation, you can insert one square bracket at any position of B.
i.e., Given B = [[]]], in one operation you can add a open square bracket,
now B can be Well-Formed string, if you add at index 2,3,4 or 5 => [[]]]]

Your task is to return the least number of operations required,
to make B as a Well-Formed string.

Input Format:
-------------
A string, B contains only characters '[', ']'

Output Format:
--------------
Print an integer value.


Sample Input-1:
---------------
[]]][

Sample Output-1:
----------------
4


Sample Input-2:
---------------
[]][[]]

Sample Output-2:
----------------
2

*/

import java.util.*;

/**
 * d44p4
 */
public class d44p4 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        sc.close();
        int cnt = 0;
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (ch == '[') {
                cnt += 1;
            } else {
                if (i + 1 == s.length() || s.charAt(i + 1) == '[') {
                    if (cnt > 0) {
                        cnt--;
                        ans++;
                    } else {
                        ans += 2;
                    }
                } else {
                    i++;
                    if (cnt > 0) {
                        cnt--;
                    } else {
                        ans += 1;
                    }
                }
            }
        }
        System.out.println(ans + cnt * 2);
    }
}