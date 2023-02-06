// Chitti(ROBO) is busy in turning the people into chittis(ROBOS) by surrounding them.
// In a room there are n*n boxes occupied by ROBOS and people.
//    1.A person will be turned into ROBO if he is surrounded by all ROBOs. 
//    2.A person will not be turned into ROBO if he is on the edge of the room
//      and all the connected people to him (directly or indirectly) are also not to be turned.
//  Return the n*n boxes after conversion.
 
// Input Format
// -------------
// Line-1:integer n represent the n*n boxes of the room..
// Next n lines:Each line of string consists of combination of 'X'(represents ROBO) and 'O'(represents a person)
   
// Output Format:
// --------------
// Print n*n space seperated values after conversion.
  
   
// Sample Input-1:
// ---------------
// 4
// XXXX
// XOOX
// XXOX
// OXXX
   
// Sample Output-1:
// ----------------
// X X X X 
// X X X X 
// X X X X 
// O X X X 
   
// Explanation:
// ------------
// The people at second row and third row are converted to ROBOs as they are surrounded by ROBOs.
// But the person at fourth row is safe as he is on edge.
  
   
// Sample Input-2:
// ---------------
// 5
// XOOOX
// XXXXX
// XOXXX
// XXXOX
// OXXXX
  
// Sample Output-2:
// ----------------
// X O O O X 
// X X X X X 
// X X X X X 
// X X X X X 
// O X X X X 


#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>> &grid,int r,int c,int n){
    if(r<0||c<0||r>=n||c>=n||grid[r][c]=='X'||grid[r][c]=='Y'){
        return;
    }
    grid[r][c]='Y';
    dfs(grid,r+1,c,n);
    dfs(grid,r,c+1,n);
    dfs(grid,r-1,c,n);
    dfs(grid,r,c-1,n);
}

int main(){
    int n;
    cin>>n;
    vector<vector<char>> grid(n,vector<char>(n,'O'));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    for(int i=0;i<n;i++){
        if(grid[i][0]=='O'){
            dfs(grid,i,0,n);
        }
        if(grid[i][n-1]=='O'){
            dfs(grid,i,n-1,n);
        }
    }
    for(int i=0;i<n;i++){
        if(grid[0][i]=='O'){
            dfs(grid,0,i,n);
        }
        if(grid[n-1][i]=='O'){
            dfs(grid,n-1,i,n);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='O'){
                grid[i][j]='X';
            }
            if(grid[i][j]=='Y'){
                grid[i][j]='O';
            }
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}