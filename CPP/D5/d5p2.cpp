// A transitive law is "If a == b and b == c, then a == c"
// Which also says "If a == b and b != c, then a != c"

// You will be given a list of strings relations[], i.e, like p==q or p!=q.
// Your task is to find out whether all the relations follow the transitive law or not.
// If all of them followed return true, otherwise return false.

// Input Format:
// -------------
// Space separated strnigs, list of relations

// Output Format:
// --------------
// Print a boolean value, whether transitive law is obeyed or not.


// Sample Input-1:
// ---------------
// a==b c==d c!=e e==f

// Sample Output-1:
// ----------------
// true


// Sample Input-2:
// ---------------
// a==b b!=c c==a

// Sample Output-2:
// ----------------
// false


// Sample Input-3:
// ---------------
// a==b b==c c!=d d!=e f==g g!=d

// Sample Output-3:
// ----------------
// true



#include<bits/stdc++.h>
using namespace std;

class DSU
{   
    public:
    vector<int> parent;
    vector<int> height;
    vector<int> size;

    DSU(int n){
        parent.resize(n,-1);
        size.resize(n,1);
        height.resize(n,1);
    }
 
    int findRoot(int node){
        if(parent[node] == -1){
            return node;}
        return (parent[node] = findRoot(parent[node]));
    }
 
    int Union(int node1 , int node2){
        int ra = findRoot(node1);
        int rb = findRoot(node2);
        if(ra != rb){
            if(height[ra] < height[rb]){
                parent[ra] = rb;
                size[rb] += size[ra];
                return size[rb];
            }
            else if(height[rb] < height[ra]){
                parent[rb] = ra;
                size[ra] += size[rb];
                return size[ra];
            }
            else{
                parent[rb] = ra;
                height[ra] ++;
                size[ra] += size[rb];
                return size[ra];
            }
        }
        return -1;
    }
};

int main(){
    string s;
    vector<string> eq;
    getline(cin,s);
    istringstream obj(s);
    string d;
    while(obj>>d){
        eq.push_back(d);
    }
    int n = eq.size();
    DSU dsu = DSU((n*2)*(n*2));
    int possible =1;
    for(auto it:eq){
        char f = it[0], l = it[3];
        int equals=1;
        if(it[1]=='!'){
            equals=0;
        }
        if(equals==1){
            int n1=f-'a',n2=l-'a';
            dsu.Union(n1,n2);
        }
    }
    for(auto it:eq){
        char f = it[0], l = it[3];
        int equals=1;
        if(it[1]=='!'){
            equals=0;
        }
        if(equals==0){
            int n1=f-'a',n2=l-'a';
            if(dsu.findRoot(n1)==dsu.findRoot(n2)){
                possible = false;
                break;
            }
        }
    }
    if(possible==1){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    return 0;
}