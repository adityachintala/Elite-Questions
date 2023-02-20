/*
Given a preorder traversal of a tree as an array of integers arr[].
Construct a binary search tree for the above tree.

Note: 
    A binary search tree is a binary tree where for every node, any 
    descendant of Node.left has a value strictly less than Node.val, and 
    any descendant of Node.right has a value strictly greater than Node.val.
     
    A preorder traversal of a binary tree displays the value of the node first, 
    then traverses Node.left, then traverses Node.right.

Your task is to print the level order traversal of binary search tree that
has been constructed using the pre order values of a binary tree.
In the output, all null nodes in the level order traversal are indicated with -1. 

Input Format:
-------------
Line-1: Size of array n
Line-2: Array elements of size n.

Output Format:
--------------
Print the level order traversal


Sample Input-1:
---------------
6
10 6 2 8 12 16

Sample Output-1:
----------------
10 6 12 2 8 -1 16


Sample Input-2:
---------------
3 5

Sample Output-2:
----------------
3 -1 5


*/


#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> ans(1e5);
int k=0;
void recfunc(vector<int> arr,vector<int> b,int i,int j,int idx){ 
    if(i>j){
        ans[idx].push_back(-1);return;
    }
    int x=arr[k];
    ans[idx].push_back(arr[k++]);
    int mid = lower_bound(b.begin(),b.end(),x)-b.begin();
    recfunc(arr,b,i,mid-1,idx+1);
    recfunc(arr,b,mid+1,j,idx+1);
}

int main(){
    int n;cin>>n;
    vector<int> arr(n),b(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        b[i] = arr[i];
    }
    sort(b.begin(),b.end());
    recfunc(arr,b,0,n-1,0);
    vector<int> res;
    for(auto x: ans){
        if(x.size()==0){
            break;
        }
        if(x.size()==1 and x[0]==-1){
            break;
        }
        for(auto y: x){
             res.push_back(y);
        } 
    } 
    while(res.back()==-1){
        res.pop_back();
    }
    for(auto x: res)cout<<x<<" ";
    return 0;
}