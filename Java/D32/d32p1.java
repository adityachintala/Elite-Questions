/*
 * There are some cubes, and each cube has an alphabet (from A to Z) 
printed on it. You can construct different, non-empty words using these 
cubes and each of the word length should be 0 < length <= number of cubes.

You are given a string of alphabets S, 
Your task is to findout number of possible non-empty distinct words

Input Format:
-------------
A string S, consist of A-Z letters only.

Output Format:
--------------
Print an integer, number of possible non-empty distinct words.


Sample Input-1:
---------------
EGG

Sample Output-1:
----------------
8

Explanation:
--------------
The possible distinct words are "E", "G", "EG", "GG", "GE", "EGG", "GEG", "GGE".


Sample Input-2:
---------------
MADAM

Sample Output-2:
----------------
89

*/

import java.util.*;

/**
 * d32p1
 */
public class d32p1 {
    
    static int func(Map<Character, Integer> map) {
        int ans = 0;
        for (Character ch : map.keySet()) {
            if (map.get(ch) != 0) {
                map.put(ch, map.get(ch) - 1);
                ans++;
                ans += func(map);
                map.put(ch, map.get(ch) + 1);
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        sc.close();
        int n = s.length();
        Map<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            char ch = s.charAt(i);
            map.put(ch, map.getOrDefault(ch, 0) + 1);
        }
        System.out.print(func(map));
    }
}