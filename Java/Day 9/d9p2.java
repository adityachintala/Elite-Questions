
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
Swap s[0] and s[1], s = "deb"
Swap s[1] and s[2], s = "dbe"
Swap s[0] and s[1], s = "bde"

*/

// Code contributed by Supriya Deolankar

import java.util.*;

class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        int n = sc.nextInt();
        int[][] seats = new int[n][2];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                seats[i][j] = sc.nextInt();
            }
        }
        sc.close();
        DSU dsu = new DSU(s.length());
        System.out.println(dsu.smallest(seats, s));
    }
}

class DSU {
    int[] parent;

    DSU(int n) {
        parent = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        return parent[x];
    }

    void union(int x, int y, String s) {
        int xp = find(x);
        int yp = find(y);
        if (xp != yp) {
            for (int i = 0; i < parent.length; i++) {
                if (parent[i] == xp) {
                    parent[i] = yp;
                }
            }
        }
    }

    StringBuilder smallest(int[][] seats, String s) {
        for (int i = 0; i < seats.length; i++) {
            union(seats[i][0], seats[i][1], s);
        }
        HashMap<Integer, ArrayList<Character>> hm = new HashMap<>();
        for (int i = 0; i < parent.length; i++) {
            ArrayList<Character> l;
            if (hm.containsKey(parent[i])) {
                l = hm.get(parent[i]);
            } else {
                l = new ArrayList<Character>();
            }
            l.add(s.charAt(i));
            hm.put(parent[i], l);
        }
        for (int i : hm.keySet()) {
            ArrayList<Character> l = hm.get(i);
            Collections.sort(l);
            hm.put(i, l);
        }
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < parent.length; i++) {
            ArrayList<Character> l = hm.get(parent[i]);
            ans.append(l.get(0));
            l.remove(0);
            hm.put(parent[i], l);
        }
        return ans;
    }
}