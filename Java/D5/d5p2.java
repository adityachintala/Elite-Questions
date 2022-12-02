/*
 * A transitive law is "If a == b and b == c, then a == c"
Which also says "If a == b and b != c, then a != c"

You will be given a list of strings relations[], i.e, like p==q or p!=q.
Your task is to find out whether all the relations follow the transitive law or not.
If all of them followed return true, otherwise return false.

Input Format:
-------------
Space separated strnigs, list of relations

Output Format:
--------------
Print a boolean value, whether transitive law is obeyed or not.


Sample Input-1:
---------------
a==b c==d c!=e e==f

a b c d e f
a a c d e f
a a c c e f
a a c c e e


Sample Output-1:
----------------
true


Sample Input-2:
---------------
a==b b!=c c==a

a b c
a a c
a a a

Sample Output-2:
----------------
false


Sample Input-3:
---------------
a==b b==c c!=d d!=e f==g g!=d

Sample Output-3:
----------------
true

 */

import java.util.*;

class Relations {
    char a, b;
    boolean eq;

    Relations(char a, char b, boolean eq) {
        this.a = a;
        this.b = b;
        this.eq = eq;
    }

    public String toString() {
        return a + "" + (eq ? "==" : "!=") + b;
    }
}

public class d5p2 {

    static void union(int[] parent, int x, int y) {
        int xset = find(parent, x);
        int yset = find(parent, y);
        if(xset != yset) {
            if(xset < yset) {
                parent[yset] = xset;
            } else {
                parent[xset] = yset;
            }
        }
    }

    static int find(int[] parent, int x) {
        if (parent[x] == x)
            return x;
        return find(parent, parent[x]);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] relations = sc.nextLine().split(" ");
        List<Relations> list = new ArrayList<>();
        char minChar = 'z', maxChar = 'a';
        for (String relation : relations) {
            char a = relation.charAt(0);
            char b = relation.charAt(3);
            boolean eq = relation.charAt(1) == '=';
            list.add(new Relations(a, b, eq));
            if (a < minChar)
                minChar = a;
            if (b < minChar)
                minChar = b;
            if (a > maxChar)
                maxChar = a;
            if (b > maxChar)
                maxChar = b;
        }
        System.out.println(list);
        int parent[] = new int[maxChar - minChar + 1];
        for (int i = 0; i < parent.length; i++) {
            parent[i] = i;
        }
        for (Relations relation : list) {
            if (relation.eq) {
                union(parent, relation.a - minChar, relation.b - minChar);
            }
        }
        for (Relations relation : list) {
            if (!relation.eq) {
                if (find(parent, relation.a - minChar) == find(parent, relation.b - minChar)) {
                    System.out.println("false");
                    return;
                }
            }
        }
        System.out.println("true");
    }
}