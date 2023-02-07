/*
 * Chitti(ROBO) is busy in turning the people into chittis(ROBOS) by surrounding them.
In a room there are n*n boxes occupied by ROBOS and people.
   1.A person will be turned into ROBO if he is surrounded by all ROBOs. 
   2.A person will not be turned into ROBO if he is on the edge of the room
     and all the connected people to him (directly or indirectly) are also not to be turned.
 Return the n*n boxes after conversion.
 
Input Format
-------------
Line-1:integer n represent the n*n boxes of the room..
Next n lines:Each line of string consists of combination of 'X'(represents ROBO) and 'O'(represents a person)
   
Output Format:
--------------
Print n*n space seperated values after conversion.
  
   
Sample Input-1:
---------------
4
XXXX
XOOX
XXOX
OXXX
   
Sample Output-1:
----------------
X X X X 
X X X X 
X X X X 
O X X X 
   
Explanation:
------------
The people at second row and third row are converted to ROBOs as they are surrounded by ROBOs.
But the person at fourth row is safe as he is on edge.
  
   
Sample Input-2:
---------------
5
XOOOX
XXXXX
XOXXX
XXXOX
OXXXX
  
Sample Output-2:
----------------
X O O O X 
X X X X X 
X X X X X 
X X X X X 
O X X X X 

*/

import java.util.*;

/**
 * d44p6
 */
public class d44p6 {

    static boolean isSurrounded(int arr[][], int i, int j) {
        if ((i == 0 || i == arr.length - 1 || j == 0 || j == arr.length - 1) && arr[i][j] == 0) {
            return false;
        }
        if (arr[i][j] == 1) {
            return true;
        }
        arr[i][j] = 1;
        boolean flag = true;
        flag = flag & 
               isSurrounded(arr, i-1, j) &
               isSurrounded(arr, i+1, j) &
               isSurrounded(arr, i, j-1) &
                isSurrounded(arr, i, j + 1);
        arr[i][j] = 0;
        return flag;

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int arr[][] = new int[n][n];
        for (int i = 0; i < n; i++) {
            String s = sc.next();
            for (int j = 0; j < n; j++) {
                if (s.charAt(j) == 'X') {
                    arr[i][j] = 1;
                }
            }
        }
        sc.close();
        // 1 == x
        // 0 == o
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (arr[i][j] == 0 && isSurrounded(arr, i, j)) {
                    arr[i][j] = 1;
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == 1) {
                    System.out.print("X ");
                } else {
                    System.out.print("O ");
                }
            }
            System.out.println();
        }
    }
}