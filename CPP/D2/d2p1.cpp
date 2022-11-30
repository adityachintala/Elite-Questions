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
