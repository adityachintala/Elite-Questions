/*
 * A string 'InputStr' is given to students of 9th class .They are asked to create 
a string 'str' of length n+1 and the conditions to be followed for string 
creation is as follows:
    - Index of str starts from zero and length will be n+1.
    - str consists of the digits '1' to '9', where each digit is used at most once.
    - If InputStr[i] == 'A', then str[i] < str[i + 1].
    - If InputStr[i] == 'D', then str[i] > str[i + 1].


Your task is to return the lexicographically smallest possible string str 
that meets the conditions.


Input Format:
-------------
Line1: String which consists of A's and D's

Output Format:
-------------- 
String of decimal numbers


Sample Input-1:
---------------
AAADADDD
Sample Output-1:
----------------
123549876

Explanation:
------------
At indices 0, 1, 2, and 4 we must have that num[i] < num[i+1].
At indices 3, 5, 6, and 7 we must have that num[i] > num[i+1].
Some possible values of num are "245639871", "135749862", and "123849765".
It can be proven that "123549876" is the smallest possible num that meets the conditions.
Note that "123414321" is not possible because the digit '1' is used more than once.


Sample Input-2:
---------------
DDD

Sample Output-2:
----------------
4321

Explanation:
------------
Some possible values of num are "9876", "7321", and "8742".
It can be proven that "4321" is the smallest possible num that meets the conditions.

*/

import java.util.*;

/**
 * d54p2
 */
public class d54p2 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input = sc.next();
        sc.close();
        int n = input.length();
        String ans = "";
        int j = 0;
        for (int i = 0; i <= n; i++) {
            ans += (char) ('1' + i);
            if (i == n || input.charAt(i) == 'A') {
                ans = ans.substring(0, j) + new StringBuilder(ans.substring(j)).reverse().toString();
                j = i + 1;
            }
        }
        System.out.println(ans);
    }
}