// In AMB mall, to attract kids and to increase their economy they setup 
// a separate Fun Zone. They opened a stall by name Soda Bears. We have an 
// LED display panel with different colours of Soda bears.

// You will be given a 2D integer panel representing the grid of a 
// Soda bears, we have different color-codes as positive integer in 
// panel [p][q] of each coloured soda bears. If a cell in 
// panel[p][q]=0 representing at position (p,q) is empty. 

// The given panel represents the state of game according to participants move. 
// Now it’s your aim to make panel to a stable state by merging Soda Bears 
// with certain conditions:

// 1. If three or more soda bears of the same colour are adjacent 
// vertically or horizontally,"merge" them all at the same time - 
// these locations become empty.

// 2. After merging all Soda Bears simultaneously, if an empty space on
// the panel has soda bears on top of itself, then these bears will drop
// until they hit another bear or bottom at the same time. 
// (No new soda bear will drop outside the top boundary.)

// 3. After the above steps, there may exist more bears that can be merged. 
// If so, you need to repeat the above steps.

// 4. If there does not exist more bears for merge (ie. the panel is stable), 
// then return the current panel.

// Repeat the procedure for stable panel, then return the current panel state.

// Input Format:
// -------------
// Line-1: Two space separated integers, M and N size of panel
// Next M lines: N space separated integers, color codes of soda bears.

// Output Format:
// --------------
// Print the stable format of panel.


// Sample Input-1:
// --------------
// 8 4
// 11 5 13 5
// 12 13 5 13
// 1 2 3 4
// 11 2 3 4
// 2 2 2 5
// 13 13 3 4
// 14 13 13 14
// 12 12 11 13

// Sample Output-1:
// ----------------
// 0 0 0 5
// 11 0 0 13
// 12 0 0 4
// 1 0 0 4
// 11 0 13 5
// 13 0 5 4
// 14 5 13 14
// 12 12 11 13


// Sample Input-2:
// --------------
// 7 8
// 1 1 1 1 1 1 1 1
// 2 1 1 1 1 1 1 2
// 3 2 1 1 1 1 2 3
// 4 3 2 1 1 2 3 4
// 3 2 1 1 1 1 2 3
// 2 1 1 1 1 1 1 2
// 1 1 1 1 1 1 1 1

// Sample Output-2:
// ----------------
// 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0
// 2 0 0 0 0 0 0 2
// 3 0 0 0 0 0 0 3
// 4 2 0 0 0 0 2 4
// 3 3 0 0 0 0 3 3


#include<bits/stdc++.h>
using namespace std;

set<pair<int,int>> unique_pts;

void movedown(vector<vector<int>> & grid){
    for(int i=0;i<grid.size();++i){
        for(int j=0;j<grid[0].size();++j){
            if(grid[i][j]==0){
                int temprow = i-1;
                while(temprow>=0){
                    swap(grid[temprow+1][j],grid[temprow][j]);
                    temprow--;
                }
            }
        }
    }
}

void makezeros(vector<vector<int>>& grid, set<pair<int,int>>& pts){
    for(auto it:pts){
        grid[it.first][it.second]=0;
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

    while(true){
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                int curr_pnt = grid[i][j];
                if(curr_pnt==0){
                    continue;
                }
                if(i>1 && i<n){
                    if(grid[i-1][j]==curr_pnt && grid[i-2][j]==curr_pnt){
                        unique_pts.insert({i,j});
                        unique_pts.insert({i-1,j});
                        unique_pts.insert({i-2,j});
                    }
                }
                if(i>=0 && i<n-2){
                    if(grid[i+1][j]==curr_pnt && grid[i+2][j]==curr_pnt){
                        unique_pts.insert({i,j});
                        unique_pts.insert({i+1,j});
                        unique_pts.insert({i+2,j});
                    }
                }
                if(j>1 && j<m){
                    if(grid[i][j-1]==curr_pnt && grid[i][j-2]==curr_pnt){
                        unique_pts.insert({i,j});
                        unique_pts.insert({i,j-1});
                        unique_pts.insert({i,j-2});
                    }
                }
                if(j>=0 && j<m-2){
                    if(grid[i][j+1]==curr_pnt && grid[i][j+2]==curr_pnt){
                        unique_pts.insert({i,j});
                        unique_pts.insert({i,j+1});
                        unique_pts.insert({i,j+2});
                    }
                }
            }
        }


        if(unique_pts.empty() || unique_pts.size()==0){
            break;
        }

        makezeros(grid,unique_pts);
        movedown(grid);
        if(!unique_pts.empty()){
            unique_pts.clear();
        }
    }

    for(auto it:grid){
        for(auto j:it){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}