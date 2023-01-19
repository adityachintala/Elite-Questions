/*
 * Subodh is interested in playing with Strings,
For a given String 'S', Subodh applies some rules to find the value of 'S'.
The rules are as follows:
	- If it is a balanced [] has value 1
	- XY has value X + Y , where X and Y are balanced [] strings.
	- [Z] has score 2 * Z , where Z is a balanced parentheses string.
	
Find out the value of given String and print it.

Note: All the given strings are balanced

Input Format:
----------------
A String contains only '[', ']'


Output Format:
------------------
Print an integer as result.


Sample Input-1:
-------------------
[]

Sample Output-1:
---------------------
1

Sample Input-2:
-------------------
[[]]

Sample Output-2:
---------------------
2

Sample Input-3:
-------------------
[[][[[]]]]

Sample Output-3:
---------------------
6
*/

import java.util.*;

/**
 * d33p2
 */
public class d33p2 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int res = 0;
        sc.close();
        Stack<Integer> st = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '[') {
                st.push(res);
                res = 0;
            } else {
                res = st.pop() + Math.max(2 * res, 1);
            }
        }
        System.out.println(res);
    }
}