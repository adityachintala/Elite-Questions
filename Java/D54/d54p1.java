// Given a preorder traversal of a tree as an array of integers arr[].
// Construct a binary search tree for the above tree.

// Note: 
//     A binary search tree is a binary tree where for every node, any 
//     descendant of Node.left has a value strictly less than Node.val, and 
//     any descendant of Node.right has a value strictly greater than Node.val.
     
//     A preorder traversal of a binary tree displays the value of the node first, 
//     then traverses Node.left, then traverses Node.right.

// Your task is to print the level order traversal of binary search tree that
// has been constructed using the pre order values of a binary tree.
// In the output, all null nodes in the level order traversal are indicated with -1. 

// Input Format:
// -------------
// Line-1: Size of array n
// Line-2: Array elements of size n.

// Output Format:
// --------------
// Print the level order traversal


// Sample Input-1:
// ---------------
// 6
// 10 6 2 8 12 16

// Sample Output-1:
// ----------------
// 10 6 12 2 8 -1 16


// Sample Input-2:
// ---------------
// 3 5

// Sample Output-2:
// ----------------
// 3 -1 5

import java.util.*;

/**
 * d54p1
 */

class Node {
    int val;
    Node left;
    Node right;

    public Node(int val) {
        this.val = val;
        this.left = null;
        this.right = null;
    }
}

class BST {
    Node root;

    public BST() {
        this.root = null;
    }

    public void insert(int val) {
        Node newNode = new Node(val);
        if (root == null) {
            root = newNode;
            return;
        }

        Node curr = root;
        Node parent = null;
        while (curr != null) {
            parent = curr;
            if (val < curr.val) {
                curr = curr.left;
            } else {
                curr = curr.right;
            }
        }

        if (val < parent.val) {
            parent.left = newNode;
        } else {
            parent.right = newNode;
        }
    }

    public void levelOrderTraversal() {
        Queue<Node> queue = new LinkedList<Node>();
        queue.add(root);
        while (!queue.isEmpty()) {
            Node curr = queue.poll();
            if (curr != null) {
                System.out.print(curr.val + " ");
                queue.add(curr.left);
                queue.add(curr.right);
            } else {
                System.out.print("-1 ");
            }
        }
    }
}

public class d54p1 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] preorder = new int[n];
        for (int i = 0; i < n; i++) {
            preorder[i] = sc.nextInt();
        }

        BST bst = new BST();
        for (int i = 0; i < n; i++) {
            bst.insert(preorder[i]);
        }

        bst.levelOrderTraversal();
        sc.close();
    }
    
}