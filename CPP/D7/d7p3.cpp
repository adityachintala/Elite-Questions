// Arjun wants to build some homes in a land of size R*C.
// He wanted to construct homes in rectangular shape.
// The place which is remained will be used for gradening.
// Accordingly he has prepared the plan and given as
// an 2d array plan[][], where 1 indicates home, and 0 indicates garden area.

// A home is set of cells with value 1 in rectangular shape.
// He wants to findout all the homes in the plan and store their co-ordinates in 
// the following order, coords[i] = [x1,y1,x2,y2], where (x1,y1) is the starting
// co-ordinate (top left corner), and (x2,y2) is the ending co-ordinate 
// (bottom right corner) of i-th home.

// Your task is to help Arjun to find all the homes and return the coords[][] of 
// all the homes from top left corner to bottom right corner.

// NOTE: No two homes are adjacent to each other in 4 directions,
// (left, right, top, bottom).

// Input Format:
// -------------
// Line-1: Two integers R and C, size of the land.
// Next R lines: C space separated integers, either 0 or 1
// 0- represents garden area land and 1- represents the home.

// Output Format:
// --------------
// Print 2d array, the co-ordinates of all homes.


// Sample Input-1:
// ---------------
// 2 3
// 1 0 0
// 0 1 1
 
// Sample Output-1:
// ----------------
// [0, 0, 0, 0][1, 1, 1, 2]


// Sample Input-2:
// ---------------
// 4 4
// 1 1 0 1
// 0 0 0 0
// 1 1 0 1
// 1 1 0 1
 
// Sample Output-2:
// ----------------
// [0, 0, 0, 1][0, 3, 0, 3][2, 0, 3, 1][2, 3, 3, 3]


#include<bits/stdc++.h>
using namespace std;

vector<int> dir = {0,1,0,-1,0};


void dfs(vector<vector<int>>& grid,int i,int j,int& endx,int& endy,int m,int n){
    if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==0){
        return;
    }
    grid[i][j]=0;
    for(int i1=0;i1<4;++i1){
        int newx = dir[i1]+i, newy = dir[i1+1]+j;
        if(newx >= endx){
                endx = newx;
                endy = max(endy,newy);
        }
        dfs(grid,newx,newy,endx,endy,m,n);
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int> (m,0));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>grid[i][j];
        }
    }
    vector<vector<int>> ans;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(grid[i][j]==1){
                int endx=i,endy=j;
                dfs(grid,i,j,endx,endy,m,n);
                ans.push_back({i,j,endx-1,endy-1});
            }
        }
    }
    for(auto it:ans){
        cout<<'[';
        for(int j=0;j<it.size();++j){
            cout<<it[j];
            if(j!=it.size()-1){
                cout<<", ";
            }
        }
        cout<<']';
    }
    return 0;
}