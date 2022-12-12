/*
There is a competetion conducted at a school where students are given string 
of English letters. String consits of lower case letters.

A student can alter the string and create a new string so that, when reversed, 
the altered and and its reveresed strings should be equal, designating a winner.

There is a constraint that each string can be altered atmost twice. 
In one operation, you can change any character of string to any other character.

The student has to return "true" if he is winner, otherwise return "false"

Input Format:
-------------
A string, S

Output Format:
--------------
Print a boolean result.


Sample Input-1:
---------------
xyzwyx

Sample Output-1:
----------------
true

Explanation:
------------
One way to alter the string such that it matches the given criteria,
using 1 operation is:

- Change s[2] to 'w'. Now, s = "xywwyx".
One operation could be performed to make our required string so return true.


Sample Input-2:
---------------
pp

Sample Output-2:
----------------
true

Explanation:
------------
One way to alter the string such that it matches the given criteria,
using 2 operations is:
- Change s[0] to 'q'. Now, s = "qp".
- Change s[1] to 'q'. Now, s = "qq".
Two operations could be performed to make our required string so return true.


Sample Input-3:
---------------
mnopqr

Sample Output-3:
----------------
false

Explanation:
------------
It is not possible to make string that matches the given criteria using 
one or two operations. So, return false.

*/

import java.util.*;

public class d7p3 {

    static boolean func(String s) {
        int n = s.length();
        int count = 0;
        for (int i = 0; i < n / 2; i++) {
            if (s.charAt(i) != s.charAt(n - i - 1)) {
                count++;
            }
        }
        
        if(count == 0 || count == 1 || count == 2) {
            return true;
        }
        return false;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        sc.close();
        System.out.println(func(s));
    }

}
