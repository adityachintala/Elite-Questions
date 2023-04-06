/*
Ms Tejaswi is given a Triply Linked list (TLL), The Triply linked list contains
three pointers left, right and down.

The TLL is created in multi level format as follows:
    - In each level only one Node will be connected to another Node 
      through down pointer.
    - For the remaining Nodes in that level, the down pointer ponits to null. 

Your task is to convert the given TLL to DLL (Doubly Linked List) as follows:
    - The priority for processing the TLL pointers are
      1. down, 2.right, 3.left
    - You need to follow Depth First approach, and convert the TLL to DLL

You need to implement the Solution Class:
    - public Node convertToDLL(Node head) : return the head node.

NOTE: All the levels should be processed first, before you process the right node.

NOTE: 
- The numbers printed on the board in each row and each column are
  in increasing order. And all the numbers are unique.

Input Format:
-------------
Single line comma',' separated data of the list, integer

Output Format:
--------------
Print the modified doubly linked list as given sample.


Sample Input-1:
---------------
1,2,3,null,null,4,5,6,null,null,7,8,9,null,null,11,11,12

Sample Output-1:
----------------
1->2->4->5->7->8->11->11->12->9->6->3

Explanation:
------------
Please look the hint


Sample Input-2:
---------------
1,2,3,4,5,null,null,null,6,7,8,9,null,null,10,11

Sample Output-2:
----------------
1->2->3->6->7->10->11->8->9->4->5




*/



/*
//Structure of the node in Triply Linked List(TLL)

class Node {
    public int val;
    public Node left;
    public Node right;
    public Node down;
}

*/
import java.util.*;
class Solution{
    List<Integer> ll;
    public Node convertToDLL(Node head) {
        //implement this method
        ll=new ArrayList<>();
        dfs(head);
        Node dummy=new Node();
        Node temp=dummy;
        for(int i:ll){
            Node curr=new Node();
            curr.val=i;
            temp.right=curr;
            curr.left=temp;
            temp=curr;
        }
        return dummy.right;
    }
    public void dfs(Node head){
        if(head==null) return;
        ll.add(head.val);
        dfs(head.down);
        dfs(head.right);
    }
}