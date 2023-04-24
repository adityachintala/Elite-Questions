/*

A merchant has two types of idols, gold and silver.
He has arranged the idols in the form of m*n grid, 
	- the gold idols are represented as 1's 
	- the silver idols are represented as 0's.

Your task is to find the longest consecutive arrangement of gold idols, 
The arrangement can be either horizontal, vertical, diagonal or 
antidiagonal, but not the combination of these.


Input Format:
-------------
Line-1: Two space separated integers m and n, grid size.
Next m lines : n space separated integers, arrangement of idols.

Output Format:
--------------
Print an integer, longest arranement of gold idols.


Sample Input:
---------------
4 5
1 0 1 1 1
0 1 0 1 0
1 0 1 0 1
1 1 0 1 1

Sample Output:
----------------
4



*/



#include<bits/stdc++.h>
using namespace std;

int main(){
    int r,c;
    cin>>r>>c;
    vector<vector<int>> grid(r,vector<int>(c,0));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(4,0)));
    int res=0;
    for(int i = 0 ; i < r ; i++){
        for(int j = 0; j < c ; j++){
            if(grid[i][j] == 1){
                dp[i][j][0] = 1;
                dp[i][j][1] = 1;
                dp[i][j][2] = 1;
                dp[i][j][3] = 1;
                if(i > 0){
                    dp[i][j][0] += dp[i-1][j][0];
                    res = max(res,dp[i][j][0]);
                }
                if(j > 0){
                    dp[i][j][1] += dp[i][j-1][1];
                    res = max(res,dp[i][j][1]);
                }
                if(i > 0 && j > 0){
                    dp[i][j][2] += dp[i-1][j-1][2];
                    res = max(res,dp[i][j][2]);
                }
                if(i > 0 && j < c - 1){
                    dp[i][j][3]  += dp[i-1][j+1][3];
                    res = max(res,dp[i][j][3]);
                }
            }
        }
    }
    cout<<res<<endl;
}