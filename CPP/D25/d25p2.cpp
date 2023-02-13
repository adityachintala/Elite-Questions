// Sridhar brought his latest Apple iPhone 12 pro. He started his conversation 
// with one of his friend on WhatsApp with list of words.

// Now it’s our task to find and return what are the most common words 
// in the list of words he used in sorted order based on occurrence from 
// largest to smallest. If any of words he used are having same occurrence 
// then consider the lexicographic order.

// You will be given a list of words, you need to print top P number of 
// most common used words as described in the statement. 

// Input Format:
// -------------
// Line-1: comma separated line of words, list of words.
// Line-2: An integer P, number of words to display. 

// Output Format:
// --------------
// Print P number of most common used words.


// Sample Input-1:
// ---------------
// ball,are,case,doll,egg,case,doll,egg,are,are,egg,case,are,egg,are,case
// 3

// Sample Output-1:
// ----------------
// [are, case, egg]



// Sample Input-2:
// ---------------
// ball,are,case,doll,egg,case,doll,egg,are,are,egg,case,are,egg,are
// 3

// Sample Output-2:
// ----------------
// [are, egg, case]


#include<bits/stdc++.h>
using namespace std;

class Trie{
public:
    vector<Trie*> children;
    bool isEnd;
    bool vis;
    int count;
    Trie* root;
    Trie()
    {
        vis = false;
        count = 0;
        isEnd = false;
        children.resize(26);
        root = nullptr;
    }
    void insert(string key)
    {
        if(root == nullptr) root = new Trie();
        Trie* temp = root;
        int n = key.length();
        for(int i=0; i<n; i++)
        {
            int ind = key[i] - 'a';
            if(temp->children[ind] == nullptr) temp->children[ind] = new Trie();
            temp = temp->children[ind];
        }
        temp->count++;
        temp->isEnd = true;
    }
    int search(string key)
    {
        int n = key.length();
        Trie* temp = root;
        for(int i=0; i<n; i++)
        {
            int ind = key[i] - 'a';
            temp = temp->children[ind];
        }
        if(temp->vis == true) return -1;
        temp->vis = true;
        return temp->count;
    }
};

struct problem {
    int val;
    string s;
    problem(string str, int v) :  s(str),val(v) {}
};

auto cmp = [](problem a, problem b) {
    if (a.val == b.val) return a.s > b.s;
    return a.val < b.val;
};

int main(){
    string s;
    cin>>s;
    vector<string> arr;
    string x="";
    for(int i=0;i<s.size();i++){
        if(s[i]==','){
            arr.push_back(x);
            x="";
            continue;
        }
        x+=s[i];
        if(i==s.size()-1){
            arr.push_back(x);
            x="";
        }
    }
    int k;
    cin>>k;
    Trie node;
    for(string s:arr){node.insert(s);}
    priority_queue<problem, vector<problem>, decltype(cmp)> pq(cmp);
    for(auto s:arr)
    {
        int val = node.search(s);
        if(val == -1) continue;
        problem p(s, val);
        pq.push(p);
    }
    vector<string> res;
    for(int i=0;i<k;++i)
    {
        problem p = pq.top();
        pq.pop();
        res.push_back(p.s);
    }
    for(auto it:res){
        cout<<it<<' ';
    }
    return 0;
}