/*
 * 
 * To get the admission into 6th standard in a reputed school in Hyderabad, 
conducted an entrance test. one of the questions in the test was

There was a sequence of characters(String) given, student has to check 
in given String how many substrings are same as reverse of it (palindromic).

Input Format:
-------------
Read a String.

Output Format:
--------------
Print number of palindromic substrings of given string.



Sample Input-1
pqrs
Sample Output-1
4

Explanation: 
"p", "q", "r", "s" are palindromic substrings of given string.


Sample Input-2
pppp
Sample Output-2
10

Explanation: 
"p", "p", "p", "p", "pp", "ppp", "pppp", "pp", "ppp", "pp"  are 
palindromic substrings of given string. 
*/

import java.util.*;

class d46p3 {

    public static boolean isPalindrome(int[] arr, int i, int j) {
        while (i < j) {
            if (arr[i] != arr[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        int n = str.length();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = str.charAt(i) - 'a' + 1;
        }
        // complete in O(n^2) time
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalindrome(arr, i, j)) {
                    count++;
                }
            }
        }
        System.out.println(count);
    }
}