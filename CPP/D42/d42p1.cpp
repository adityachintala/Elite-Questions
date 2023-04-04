/*

Brahmi and his gang was chased by group of police officers, unfortunately 
they all got locked up in a building consist of M*N rooms in the form of 
a grid. All the rooms are connected with  the adjacent rooms both horizontally
and vertically. There are few rooms for them to escape called as safe zones. 

Now help Brahmi and his gang to reach the safe zones in the building.

In the Building we have the rooms filled with following values: [0,-1,-2] 
where, -1 -> Danger zone (they should not enter into it).
0 -> Safe Zone (room to escape)
-2 -> a thief

Now create a method to print the grid after performing following step: 
Fill each room with one of the member from The Brahmi and his gang with 
the distance to its nearest safe zone.
If it is impossible to reach a safezone, fill with '-2' only.

Input Format:
-------------
Line-1 -> two integers M and N, size of the grid of rooms.
Next M Lines -> N space separated integers, from this set [-2,-1,0] only.

Output Format:
--------------
Print an integer as result.


Sample Input-1:
---------------
4 4
-2 -1 0 -2
-2 -2 -2 -1
-2 -1 -2 -1
0 -1 -2 -2

Sample Output-1:
----------------
3 -1 0 1
2 2 1 -1
1 -1 2 -1
0 -1 3 4





*/



#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int> (m,0));
    vector<vector<int>> vis(n,vector<int> (m,false));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>grid[i][j];
            if(grid[i][j]>=-1){
                vis[i][j]=true;
            }
        }
    }
    queue<vector<int>> q;
    vector<int> dirs = {1,0,-1,0,0,1,0,-1};
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(grid[i][j]==0){
                q.push({i,j,0});
            }
        }
    }
    while(!q.empty()){
        auto top = q.front();q.pop();
        vis[top[0]][top[1]]=true;
        for(int i=0;i<4;++i){
            int newx=top[0]+dirs[i], newy = top[1]+dirs[i+4];
            if(newx>=0 && newy>=0 && newx<n && newy<m && vis[newx][newy]==false){
                if(grid[newx][newy]==-2){
                    grid[newx][newy]=top[2]+1;
                    q.push({newx,newy,top[2]+1});
                }
                if(grid[newx][newy]>top[2]+1){
                    grid[newx][newy]=top[2]+1;
                    q.push({newx,newy,top[2]+1});
                }
            }
        }

    }

    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cout<<grid[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}