/*
A game-zone is represented as an infinite 2D grid. At every integer coordinate 
(x,y) there is a bag, and the bag contains |x| + |y| number of chocolates in it.

You want grab N chocolates for your kid. You have to select some square area in 
the game-zone such a way that the selected area is an axis-aligned square plot 
that is centered at (0, 0).

Your task is to find the minimum perimeter of the square area such that 
at least it conains N chocolates are inside or on the perimeter of that area.

NOTE: 
The value of |x| is defined as: x if x >= 0 -x if x < 0

Constarint:
-----------
1 <= N <= 10^14

Input Format:
-------------
An integer N, number of chocolates.

Output Format:
--------------
Print an integer result.


Sample Input-1:
---------------
5

Sample Output-1:
----------------
8

Explanation:
------------
Self-Explanatory

Sample Input-2:
---------------
56

Sample Output-2:
----------------
16

Explanation:
------------
Self-Explanatory


Sample Input-3:
---------------
62

Sample Output-3:
----------------
24

*/

import java.util.*;

public class d9p1 {

    static long BJPforLife(long x) {
        return (long) (4 * Math.pow(x, 3) + 6 * Math.pow(x, 2) + 2*x);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextInt();
        sc.close();
        long low = 0, high = Long.MAX_VALUE, ans = Long.MAX_VALUE;
        while (low < high) {
            long mid = ((long) (low + (high - low) / 2));

            if (BJPforLife(mid) > n) {
                if (mid < ans)
                    ans = mid;
                high = mid;
            }
            else if(BJPforLife(mid) == n){
                ans = mid;
                break;
            }
            else {
                low = mid + 1;
            }
        }
        System.out.println((long)(8 * ans));
    }
}