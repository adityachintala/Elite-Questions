/*
 * In a hall, the blocks are arranged in the form of a tree,
based on the serial numbers allotted to that room.

The seating arrangement is filled in the following way:
	- left sub node data is always smaller than the current node data.
	- right sub node data is always greater than the current node data.
	
You are given the final tree T.
Your task is to convert the tree T to Altered Tree such that every data
of the original tree T is changed to the original data plus sum of all data
greater than the original data in tree T and return the Altered Tree T.
and print the altered tree using in-order traversal.

Your task is to implement the class Solution:
	- public BinaryTreeNode alterTree(BinaryTreeNode root): 
		return the root node of the altered tree.
	- public void inOrder(BinaryTreeNode root):
		print the node data of the altered tree.
	
NOTE: 
The term data indicates serial number of the aspirant.


Input Format:
-------------
Single line space separated integers, serial numbers of the aspirants.

Output Format:
--------------
Print the inorder traversal of altered bst.


Sample Input-1:
---------------
8 3 10 1 6 14 4 7 13

Sample Output-1:
----------------
66 65 62 58 52 45 37 27 14


Sample Input-2:
---------------
4 2 6 1 3 5 7

Sample Output-2:
----------------
28 27 25 22 18 13 7

*/

import java.util.*;

class BinaryTreeNode{
    int data;
    BinaryTreeNode left;
    BinaryTreeNode right;
    
    public BinaryTreeNode(int data){
        this.data=data;
        this.left=null;
        this.right=null;
    }
}

/**
 * Solution
 */
public class Solution {

    int temp = 0;

    public void inorder(BinaryTreeNode root) {
        if (root != null) {
            inorder(root.right);
            temp += root.data;
            root.data = temp;
            inorder(root.left);
        }
    }

    public BinaryTreeNode alterTree(BinaryTreeNode root) {
        // implement this method
        inorder(root);
        return root;
    }

    public void inOrder(BinaryTreeNode root) {
        // implement this method
        if (root != null) {
            inOrder(root.left);
            System.out.print(root.data + " ");
            inOrder(root.right);
        }
    }
    
}