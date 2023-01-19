// Students are asked to stand in the ground in rows and cols with their roll numbers. 
// Given this you have to sort each matrix diagonal in ascending order of their 
// roll numbers

// A Matrix diagonal is a diagonal line of cells starting from some cell in 
// either the topmost row or leftmost column and going in the bottom-right 
// direction until reaching the matrix's end.
 
// For example, the matrix diagonal starting from mat[2][0], where mat is 
// a 6 x 3 matrix, includes cells mat[2][0], mat[3][1], and mat[4][2].

// Input Format
// -------------
// Line1: M, N integers representing row and col size
// Line2: space separated integers of size M*N

// Output Format
// -------------
// space separated integers  of size M*N


// Sample Input1:
// 3 4 
// 3 3 1 1
// 2 2 1 2
// 1 1 1 2
// Sample Output1: 
// 1 1 1 1
// 1 2 2 2
// 1 2 3 3
        

// Sample Input2:   
// 5 6
// 11 25 66 1 69 7
// 23 55 17 45 15 52
// 75 31 36 44 58 8
// 22 27 33 25 68 4
// 84 28 14 11 5 50

// Sample Output2:
// 5 17 4 1 52 7
// 11 11 25 45 8 69
// 14 23 25 44 58 15
// 22 27 31 36 50 66 
// 84 28 75 33 55 68


#include<bits/stdc++.h>
using namespace std;

void sortdiagnol(vector<vector<int>> &grid,int i,int j,int n,int m){
    vector<int> temp;
    int i1=i,j1=j;
    while(i1<n && j1<m){
        temp.push_back(grid[i1][j1]);
        i1++;j1++;
    }
    sort(temp.begin(),temp.end());
    for(auto it:temp){
        grid[i][j]=it;
        j++;i++;
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
    for(int r=n-1;r>=0;r--){
        sortdiagnol(grid,r,0,n,m);
    }
    for(int c=0;c<m;c++){
        sortdiagnol(grid,0,c,n,m);
    }
    for(auto it:grid){
        for(auto j:it){
            cout<<j<<' ';
        }
        cout<<endl;
    }
    return 0;
}
