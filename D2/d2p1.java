/*
 Vihaar is working with strings. 
He is given two strings A and B, and another string T,
where the length of A and B is same.

You can find the relative groups of letters from A and B,
using the following rule set:
- Equality rule: 'p' == 'p'
- Symmetric rule: 'p' == 'q' is same as 'q' == 'p'
- Transitive rule: 'p' == 'q' and 'q' == 'r' indicates 'p' == 'r'.

Vihaar has to form the relatively smallest string of T,
using the relative groups of letters.

For example, if A ="pqr" and B = "rst" , 
then we have 'p' == 'r', 'q' == 's', 'r' == 't' .

The relatives groups formed using above rule set are as follows: 
[p, r, t] and [q,s] and  String T ="tts", then relatively smallest string is "ppq".

You will be given the strings A , B and T.
Your task is to help Vihaar to find the relatively smallest string of T.


Input Format:
-------------
Three space separated strings, A , B and T

Output Format:
--------------
Print a string, relatively smallest string of T.


Sample Input-1:
---------------
kmit ngit mgit

Sample Output-1:
----------------
ggit

Explanation: 
------------
The relative groups using A nd B are [k, n], [m, g], [i], [t] and
the relatively smallest string of T is "ggit"


Sample Input-2:
---------------
attitude progress apriori

Sample Output-2:
----------------
aaogoog

Explanation: 
------------
The relative groups using A nd B are [a, p], [t, r, o], [i, g] and [u, e, d, s]
the relatively smallest string of T is "aaogoog"

 */

import java.util.*;

public class d2p1 {

    static void union(int parent[], int u, int v) {
        int x = find(parent, u);
        int y = find(parent, v);
        if (x != y) {
            if (x > y) {
                parent[x] = y;
            }
            else {
                parent[y] = x;
            }
        }
    }

    static int find(int parent[], int x) {
        if (parent[x] == x) {
            return x;
        }
        return find(parent, parent[x]);
    }

    static String func(String a, String b, String t) {
        int parent[] = new int[26];
        String res = "";
        for (int i = 0; i < parent.length; i++) {
            parent[i] = i;
        }
        // System.out.println(Arrays.toString(parent));

        for (int i = 0; i < a.length(); i++) {
            int u = (a.charAt(i)) - 'a';
            int v = (b.charAt(i)) - 'a';
            union(parent, u, v);
        }

        // for (int i = 0; i < 26; i++) {
        //     System.out.println(parent[i] + " " + (char) (i + 'a'));
        // }

        for (int i = 0; i < t.length(); i++) {
            res += (char) (find(parent, (int)(t.charAt(i) - 'a')) + 'a');
        }

        return res;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        String b = sc.next();
        String c = sc.next();

        System.out.println(func(a, b, c));

    }
}
