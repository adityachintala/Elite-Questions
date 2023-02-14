// In a school, the students are given an array of strings words[]. Students have 
// to find the longest string in words[] such that every prefix of it is also in words.

// For example, let words = ["a", "app", "ap","appl", "apply"]. The string "apply" 
// has prefixes "ap","app","appl" and "a", all of which are in words.

// Your task is the find and return the longest string in words as described above.

// If there is more than one string with the same length, return the lexicographically
// smallest one, and if no string exists, return "".

// Input Format
// -------------
// Line1: string separated by spaces
 
// Output Format
// --------------
// string 

// Sample Input-1:
// ---------------
// k kmi km kmit

// Sample Output-1:
// ----------------
// kmit

// Explanation:
// ------------
// "kmit" has prefixes "kmi", "km", "k" and all of them appear in words.


// Sample Input-2:
// ---------------
// t tanker tup tupl tu tuple tupla

// Sample Output-2:
// ----------------
// tupla

// Explanation:
// ------------
// Both "tuple" and "tupla" have all their prefixes in words.
// However, "tupla" is lexicographically smaller, so we return that.


// Sample Input-3:
// ---------------
// abc bc ab abcd

// Sample Output-3:
// ----------------
// ""


#include<bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode *next[26] = {};
    bool word = false;
};

void addWord(TrieNode *node, string &s) {
    for (char c : s) {
        if (!node->next[c - 'a']) node->next[c - 'a'] = new TrieNode();
        node = node->next[c - 'a'];
    }
    node->word = true;
}
string ans, path;
void dfs(TrieNode *node) {
    for (int i = 0; i < 26; ++i) {
        if (!node->next[i] || !node->next[i]->word) continue;
        path += 'a' + i;
        if (path.size() > ans.size()) ans = path;
        dfs(node->next[i]);
        path.pop_back();
    }
}


int main(){
    TrieNode root;
    vector<string> A;
    string p,k;
    getline(cin,p);
    istringstream obj(p);
    while(obj>>k){
        A.push_back(k);
    }
    for (auto &s : A) addWord(&root, s);
    dfs(&root);
    cout<<ans;
    return 0;
}