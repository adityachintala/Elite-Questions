/*


Balbir singh is working with Binary Trees.
The elements of the tree is given in the level order format.
Balbir is looking the tree from right side. 
So, he can view only rihtmost nodes only (one node per level).

You will be given the root of the binary tree.
Your task is to find the nodes which can be viewed by Balbir from right side.
And print the nodes from top to bottom order.

Your task is to implement the class Solution:
	- public List<Integer> rightSideView(BinaryTreeNode root):
	return the list of node values.
	
NOTE: 
Please do consider the node with data '-1' as null node in the given trees.

Input Format:
-------------
Space separated integers, elements of the tree.

Output Format:
--------------
Print a boolean value.


Sample Input-1:
---------------
1 2 3 5 -1 -1 5

Sample Output-1:
----------------
[1, 3, 5]



Sample Input-2:
---------------
3 2 4 3 2

Sample Output-2:
----------------
[3, 4, 2]



*/

import java.util.*;
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

class Solution {
    public void dfs(Node root,List<Integer> ll,int level){
        if(root==null || root.data==-1) return;
        if(ll.size()==level) ll.add(root.data);
        dfs(root.right,ll,level+1);
        dfs(root.left,ll,level+1);
    }
    public List<Integer> rightSideView(Node root) {
        // Implement Your Code here..
        List<Integer> ll=new ArrayList<>();
        dfs(root,ll,0);
        return ll;
    }
}
