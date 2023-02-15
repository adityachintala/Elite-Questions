// In an english training institute, the trainer Reeta given a task to the trainees.
// We know that, in english we have prefixes and suffixes for the words.
// You can divide a word as concatenation of prefix and suffix.
// i.e., word = prefix + suffix, another = an + other

// You will be given a list of prefixes and a statement consisting of words.
// Now, the task given to the trainees is as follows:
// 	- Replace all the words in the statement with the prefix, 
// 	  if you found prefix of that word in the list.
// 	- If you found more than one prefix in the list for a word in the statement,
// 	  replace the word with the prefix that has the shortest length.

// Your task is to help the trainees to prepare and print the final statement
// after all the replacements done.

// Input Format:
// -------------
// Line-1: Space separated strings, prefixes.
// Line-2: A single line of words, statement.

// Output Format:
// --------------
// Print the String, the final statement.


// Sample Input-1:
// ---------------
// am add mean ref 
// amigos used to address or refer to a friend

// Sample Output-1:
// ----------------
// am used to add or ref to a friend


// Sample Input-2:
// ---------------
// th the pa tho
// thomas the trainer teaches theroy part of thermodynamics

// Sample Output-2:
// ----------------
// th th trainer teaches th pa of th


#include<bits/stdc++.h>
using namespace std;

class Trie {

public:

    //N is number of possible characters in a string
    const static int N = 26;

    //baseChar defines the base character for possible characters
    //like '0' for '0','1','2'... as possible characters in string 
    const static char baseChar = 'a';

    struct TrieNode
    {
        int next[N];
        //if isEnd is set to true , a string ended here
        bool isEnd;
        //freq is how many times this prefix occurs
        int freq;

        TrieNode()
        {
            for(int i=0;i<N;i++)
                next[i] = -1;
            isEnd = false;
            freq = 0;
        }
    };

    //the implementation is via vector and each position in this vector
    //is similar as new pointer in pointer type implementation
    vector <TrieNode> tree;

    //Base Constructor
    Trie ()
    {
        tree.push_back(TrieNode());
    }

    //inserting a string in trie
    void insert(const string &s)
    {
        int p = 0;
        tree[p].freq++;
        for(int i=0;i<s.size();i++)
        {
            // tree[]
            if(tree[p].next[s[i]-baseChar] == -1)
            {
                tree.push_back(TrieNode());
                tree[p].next[s[i]-baseChar] = tree.size()-1;
            }

            p = tree[p].next[s[i]-baseChar];
            tree[p].freq++;
        }
        tree[p].isEnd = true;
    }

    //check if a string exists as prefix
    bool checkPrefix(const string &s)
    {
        int p = 0;
        for(int i=0;i<s.size();i++)
        {
            if(tree[p].next[s[i]-baseChar] == -1)
                return false;

            p = tree[p].next[s[i]-baseChar];
        }
        return true;
    }

    //check is string exists
    bool checkString(const string &s)
    {
        int p = 0;
        for(int i=0;i<s.size();i++)
        {
            if(tree[p].next[s[i]-baseChar] == -1)
                return false;

            p = tree[p].next[s[i]-baseChar];
        }

        return tree[p].isEnd;
    }

    //persistent insert
    //returns location of new head
    int persistentInsert(int head , const string &s)
    {
        int old = head;

        tree.push_back(TrieNode());
        int now = tree.size()-1;
        int newHead = now;

        int i,j;

        for(i=0;i<s.size();i++)
        {
            if(old == -1)
            {
                tree.push_back(TrieNode());
                tree[now].next[s[i]-baseChar] = tree.size() - 1;
                tree[now].freq++;
                now = tree[now].next[s[i]-baseChar];
                continue;
            }
            for(j=0;j<N;j++)
                tree[now].next[j] = tree[old].next[j];
            tree[now].freq = tree[old].freq;
            tree[now].isEnd = tree[old].isEnd;

            tree[now].freq++;
            
            tree.push_back(TrieNode());
            tree[now].next[s[i]-baseChar] = tree.size()-1;

            old = tree[old].next[s[i]-baseChar];
            now = tree[now].next[s[i]-baseChar];
        }

        tree[now].freq++;
        tree[now].isEnd = true;

        return newHead;
    }

    //persistent check prefix
    bool persistentCheckPrefix(int head, const string &s)
    {
        int p = head;
        for(int i=0;i<s.size();i++)
        {
            if(tree[p].next[s[i]-baseChar] == -1)
                return false;

            p = tree[p].next[s[i]-baseChar];
        }
        return true;
    }

    //persistent check string
    bool persistentCheckString(int head, const string &s)
    {
        int p = head;
        for(int i=0;i<s.size();i++)
        {
            if(tree[p].next[s[i]-baseChar] == -1)
                return false;

            p = tree[p].next[s[i]-baseChar];
        }
        return tree[p].isEnd;
    }
};


int main(){
    string p,k;
    getline(cin,p);
    vector<string> to_be_added;
    istringstream obj(p);
    while(obj>>k){
        to_be_added.push_back(k);
    }
    string p1,k1;
    getline(cin,p1);
    vector<string> to_be_checked;
    istringstream obj1(p1);
    while(obj1>>k1){
        to_be_checked.push_back(k1);
    }
    Trie trie = Trie();
    for(auto it:to_be_added){
        trie.insert(it);
    }
    vector<string> res;
    for(auto it:to_be_checked){
        bool added= false;
        for(int j=0;j<it.size();j++){
            string prefix = it.substr(0,j+1);
            if(trie.checkString(prefix)){
                res.push_back(prefix);
                added = true;
                break;
            }
        }
        if(added==false){
            res.push_back(it);
        }
    }
    for(auto it:res){
        cout<<it<<' ';
    }
    return 0;
}