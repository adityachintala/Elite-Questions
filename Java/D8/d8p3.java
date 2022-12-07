
/*
 * Jason Statham is a well known transporter.
He transports goods from one place to other place using his container.
The container is divided into M*N slots, you can place M*N items in it.
In the container few slots are closed, you can't use them.
No other item can move from it.

When the items are loaded the container looks like an M*N grid, 
but to unload the items from the container it is turned 90-derees clockwise.
So, the Items in the container moves through the empty slots and set one on one.
If there is an closed slot, the items will be fall on the closed slot.

You will be given a matrix of size M*N, consists of 3 letters [I,O,S]
Where I indicates item, O indicates closed slot, S indicates empty slot.

Your task is to help Jason Stathamto know the positions of items, empty slots and 
closed slots after turning the container 90-degree clockwise.

Input Format:
-------------
Line-1: Two space separated integers M and N, size of the container
Next M lines: A string of length N, consists only 3 characters [I, O, S]

Output Format:
--------------
Print a charcter matrix of size N*M as described in sample.


Sample Input-1:
---------------
2 3
ISI
ISO

Sample Output-1:
----------------
SS
II
OI

Explanation:
------------
Look at hint for explanation.


Sample Input-2:
---------------
3 6
IIOSOS
IIIOSS
IIISIS

III
III
OII
SOS
OSI
SSS

Sample Output-2:
----------------
SII
SII
IIO
IOS
ISO
ISS

Explanation:
------------
Look at hint for explanation.

*/
import java.util.*;

/**
 * d8p3
 */
public class d8p3 {

    static void shawarma(char arr[][]) {
        for (int i = 0; i < arr[0].length; i++) {
            for (int j = arr.length - 1; j >= 0; j--) {
                if(arr[j][i] == 'S' && j > 0) {
                    if(arr[j-1][i] == 'I') {
                        arr[j][i] = 'I';
                        arr[j-1][i] = 'S';
                    }
                    else if(arr[j][i] == 'S') {
                        int k = j - 1;
                        while(k >= 0 && arr[k][i] == 'S') {
                            k--;
                        }
                        if(k >= 0 && arr[k][i] == 'I') {
                            arr[j][i] = 'I';
                            arr[k][i] = 'S';
                        }
                    }
                }
            }
        }
    }
    
    // Where I indicates item, O indicates closed slot, S indicates empty slot.
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int n = sc.nextInt();
        char ans[][] = new char[n][m];
        // input taken in reverse order
        for (int i = 0; i < m; i++) {
            String s = sc.next();
            for (int j = 0; j < n; j++) {
                ans[j][i] = s.charAt(j);
            }
        }
        sc.close();
        shawarma(ans);
        System.out.println();
        // messed taking the input in correct so printing every singular array in revese order
        for (int i = 0; i < n; i++) {
            for (int j = m - 1; j >= 0; j--) {
                System.out.print(ans[i][j]);
            }
            System.out.println();
        }
    }
}