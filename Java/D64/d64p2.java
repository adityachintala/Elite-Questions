/*
 * Ms ALEENA is working on numbers; she is fascinated by number factors.
She is given a number N, she wants to find out all possible ways of 
obtaining N as multiple of its factors.
For example given N =12
can be written as multiple of 2,3 and 4.
and the ways to obtains 12 from ots factors are: 2*2*3, 2*6, 3*4

Your task is to help Ms ALEENA to find the all possible ways of obtaining N 
from its factors and return all the possible ways as shown in the samples.

Input Format:
-------------
An integer N, value of N.

Output Format:
--------------
Print the list of possiblilties.


Sample Input-1:
---------------
12

Sample Output-1:
----------------
[[2, 2, 3], [2, 6], [3, 4]]


Sample Input-2:
---------------
16

Sample Output-2:
----------------
[[2, 2, 2, 2], [2, 2, 4], [2, 8], [4, 4]]


Sample Input-3:
---------------
32

Sample Output-3:
----------------
[[2, 2, 2, 2, 2], [2, 2, 2, 4], [2, 2, 8], [2, 4, 4], [2, 16], [4, 8]]

*/

import java.util.*;

/**
 * d64p2
 */
public class d64p2 {

    public static void helper(int n, int start, List<Integer> temp, List<List<Integer>> res) {
        if (n == 1) {
            res.add(new ArrayList<>(temp));
            return;
        }
        for (int i = start; i <= n; i++) {
            if (n % i == 0) {
                temp.add(i);
                helper(n / i, i, temp, res);
                temp.remove(temp.size() - 1);
            }
        }
    }
    
    public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            int n = sc.nextInt();
            sc.close();
            List<List<Integer>> res = new ArrayList<>();
            List<Integer> temp = new ArrayList<>();
            helper(n, 2, temp, res);
            res.remove(res.size() - 1);
            System.out.println(res);
        }
}