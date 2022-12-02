// There are N people in a private party. Initially all are strangers to each other,
// and the people are identified by unique ID from 0 to N-1.

// In the party, whenever two persons (person-A and person-B) become friends, they 
// took a photo. Each of the photo has some information, photos[i]=[T-i, P-j,P-k],
// here T-i indicates time of the photo taken, P-j person with ID 'j', and 
// P-k indicates person with ID 'k'.

// Friendship is symmetric[i.e., If P-j is friend of P-k, then P-k is a friend of P-j].
// Additionally, if person-A is "a friend of person-B OR a friend of someone who is 
// friend of person-B", then person-A is friend of person-B.

// You are given L photos information, Your task is to find the earliest time 
// for which every person became friend with every other person in the party.
// If there is no such earliest time, return -1.


// Input Format:
// -------------
// Line-1: Two space separated integers, N and L.
// Next L lines: Three space separated integers, log[i], 0<=i<L.

// Output Format:
// --------------
// Print an integer result.


// Sample Input-1:
// ---------------
// 6 8
// 5 0 1
// 7 3 4
// 12 2 3
// 21 1 5
// 34 2 4
// 37 0 3
// 42 1 2
// 93 4 5

// Sample Output-1:
// ----------------
// 37


// Sample Input-2:
// ---------------
// 7 6
// 2 0 3
// 5 1 5
// 8 2 5
// 7 3 6
// 9 4 6
// 6 4 5

// Sample Output-2:
// ----------------
// 9



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
        int n,l;
    cin>>n>>l;
    vector<vector<int>> nums;
    for(int i=0;i<l;++i){
        int a,b,c;
        cin>>a>>b>>c;
        nums.push_back({a,b,c});
    }
    sort(nums.begin(),nums.end());
    DSU dsu = DSU(n*n);
    int time1 = 0;
    // debug(nums);
    for(auto it:nums){
        // debug(it)
        int person1 = it[1],person2=it[2], time=it[0];
        // debug(person1);
        // debug(person2);
        if(dsu.findRoot(person1)==dsu.findRoot(person2)){
            continue;
        }
        else{
            time1 = time;
            dsu.Union(person1,person2);
        }
    }
    cout<<time1<<endl;
    return 0;
}