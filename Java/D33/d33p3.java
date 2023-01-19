/*
There is a String given as input, it is a sequence of integer-values and 
arithmetic-operators. Your task is to print the resultant values after 
evaluating all the different possible ways to group integer-values 
and arithmetic-operators. 

Note: Print the evaluated values in sorted order.

Input Format:
-------------
Read a string

Output Format:
--------------
Print the evaluated values in sorted order

Sample input-1
------------
4-2-1

Sample output-1
---------------
1 3

Explanation
-----------
((4-2)-1)=1
(4-(2-1))=3


Sample input-2
------------
3*5-2*6

Sample output-2
---------------
-21 3 54 54 78

Explanation
------------
(3*(5-(2*6))) = -21
((3*5)-(2*6)) = 3
((3*(5-2))*6) = 54
(3*((5-2)*6)) = 54
(((3*5)-2)*6) = 78
*/

import java.util.*;

/**
 * d33p3
 */
public class d33p3 {

    static List<Integer> aakpaak(String s) {
        if (s == null || s.length() == 0)
            return new ArrayList<>();
        
        List<Integer> res = new ArrayList<>();

        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (ch == '-' || ch == '+' || ch == '*') {
                List<Integer> left = aakpaak(s.substring(0, i));
                List<Integer> right = aakpaak(s.substring(i + 1));
                for (int l : left) {
                    for (int r : right) {
                        if (ch == '-')
                            res.add(l - r);
                        else if (ch == '+')
                            res.add(l + r);
                        else if (ch == '*')
                            res.add(l * r);
                    }
                }
            }
        }
        
        if (res.size() == 0)
            res.add(Integer.parseInt(s));

        Collections.sort(res);

        return res;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        sc.close();
        System.out.println(aakpaak(s));
    }
}