/*
 Vihaar is working with strings. 
He is given two strings A and B, and another string T,
where the length of A and B is same.
You can find the relative groups of letters from A and B,
using the following rule set:
- Equality rule: 'p' == 'p'
- Symmetric rule: 'p' == 'q' is same as 'q' == 'p'
- Transitive rule: 'p' == 'q' and 'q' == 'r' indicates 'p' == 'r'.
Vihaar has to form the relatively smallest string of T,
using the relative groups of letters.
For example, if A ="pqr" and B = "rst" , 
then we have 'p' == 'r', 'q' == 's', 'r' == 't' .
The relatives groups formed using above rule set are as follows: 
[p, r, t] and [q,s] and  String T ="tts", then relatively smallest string is "ppq".
You will be given the strings A , B and T.
Your task is to help Vihaar to find the relatively smallest string of T.
Input Format:
-------------
Three space separated strings, A , B and T
Output Format:
--------------
Print a string, relatively smallest string of T.
Sample Input-1:
---------------
kmit ngit mgit
Sample Output-1:
----------------
ggit
Explanation: 
------------
The relative groups using A nd B are [k, n], [m, g], [i], [t] and
the relatively smallest string of T is "ggit"
Sample Input-2:
---------------
attitude progress apriori
Sample Output-2:
----------------
aaogoog
Explanation: 
------------
The relative groups using A nd B are [a, p], [t, r, o], [i, g] and [u, e, d, s]
the relatively smallest string of T is "aaogoog"
 */


#include<bits/stdc++.h>
using namespace std;

class DSU
{   
    public:
    vector<int> parent;

    DSU(int n){
        parent.resize(n,-1);
    }
    
    int findRoot(int node){
        if(parent[node] == -1){
            return node;}
        return (parent[node] = findRoot(parent[node]));
    }
 
    void Union(int node1 , int node2){
        int ra = findRoot(node1);
        int rb = findRoot(node2);
        if(ra != rb){
            if(ra < rb){
                parent[rb] = ra;
            }
            else{
                parent[ra] = rb;
            }
        }
    }
};


int main(){
    string a,b,c;
    cin>>a>>b>>c;
    int n = a.size()*2;
    DSU dsu = DSU(26*26);

    for(int i=0;i<a.size();++i){
        int aa = a[i] - 'a';
        int bb =b[i] - 'a';
        dsu.Union(aa,bb);
    }
    string res = "";
    for(auto it:c){
        int ff = dsu.findRoot(it-'a');
        res += char(ff)+'a';
    }
    cout<<res<<endl;
    return 0;
    
}
