/*

Mr Ajay Sharma is working woth words.
He found that few words in the langugage have same meaning.
Such words are given as a list of pairs as mappedpairs[],
where mappedpairs[i] = [word1, word2] indicates that word1 and word2 are 
the words with same meaning.

He is given phrase, and he wants to apply all the mappedpairs[] on the phrase.

Your task is to help Mr.Ajay Sharma to find and return all possible 
Mapped Phrases generated after applying all the mapped words,
and print them in lexicographical order.


Input Format:
-------------
Line-1: An integer N, number of mapped pairs.
Next N lines: Two space separated words, mappedpair[].
Last Line: A line of words, the phrase.

Output Format:
--------------
Print the list of mapped phrases in sorted order.


Sample Input-1:
---------------
3
hi hello
sweet sugar
candy chocolate
hi sam! ram has a sugar candy

Sample Output-1:
----------------
[hello sam! he has sugar candy, hello sam! he has sugar chocolate, 
hello sam! he has sweet candy, hello sam! he has sweet chocolate, 
hi sam! he has sugar candy, hi sam! he has sugar chocolate, 
hi sam! he has sweet candy, hi sam! he has sweet chocolate]



Sample Input-2:
---------------
2
hi hey
hey hello
hi how are you

Sample Output-2:
----------------
[hello how are you, hey how are you, hi how are you]

*/

#include<bits/stdc++.h>
using namespace std;

class UnionFind {
    vector<int> id;
public:
    UnionFind(int N) : id(N) {
        iota(begin(id), end(id), 0);
    }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
    void connect(int a, int b) {
        id[find(a)] = find(b);
    }
};

int main(){
    int n;
    cin>>n;
    vector<vector<string>> A(n,vector<string>(2,""));
    for(int i=0;i<n;i++){
        cin>>A[i][0]>>A[i][1];
    }
    cin.ignore();
    string s;
    getline(cin,s);
    istringstream ss(s);
    string word;
    vector<string> v, tmp, ans;
    while (ss >> word) v.push_back(word);
    int id = 0;
    unordered_map<string, int> index;
    unordered_map<int, string> rindex;
    for (auto &syn : A) {
        if (index.count(syn[0]) == 0) {
            index[syn[0]] = id;
            rindex[id] = syn[0];
            ++id;
        }
        if (index.count(syn[1]) == 0) {
            index[syn[1]] = id;
            rindex[id] = syn[1];
            ++id;
        }
    }
    UnionFind uf(index.size());
    for (auto &syn : A) {
        uf.connect(index[syn[0]], index[syn[1]]);
    }
    unordered_map<int, set<string>> m;
    for (int i = 0; i < index.size(); ++i) {
        m[uf.find(i)].insert(rindex[i]);
    }
    function<void(int)> dfs = [&](int i) {
        if (i == v.size()) {
            string t;
            for (auto &w : tmp) {
                if (t.size()) t += ' ';
                t += w;
            }
            ans.push_back(t);
            return;
        }
        if (index.count(v[i])) {
            for (auto &syn : m[uf.find(index[v[i]])]) {
                tmp.push_back(syn);
                dfs(i + 1);
                tmp.pop_back();
            } 
        } else {
            tmp.push_back(v[i]);
            dfs(i + 1);
            tmp.pop_back();
        }
    };
    dfs(0);
    for(auto it:ans){
        cout<<it<<' ';
    }
    return 0;
}