/*

For X-Mas, santa claus is preparing a X-Mas Tree with set of Bulbs.
The bulbs are of different voltages, and preparation of tree as follows:
	- The bulbs are arranged in level-wise, levels are numbered from 0,1,2,3..
	  so on.
	- At level-0: There will be only one bulb as root bulb.,
	- From next level onwards, we have to attach two bulbs to left side,
	  and right side of every bulb in previous level.
	- At each level, there must be two bulbs attached to its previous level bulbs.
	- After the last level, there will be noe more bulbs attached.

You will be given the root of the X-Mas Tree (i.e.,perfect binary tree),
Your task is to return the root of the structure, after you reverse the bulbs
arrangement at ODD levels. 

Implement the class Solution:
1.public Node reverseValuesInOddLevel(Node root): returns the list of integers.


Input Format:
-------------
An integer, number of bulbs.
A single line of space separated integers, voltages of the set of N bulbs.

Output Format:
--------------
Print the list of voltages of the bulbs from the root.


Sample Input-1:
---------------
7
1 2 3 4 5 6 7

Sample Output-1:
----------------
1 3 2 4 5 6 7


Sample Input-2:
---------------
15
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15

Sample Output-2:
----------------
1 3 2 4 5 6 7 15 14 13 12 11 10 9 8


*/

/*
//TreeNode Structure for Your Reference..

class Node{
	public int data; 
	public Node left, right; 
	public Node(int data){
		this.data = data; 
		left = null; 
		right = null; 
	}
}

*/


import java.util.*;
class Solution {
    public void dfs(Node root,int level,List<List<Integer>> ll){
        if(root==null) return;
        ll.get(level).add(root.data);
        dfs(root.left,level+1,ll);
        dfs(root.right,level+1,ll);
        return;
    }
    public int height(Node root){
        if(root==null) return 0;
        return 1+Math.max(height(root.left),height(root.right));
    }
    public List<List<Integer>> helper(Node root) {
        int val=height(root);
        List<List<Integer>> ll=new ArrayList<>();
        for(int i=0;i<val;i++) ll.add(new ArrayList<>());
        dfs(root,0,ll);
        boolean flag=false;
        for(int i=0;i<ll.size();i++){
            if(flag==true){
                List<Integer> temp=ll.get(i);
                Collections.reverse(temp);
            }
            flag=!flag;
        }
        return ll;
    }
    public void alter(List<List<Integer>> list,int level,Node root){
        if(root==null) return;
        root.data=list.get(level).get(0);
        list.get(level).remove(0);
        alter(list,level+1,root.left);
        alter(list,level+1,root.right);
        return;
    }
    public Node reverseValuesInOddLevel(Node root) {
        // Implement Your Code here..
        List<List<Integer>> list=helper(root);
        alter(list,0,root);
        return root;
        
    }
}
