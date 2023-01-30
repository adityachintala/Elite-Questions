// Given a matrix of 0's and 1's of dimension rows X cols.

// We could traverse from one element(row, col) to any other element(row + 1, col) or (row, col + 1).

// Print 'true' if there is any path from first element(0,0) of the matrix to the last element(rows - 1, cols - 1) 
// of the matrix that visits the same number of 1's and 0's.
// Print 'false' otherwise.


// Input Format
// -------------
// Line-1: Read two integers rows and cols(space separated).
// Line-2: Read the matrix of dimension rows X cols.

// Output Format
// --------------
// If the required path exist print 'true' otherwise 'false'.


// Sample input-1
// 3 4
// 0 1 1 0
// 0 0 0 0
// 0 0 1 0
// Sample output-1
// true

// Explanation: In the given matrix there is a path that is having three 0's and three 1's.

// Sample input-2
// 4 3
// 0 0 1
// 1 0 0
// 0 0 0
// 0 0 1
// Sample output-2
// false

// Explanation: There is NO path that is having same number of 0's and 1's.


#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>> grid,int i,int j,int n,int m,int count){
    if(i<0 || j<0 || i>=n || j>=m){
        return false;
    }
    if((i==(n-1) && j==(m-1))){
        if(grid[i][j]==1){
            return count+1==0;
        }
        else{
            return count-1==0;
        }
    }
    if((i==(n-1) && j==(m-1)) && count!=0 ){
        return false;
    }
    if(grid[i][j]==1){
        count++;
    }
    else{
        count--;
    }
    return dfs(grid,i+1,j,n,m,count) || dfs(grid,i,j+1,n,m,count);
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
    if(dfs(grid,0,0,n,m,0)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;
}