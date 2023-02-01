/*
 * In a Marketing Agency, each agent will mentor either two sub-agents,
or zero agents. Now, based on ranks given to sub-agents, the mentor agent 
will be ranked with the top rank among two sub-agents. 

The ranks are in the range [1,20], More than one agent can have same rank.

At the end, all mentor agents and sub agents, will be treated as agents only.

You are given the entire ranking picture as a tree.
Your task is to find out second top agent in the Marketing agency.
If no such agent exist, return -2.

Implement the class Solution:
   1. public int findSecondTopAgent(BinaryTreeNode root): returns an integer.

NOTE:
	- In the tree '-1', indicates empty(null).

Input Format:
-------------
A single line of space separated integers, ranks of each individual.

Output Format:
--------------
Print an integer, second top agent based on rank.


Sample Input-1:
---------------
2 5 2 -1 -1 2 4

Sample Output-1:
----------------
4


Sample Input-2:
---------------
3 3 3 3 3

Sample Output-2:
----------------
-2

::For Tree structure refer to Hint::
 */

import java.util.*;

/**
 * d41p1
 *
 */

 class BinaryTreeNode {
    public int data;
    public BinaryTreeNode left, right;

    public BinaryTreeNode(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}

public class d41p1 {

    public int findSecondTopAgent(BinaryTreeNode root) {
        // implement your code here.
        Queue<BinaryTreeNode> q = new LinkedList<BinaryTreeNode>();
        q.add(root);
        List<Integer> list = new ArrayList<Integer>();

        while (!q.isEmpty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                BinaryTreeNode temp = q.poll();
                list.add(temp.data);
                list.add(temp.data);
                if (temp.left != null && temp.left.data != -1) {
                    q.add(temp.left);
                }
                if (temp.right != null && temp.right.data != -1) {
                    q.add(temp.right);
                }
            }
        }

        Collections.sort(list);

        int max = list.get(0);
        
        for (int i : list) {
            if (i != max) {
                return i;
            }
        }
        
        return -2;
    }
    
}