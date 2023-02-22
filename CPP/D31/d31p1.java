/*
For X-Mas, santa claus is preparing a X-Mas Tree with set of Bulbs.
The bulbs are of different voltages, and preparation of tree as follows:
	- The bulbs are arranged in level-wise, levels are numbered from 0,1,2,3..
	  so on.
	- At level-0: There will be only one bulb as root bulb.,
	- From next level onwards, we have to attach atmost two bulbs, one is to
	  left side, and the other is for right side of every bulb in previous level.
	- A bulb B is said to be BRIGHT, if all the bulbs in the path root bulb to 
      bulb B, there are no bulbs with a voltage greater than bulb B.
      
You will be given the root of the X-Mas Tree,
Your task is to return the number of BRIGHT bulbs in the X-Mastree. 

Implement the class Solution:
1.public int brighterBulbs(Node root): returns an integer output.

NOTE:
-----
In the input -1 indicates no bulb (null node).


Input Format:
-------------
An integer, number of bulbs.
A single line of space separated integers, voltages of the set of N bulbs.

Output Format:
--------------
Print the number of BRIGHT bulbs in the tree.


Sample Input-1:
---------------
7
5 6 3 8 2 6 9

Sample Output-1:
----------------
5


Sample Input-2:
---------------
13
1 2 3 4 5 6 7 8 9 10 -1 -1 11

Sample Output-2:
----------------
11


*/

class Solution {
    void dfs(Node root,int[]sum,int res){
        if(root==null) return;
        if(root.data>=res) sum[0]++;
        dfs(root.left,sum,Math.max(root.data,res));
        dfs(root.right,sum,Math.max(root.data,res));
    }
    public int brighterBulbs(Node root) {
        // Implement Your Code here..
        int []sum={0};
        dfs(root,sum,root.data);
        return sum[0];
    }
}