/*
There is a competetion conducted at a school where students are given string 
of English letters. String consits of lower case letters.

A student can alter the string and create a new string so that, when reversed, 
the altered and and its reveresed strings should be equal, designating a winner.

There is a constraint that each string can be altered atmost twice. 
In one operation, you can change any character of string to any other character.

If The student is the winner, return the palindrome string with minimum operations,
and always alter the letters in the second half of the string only. 
Otherwise, return the original string itself.


Input Format:
-------------
A string, S

Output Format:
--------------
Print the string result.


Sample Input-1:
---------------
xyzwyx

Sample Output-1:
----------------
xyzzyx

Explanation:
------------
One way to alter the string such that it matches the given criteria,
using 1 operation is:

- Change s[3] to 'z'. Now, s = "xyzzyx".
One operation could be performed to make our required string.


Sample Input-2:
---------------
pp

Sample Output-2:
----------------
pp

Explanation:
------------
String is already a palindrome.


Sample Input-3:
---------------
mnopqr

Sample Output-3:
----------------
mnopqr

Explanation:
------------
It is not possible to make string that matches the given criteria using 
one or two operations. So, return the string itself.

*/

import java.util.*;

public class d7p3_II {

    static String func(String s) {
        int n = s.length();
        int count = 0;
        char ch[] = s.toCharArray();
        for (int i = 0; i < n / 2; i++) {
            if (s.charAt(i) != s.charAt(n - i - 1)) {
                count++;
                ch[n - i - 1] = ch[i];
            }
        }

        if (count == 0) {
            return s;
        } else if (count == 1 || count == 2) {
            return new String(ch);
        } else {
            return s;
        }
        
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        sc.close();
        System.out.println(func(s));
    }

}
