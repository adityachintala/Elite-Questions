/*
 Prabhath is working on words.  He used to take out every letter that was repeated 
in the word. 
A word W is given to Prabhath. His objective is to eliminate every duplicate 
letter from W such that the resultant word R contains every unique letter from W
and did not contain any duplicate letters. 
And R should be at the top of the dictionary order.

NOTE:
-----
He is not allowed to shuffle the relative order of the letters of the word W to
form the word R.

Input Format:
-------------
A String, the word W.

Output Format:
--------------
Print a String, resultant word R.


Sample Input-1:
---------------
cbadccb

Sample Output-1:
----------------
adcb


Sample Input-2:
---------------
silicosis

Sample Output-2:
----------------
ilcos

 */
import java.util.*;

public class d3p3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        Set<Character> set = new LinkedHashSet<>();
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (set.contains(ch)) {
                continue;
            }

            if (stack.isEmpty()) {
                stack.push(ch);
                set.add(ch);
                continue;
            }

            while (!stack.isEmpty() && stack.peek() >= ch) {
                if (s.indexOf(stack.peek(), i) == -1) {
                    break;
                }
                set.remove(stack.pop());
            }

            stack.push(ch);
            set.add(ch);
        }
        Enumeration enu = stack.elements();
        String res = "";
        while (enu.hasMoreElements()) {
            res += "" + enu.nextElement();
        }
        System.out.println(res);
        sc.close();
    }
}
