// Malika taught a new fun time program practice for Engineering Students.
// As a part of this she has given set of N numbers, and asked the students 
// to perform the operations listed below:
// First, build the segment tree and then do the following,
//     1. sumRange(s1, s2) - return the sum of numbers between the indices 
//        s1 and s2, both are inclusive and 0<=s1<=s2<N.
//     2. update(ind, val) - update the value at the index 'ind' to 'val'.

// Your task is to solve this problem using Segment Tree concept.

// Input Format:
// -------------
// Line-1: Two integers N and Q, size of the array(set of numbers) and query count.
// Line-2: N space separated integers.
// next Q lines: Three integers option, start/ind and end/val.

// Output Format:
// --------------
// An integer result, for every sumRange query.


// Sample Input:
// -------------
// 8 5
// 1 2 13 4 25 16 17 8
// 1 2 6	
// 1 0 7		
// 2 2 18	    
// 2 4 17	 
// 1 2 7		

// Sample Output:
// --------------
// 75
// 86
// 80


public class Solution {
// Segment Tree Node structure
    class SegmentTreeNode {
        int start, end;
        SegmentTreeNode left, right;
        int sum;

        public SegmentTreeNode(int start, int end) {
            this.start = start;
            this.end = end;
            this.left = null;
            this.right = null;
            this.sum = 0;
        }
    }
      
    SegmentTreeNode root = null;
   
    public Solution(int[] nums) {
        root = buildTree(nums, 0, nums.length-1);
    }

    private SegmentTreeNode buildTree(int[] nums, int start, int end) {
        if (start == end) {
            SegmentTreeNode leaf = new SegmentTreeNode(start, end);
            leaf.sum = nums[start];
            return leaf;
        }
        SegmentTreeNode node = new SegmentTreeNode(start, end);
        int mid = (start + end) / 2;
        node.left = buildTree(nums, start, mid);
        node.right = buildTree(nums, mid + 1, end);
        node.sum = node.left.sum + node.right.sum;
        return node;
    }
   
    void update(int ind, int val) {
        updateTree(root, ind, val);
    }
    
    private void updateTree(SegmentTreeNode node, int ind, int val) {
        if (node.start == node.end) {
            node.sum = val;
            return;
        }
        int mid = (node.start + node.end) / 2;
        if (ind <= mid) {
            updateTree(node.left, ind, val);
        } else {
            updateTree(node.right, ind, val);
        }
        node.sum = node.left.sum + node.right.sum;
    }
    
    public int sumRange(int i, int j) {
        return sumTree(root, i, j);
    }
    
    private int sumTree(SegmentTreeNode node, int start, int end) {
        if (node.start == start && node.end == end) {
            return node.sum;
        }
        int mid = (node.start + node.end) / 2;
        if (end <= mid) {
            return sumTree(node.left, start, end);
        } else if (start >= mid + 1) {
            return sumTree(node.right, start, end);
        } else {
            return sumTree(node.left, start, mid) + sumTree(node.right, mid + 1, end);
        }
    }
    
}
