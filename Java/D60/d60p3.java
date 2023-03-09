/*VishnuVardan is working with Binary Trees.
Kishore is planned to flip the binary tree horizontally.

The rules to flip the binary tree are as follows:
	- The original root node becomes the new right node.
	- The original left node becomes the new root node.
	- The original right node becomes the new left node.

Your task is to help VishnuVardan to flip the tree horizontally with 
given rule set.

Your task is to implement the class Solution:
	- Node flipTree(Node root) : return the new root node.
	- List<List<Integer>> levelOrder(Node root)

NOTE:
- The mentioned rules are applied level by level
- Every right node in the tree has a left node sharing the same parent
- Every right node in the tree has no children

In the given input '-1 indicates null node.

Input Format:
-------------
Space separated integers, nodes of the tree.

Output Format:
--------------
Print the list of nodes of flipped tree as described below.


Sample Input-1:
---------------
4 2 3 5 1

Sample Output-1:
----------------
[[5],[1,2],[3,4]]


Sample Input-2:
---------------
1 2 3 4 5 -1 -1 6 7

Sample Output-2:
----------------
[[6],[7,4],[5,2],[3,1]]

For explanation look the hint
*/

import java.util.*;

/**
 * d60p3
 */

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

public class d60p3 {

    Node flipTree(Node root) {
        if (root == null)
            return root;
        if (root.left == null && root.right == null)
            return root;
        
        Node flippedRoot = flipTree(root.left);

        root.left.left = root.right;
        root.left.right = root;
        root.left = root.right = null;
        return flippedRoot;
    }

    List<List<Integer>> levelOrder(Node res) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        Queue<Node> q = new LinkedList<Node>();
        q.add(res);
        while (!q.isEmpty()) {
            int size = q.size();
            List<Integer> list = new ArrayList<Integer>();
            for (int i = 0; i < size; i++) {
                Node node = q.poll();
                list.add(node.data);
                if (node.left != null) {
                    q.add(node.left);
                }
                if (node.right != null) {
                    q.add(node.right);
                }
            }
            result.add(list);
        }
        return result;
    }

    public static void main(String[] args) {
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(1);
        root.right.left = new Node(4);
        root.right.right = new Node(5);
        root.left.left = new Node(3);

        d60p3 obj = new d60p3();
        List<List<Integer>> result = obj.levelOrder(root);
        System.out.println(result);

        Node flippedRoot = obj.flipTree(root);
        List<List<Integer>> flippedResult = obj.levelOrder(flippedRoot);
        System.out.println(flippedResult);
    }

}