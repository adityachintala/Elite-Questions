/*
 * Clavius, the person who suggested grouping of data using brackets.
 * He has suggested that the group of brackets should be Well-Formed.
 * 
 * A string is said to be Well-Formed, if:
 * - The string is empty.
 * - The string can be written as MN, (M is appended to N),
 * where M and N are Well-Formed Strings, or
 * - The string can be written as {M}, where M is Well-Formed string.
 * 
 * You will be given an integer N. Your task is to return the list of all
 * Well-Formed strings of length 2*N.
 * 
 * Input Format:
 * -------------
 * An integer N.
 * 
 * Output Format:
 * --------------
 * Print the list of well-formed strings.
 * 
 * 
 * Sample Input-1:
 * ---------------
 * 3
 * 
 * Sample Output-1:
 * ----------------
 * [{{{}}},{{}{}},{{}}{},{}{{}},{}{}{}]
 * 
 * 
 * Sample Input-2:
 * ---------------
 * 1
 * 
 * Sample Output-2:
 * ----------------
 * [{}]
 * 
*/

import java.util.*;

/**
 * d63p2
 */
public class d63p2 {

    public static List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<>();
        backtrack(res, "", 0, 0, n);
        return res;
    }

    public static void backtrack(List<String> res, String curr, int open, int close, int max) {
        if (curr.length() == max * 2) {
            res.add(curr);
            return;
        }

        if (open < max) {
            backtrack(res, curr + "{", open + 1, close, max);
        }
        if (close < open) {
            backtrack(res, curr + "}", open, close + 1, max);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<String> res = generateParenthesis(n);
        System.out.println(res);
    }
    
}