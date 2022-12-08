/*
In an exam hall, seating arrangement is done in a row, When an invigilator 
enters into exam hall he wants to exchange(swap) some students places in pairs.

Note: student names will be alphabets(a,b,c...z) may be repeated,
and seat number starts from zero(0 to N-1) where N is the number of students.

Invigilator may swap the students at any pair of seats(indices) in 
the given pairs any number of times.

Given the seating-arrangement s, and list of pairs of seats(indices) in 
seating-arrangement pairs where pairs[i]=[x,y] denotes 2 indices 
(index starts from zero(0)) of the seating-arrangement s.

Your task is to print the lexicographically smallest seating-arrangement S
that has been changed after using the swaps.


Input Format:
-------------
Line-1: Read a String seating-arrangement s.
Line-2: Read the number of pairs of seat numbers to swap R.
Next R lines: Two space separated integers, pair of seat numbers.

Output Format:
--------------
Print the lexicographically smallest seating-arrangement s after using the swaps.

Sample Input-1:
---------------
feabdc
2       
0 4
1 3

Sample Output-1:
----------------
dbaefc

Explanation:
------------
Swap s[0] and s[4], s = "deabfc"
Swap s[1] and s[3], s = "dbaefc"

Sample Input-2:
---------------
edb
2
0 1
1 2

Sample Output-2:
----------------
bde


Explanation:
------------
edb
deb
dbe
bde
Swap s[0] and s[1], s = "deb"
Swap s[1] and s[2], s = "dbe"
Swap s[0] and s[1], s = "bde"
*/

// Naveen's CPP code translated to Java

import java.util.*;

class DSU {
    public ArrayList<Integer> parent;
    public ArrayList<Integer> height;
    public ArrayList<Integer> size;

    DSU(int n) {
        parent = new ArrayList<Integer>(Collections.nCopies(n, -1));
        size = new ArrayList<Integer>(Collections.nCopies(n, 1));
        height = new ArrayList<Integer>(Collections.nCopies(n, 1));
    }

    int findRoot(int node) {
        if (parent.get(node) == -1) {
            return node;
        }
        return (parent.set(node, findRoot(parent.get(node))));
    }

    int Union(int node1, int node2) {
        int ra = findRoot(node1);
        int rb = findRoot(node2);
        if (ra != rb) {
            if (height.get(ra) < height.get(rb)) {
                parent.set(ra, rb);
                size.set(rb, size.get(rb) + size.get(ra));
                return size.get(rb);
            } else if (height.get(rb) < height.get(ra)) {
                parent.set(rb, ra);
                size.set(ra, size.get(ra) + size.get(rb));
                return size.get(ra);
            } else {
                parent.set(rb, ra);
                height.set(ra, height.get(ra) + 1);
                size.set(ra, size.get(ra) + size.get(rb));
                return size.get(ra);
            }
        }
        return -1;
    }
}

/**
 * d9p2
 */
public class d9p2 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int n = sc.nextInt();
        int n1 = s.length();
        DSU dsu = new DSU(n1 * n1);
        for (int i = 0; i < n; ++i) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            dsu.Union(x, y);
        }
        sc.close();
        HashMap<Integer, ArrayList<Integer>> mp = new HashMap<>();
        for (int i = 0; i < n1; ++i) {
            int root = dsu.findRoot(i);
            if (mp.containsKey(root)) {
                mp.get(root).add(i);
            } else {
                ArrayList<Integer> temp = new ArrayList<>();
                temp.add(i);
                mp.put(root, temp);
            }
        }
        for (Map.Entry<Integer, ArrayList<Integer>> it : mp.entrySet()) {
            String temp = "";
            for (int i : it.getValue()) {
                temp += s.charAt(i);
            }
            char[] temp1 = temp.toCharArray();
            Arrays.sort(temp1);
            int c = 0;
            for (int i : it.getValue()) {
                s = s.substring(0, i) + temp1[c++] + s.substring(i + 1);
            }
        }
        System.out.println(s);
    }
}