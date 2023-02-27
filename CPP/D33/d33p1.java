/*
Indian Army setup some military-camps, sitauted at random places at LAC in Galwan.
There exist a main base camp connected with other base camps as follows:
Each military-camp is connected with atmost two other military-camps.
Each military-camp will be identified with an unique ID,(an integer).

To safeguard all the military-camps, Govt of India planned to setup protective 
S.H.I.E.L.D. Govt of India ask your help to build the S.H.I.E.L.D that should 
enclose all the militar-camps.

You are given the IDs of the military-camps as binary tree. 
Your task is to find and return the military camp IDs, those are on the edge of 
the S.H.I.E.L.D in anti-clockwise order.

Implement the class Solution:
   1. public List<Integer> compoundWall(BinaryTreeNode root): returns a list.
  

NOTE:
'-1' in the input IDs indicates no military-camp (NULL).


Input Format:
-------------
space separated integers, military-camp IDs.

Output Format:
--------------
Print all the military-camp IDs, which are at the edge of S.H.I.E.L.D.


Sample Input-1:
---------------
5 2 4 7 9 8 1

Sample Output-1:
----------------
[5, 2, 7, 9, 8, 1, 4]


Sample Input-2:
---------------
11 2 13 4 25 6 -1 -1 -1 7 18 9 10

Sample Output-2:
----------------
[11, 2, 4, 7, 18, 9, 10, 6, 13]




import java.util.*;

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

class Solution{
    public void left(Node root,ArrayList<Integer> res){
           if(root==null || root.data==-1) return;
           if((root.left!=null && root.left.data!=-1) || (root.right!=null && root.right.data!=-1))res.add(root.data);
           if((root.left!=null && root.left.data!=-1)) left(root.left,res);
           else if((root.left==null || root.left.data==-1) && (root.right!=null && root.right.data!=-1)) left(root.right,res);
    }
       public void right(Node root,ArrayList<Integer> res){
           if(root==null || root.data==-1) return;
           if(root.right!=null && root.right.data!=-1) right(root.right,res);
           else if((root.right==null || root.right.data==-1) &&(root.left!=null && root.left.data!=-1)) right(root.left,res);
           if((root.left!=null && root.left.data!=-1) || (root.right!=null && root.right.data!=-1))res.add(root.data);
       }
       public void leaf(Node root,ArrayList<Integer> res){
           if(root==null || root.data==-1) return;
           if((root.left==null || root.left.data==-1) && (root.right==null || root.right.data==-1))res.add(root.data);
           leaf(root.left,res);
           leaf(root.right,res);
       }
       public List<Integer> compoundWall(Node root) {
           ArrayList<Integer> res = new ArrayList<>();
           if(root!=null && root.data!=-1) res.add(root.data);
           left(root.left,res);
           leaf(root,res);
           right(root.right,res);
           return res;
           //implement your code here.
       }
   }
