/*
Implement the treap data structure and 
print the values using in-order traversal
and pre-order traversal methods.

Input:
------
6 3 5 2 4 7 9

Output:
-------
2 3 4 5 6 7 9   // in-order
6 3 2 5 4 7 9   // pre-order

*/


#include<bits/stdc++.h>
using namespace std;

class TreapNode{
    public: 
        int key, priority;
        TreapNode *left, *right;
        TreapNode(int l){
            key = l;
            priority = rand()%100;
            left = right = NULL;
        }
};

TreapNode *leftRotate(TreapNode *x)
{
    TreapNode *y = x->right, *T2 = y->left;
  
    // Perform rotation
    y->left = x;
    x->right = T2;
  
    // Return new root
    return y;
}
TreapNode *rightRotate(TreapNode *y)
{
    TreapNode *x = y->left,  *T2 = x->right;
  
    // Perform rotation
    x->right = y;
    y->left = T2;
  
    // Return new root
    return x;
}
TreapNode* insert(TreapNode* root, int key)
{
    // If root is NULL, create a new node and return it
    if (!root)
        return new TreapNode(key);
  
    // If key is smaller than root
    if (key <= root->key)
    {
        // Insert in left subtree
        root->left = insert(root->left, key);
  
        // Fix Heap property if it is violated
        if (root->left->priority > root->priority)
            root = rightRotate(root);
    }
    else  // If key is greater
    {
        // Insert in right subtree
        root->right = insert(root->right, key);
  
        // Fix Heap property if it is violated
        if (root->right->priority > root->priority)
            root = leftRotate(root);
    }
    return root;
}
  
void inorder(TreapNode* root)
{
    if (root)
    {
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}

void preorder(TreapNode* root)
{
    if (root)
    {
        cout<<root->key<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main(){
    string word;
    getline(cin,word);
    vector<int> words;
    int x;
    istringstream obj(word);
    while(obj>>x){
        words.push_back(x);
    }
    
    TreapNode *root = NULL;
    for(int i=0;i<words.size();i++){
        root=insert(root,words[i]);
    }
    inorder(root);
    cout<<endl;
    preorder(root);
    
}