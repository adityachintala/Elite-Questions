//There are N computers in a network, all the computers are connected as tree 
// structure. And one new connection is added in the Network. The computers in 
// the network are identified with their IDs, the IDs are numbered between 1 to N.

// The connections in the network is given as coonection[i] = [comp-A, comp-B], 
// there is a connection between comp-A and comp-B.

// Your task is to remove a connection in the network and print it, so that 
// all the computers are connected as tree structure. If there are multiple 
// options to remove, remove the connection that occurs last in the input.


// Input Format:
// -------------
// Line-1: Two space separated integers N, number of computers.
// Next N lines: Two space separated integers, comp-A & comp-B.

// Output Format:
// --------------
// Print the connection which is removed.


// Sample Input-1:
// ---------------
// 6
// 1 2
// 3 4
// 3 6
// 4 5
// 5 6
// 2 3

// Sample Output-1:
// ---------------
// 5 6


// Sample Input-2:
// ---------------
// 4
// 1 2
// 2 3
// 3 4
// 2 4

// Sample Output-2:
// ---------------
// 2 4

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
    int n;
    cin>>n;
    DSU dsu = DSU(n*n);
    int a1=0,a2=0;
    for(int i=0;i<n;++i){
        int a,b;
        cin>>a>>b;
        if(dsu.findRoot(a)!=dsu.findRoot(b)){
            dsu.Union(a,b);
        }
        else{
            a1=a;
            a2 = b;
        }
    }
    cout<<a1<<" "<<a2<<endl;
    return 0;
}
