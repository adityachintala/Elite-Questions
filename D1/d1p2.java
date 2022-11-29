/*Mr Suleman is given a checkerboard of size 400*400,where the indices starts from(-200,-200)and ends at(199,199).In one step,he can move the box from position(p,q)to one of the following positions in L shape like as follows:-(p-2,q-1),(p-2,q+1),(p+2,q-1),(p+2,q+1)-(p-1,q+2),(p+1,q+2),(p-1,q-2),(p+1,q-2)

Initially the box is at(0,0)position,and need to move the box to position(m,n).You will be given two integers m and n indicates the position(m,n).

Now your task is to help by Mr Suleman to find the minimum number of steps required to move the box from(0,0)to(m,n).

Note:It is allowed to move out of the board also.

Input Format:-----------------Two space separated integers,m and n,position.

Output Format:------------------Print an integer,minimum number of steps to reach(m,n).

Sample Input-1:---------------2 4

Sample Output-1:----------------2

Explanation:-------------Initially,you are at(0,0)position,you can reach(2,4)as follows:(0,0)->(1,2)->(2,4)

Sample Input-2:---------------4 7

Sample Output-2:----------------5

Explanation:------------Initially,you are at(0,0)position,you can reach(4,7)as follows:(0,0)->(1,2)->(2,4)->(1,6)->(3,5)->(4,7)
*/
import java.util.*;

class d1p2 {

    static int minSteps(int m, int n) {
        int[][] directions = { { -2, -1 }, { -2, 1 }, { 2, -1 }, { 2, 1 }, { -1, 2 }, { 1, 2 }, { -1, -2 }, { 1, -2 } };
        Queue<int[]> queue = new LinkedList<>();
        boolean visited[][] = new boolean[400][400];
        queue.add(new int[] { 0, 0 });
        visited[200][200] = true;
        int steps = 0;
        while (!queue.isEmpty()) {
            int size = queue.size();
            steps++;
            for (int i = 0; i < size; i++) {
                int curr[] = queue.poll();
                if (curr[0] == m && curr[1] == n)
                    return steps;
                for (int[] dir : directions) {
                    int x = curr[0] + dir[0];
                    int y = curr[1] + dir[1];
                    if (x < -200 || x > 199 || y < -200 || y > 199 || visited[x + 200][y + 200])
                        continue;
                    if (x == m && y == n)
                        return steps;
                    visited[x + 200][y + 200] = true;
                    queue.add(new int[] { x, y });
                }
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int n = sc.nextInt();
        System.out.println(minSteps(m, n));
    }
}