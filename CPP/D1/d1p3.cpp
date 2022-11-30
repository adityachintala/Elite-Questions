/*
There are N cities, and M routes[], each route is a path between two cities.
routes[i] = [city1, city2], there is a travel route between city1 and city2.
Each city is numbered from 0 to N-1.
 
There are one or more Regions formed among N cities. 
A Region is formed in such way that you can travel between any two cities 
in the region that are connected directly and indirectly.
 
Your task is to findout the number of regions formed between N cities. 
 
Input Format:
-------------
Line-1: Two space separated integers N and M, number of cities and routes
Next M lines: Two space separated integers city1, city2.
 
Output Format:
--------------
Print an integer, number of regions formed.
 
 
Sample Input-1:
---------------
5 4
0 1
0 2
1 2
3 4
 
Sample Output-1:
----------------
2
 
 
Sample Input-2:
---------------
5 6
0 1
0 2
2 3
1 2
1 4
2 4
 
Sample Output-2:
----------------
1
 
Note: Look HINT for explanation.
*/

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
    int n,m;
    cin>>n>>m;
    DSU dsu = DSU(n * n);
    for(int i=0;i<m;++i){
        int a,b;
        cin>>a>>b;
        dsu.Union(a,b);
    }
    set<int> islands;
    for(int i=0;i<n;++i){
        islands.insert(dsu.findRoot(i));
    }
    cout<<islands.size()<<endl;
    return 0;
}
