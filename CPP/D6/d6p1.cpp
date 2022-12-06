// Ibrahim is an interior designer wants to color wall of size M*N. 
// He plans to color the wall and put lights of two different colors

// The designer can lit the wall using M*N lights.The lights are Blue or pink
// in color.Blue colored lights represented with digit-1 and pink colored lights 
// represented with digit-0.

// The Blue colored lights forms different shapes, that are connected 4 directonally.
// The directons are upwards, downwards, left, and right. Ibrahim got an idea to 
// count the unique shapes formed by blue colored lights.

// You will be given the decorated wall as a matrix wall[][].
// Your task is to help Ibrahim to count the unique shapes by the lights.

// Input Format:
// -------------
// Line-1: Two space separated integers M and N, size of the wall.
// Next M lines: N space separated integers, either 0 or 1.

// Output Format:
// --------------
// Print an integer, Number of distinct shapes formed by Blue Lights.


// Sample Input-1:
// ---------------
// 4 5
// 1 1 0 1 1     
// 1 1 0 0 1
// 0 0 0 0 0
// 1 1 0 0 0

// Sample Output-1:
// ----------------
// 3


// Sample Input-2:
// ---------------
// 5 5
// 1 1 0 1 1
// 1 0 0 0 1
// 0 0 0 0 0
// 1 0 0 0 1
// 1 1 0 1 1

// Sample Output-2:
// ----------------
// 4

// Note: 
// -------
// The shapes, 
// 1 1  		  1 1
// 1      and             1



#include<bits/stdc++.h>
using namespace std;



bool dfs(int i, int j, int x, int y, vector<vector<int>> & grid, int m, int n, vector<vector<int>> & island,vector<int> d){
    if(x < 0 or x >= m or y < 0 or y >= n or grid[x][y] <= 0) return false;
    grid[x][y] *= -1;
    island.emplace_back(x-i, y-j);
    for(int k = 0; k < 4; k++){
        dfs(i, j, x + d[k], y + d[k + 1], grid, m, n, island,d);
    }

    return true;
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
    set<vector<vector<int>>> distinctIslands;
    vector<int> d = {0,1,0,-1,0};
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j++){
            vector<vector<int>> island;
            if (dfs(i, j, i, j, grid, n, m, island,d)){
                distinctIslands.insert(island);
            }
        }
    }
    cout<<distinctIslands.size();

    return 0;
}
