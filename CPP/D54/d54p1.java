/*

In a joint family of N members, every person assigned with an ID, an integer value.
and the entire family is arranged in the from of binary tree.

You will be given the preOrder data and inOrder data of the tree.
Your task is to build the original fammily tree using the given data.
and return the root of the tree.

Implement the class Solution:
    - Node buildBinaryTree(int[] preOrder, int[] inOrder):
        return the root node of the tree.

Input Format:
-------------
Line-1: An integer N, number of persons in the family.
Line-2: N space separated integers, preOrder[] data.
Line-3: N space separated integers, inOrder[] data.

Output Format:
--------------
Return the root node of the original tree.


Sample Input-1:
---------------
7
1 2 4 5 3 6 7
4 2 5 1 6 3 7

Sample Output-1:
----------------
1 2 3 4 5 6 7 



Sample Input-2:
---------------
8
1 2 8 3 4 6 5 7
2 8 1 6 4 3 5 7

Sample Output-2:
----------------
1 2 3 8 4 5 6 7



*/



import java.util.*;

/*
Reference of Node

class Node {
    public int data;
    public Node left;
    public Node right;
    public Node(int value) {
        data = value;
        left = null;
        right = null;
    }
}

*/

class Solution{
    int i = 0;
    Node buildBinaryTree(int[] preOrder, int[] inOrder){
        // Implement your code here.
        return helper(preOrder,inOrder,0,preOrder.length-1);
        
    }
    Node helper(int[] preOrder,int[] inOrder,int left,int right){
        if(i == preOrder.length || left> right ){
            return null;
        }
        Node root = new Node (preOrder[i]);
        for(int j=left;j<=right;j++){
            if(preOrder[i] == inOrder[j]){
                i++;
                root.left = helper(preOrder,inOrder,left,j-1);
                root.right = helper(preOrder,inOrder,j+1,right);
                break;
            }
            
        }
        return root;
    } 
}