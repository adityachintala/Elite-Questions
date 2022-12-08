// In an exam hall, seating arrangement is done in a row, When an invigilator 
// enters into exam hall he wants to exchange(swap) some students places in pairs.

// Note: student names will be alphabets(a,b,c...z) may be repeated,
// and seat number starts from zero(0 to N-1) where N is the number of students.

// Invigilator may swap the students at any pair of seats(indices) in 
// the given pairs any number of times.

// Given the seating-arrangement s, and list of pairs of seats(indices) in 
// seating-arrangement pairs where pairs[i]=[x,y] denotes 2 indices 
// (index starts from zero(0)) of the seating-arrangement s.

// Your task is to print the lexicographically smallest seating-arrangement S
// that has been changed after using the swaps.


// Input Format:
// -------------
// Line-1: Read a String seating-arrangement s.
// Line-2: Read the number of pairs of seat numbers to swap R.
// Next R lines: Two space separated integers, pair of seat numbers.

// Output Format:
// --------------
// Print the lexicographically smallest seating-arrangement s after using the swaps.

// Sample Input-1:
// ---------------
// feabdc
// 2       
// 0 4
// 1 3

// Sample Output-1:
// ----------------
// dbaefc

// Explanation:
// ------------
// Swap s[0] and s[4], s = "deabfc"
// Swap s[1] and s[3], s = "dbaefc"

// Sample Input-2:
// ---------------
// edb
// 2
// 0 1
// 1 2

// Sample Output-2:
// ----------------
// bde

// Explanation:
// ------------
// Swap s[0] and s[1], s = "deb"
// Swap s[1] and s[2], s = "dbe"
// Swap s[0] and s[1], s = "bde"


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
    cin>>s;
    int n;
    cin>>n;
    int n1 = s.length();
    DSU dsu = DSU(n1*n1);
    for(int i=0;i<n;++i){
        int x,y;
        cin>>x>>y;
        dsu.Union(x,y);
    }
    unordered_map<int,vector<int>> mp;
    for(int i=0;i<n1;++i){
        mp[dsu.findRoot(i)].push_back(i);
    }
    for(auto it:mp){
        string temp="";
        for(int i:it.second){
            temp += s[i];
        }
        sort(temp.begin(),temp.end());
        int c = 0;
        for(int i:it.second){
            s[i]=temp[c++];
        }
    }
    cout<<s;
    return 0;
}