// Mr Suresh is working with the plain text P, a list of words w[], 
// He is converting P into C [the cipher text], C is valid cipher of P, 
// if the following rules are followed:
// 	- The cipher-text C is a string ends with '$' character.
// 	- Every word, w[i] in w[], should be a substring of C, and 
// 	the substring should have $ at the end of it.

// Your task is to help Mr Suresh to find the shortest Cipher C,  
// and return its length.

// Input Format:
// -------------
// Single line of space separated words, w[].

// Output Format:
// --------------
// Print an integer result, the length of the shortest cipher.


// Sample Input-1:
// ---------------
// kmit it ngit

// Sample Output-1:
// ----------------
// 10

// Explanation:
// ------------
// A valid cipher C is "kmit$ngit$".
// w[0] = "kmit", the substring of C, and the '$' is the end character after "kmit"
// w[1] = "it", the substring of C, and the '$' is the end character after "it"
// w[2] = "ngit", the substring of C, and the '$' is the end character after "ngit"


// Sample Input-2:
// ---------------
// ace

// Sample Output-2:
// ----------------
// 4

// Explanation:
// ------------
// A valid cipher C is "ace$".
// w[0] = "ace", the substring of C, and the '$' is the end character after "ace"


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

struct compare {
    inline bool operator()(const std::string& first,
            const std::string& second) const
    {
        return first.size() > second.size();
    }
};

int main(){
    string p,k;
    getline(cin,p);
    vector<string> inp;
    istringstream obj(p);
    while(obj>>k){
        inp.push_back(k);
    }
    compare c;
    sort(inp.begin(),inp.end(),c);
    int ans = 0;
    Trie trie = Trie();
    for(auto it:inp){
        if(trie.checkString(it)==false){
            // insert all suffix as prefix
            int le = it.size();
            for(int i=1;i<=le;++i){
                string temp = it.substr(le-i,le);
                trie.insert(temp);
            }
            ans += it.size()+1;
        }
    }
    cout<<ans;
    return 0;
}