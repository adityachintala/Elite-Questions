// A game show hosted by the famous anchor Suma in which the celebrities compete 
// with each other. The game show format is changed a bit, There are N celebrities 
// participated now. And all of them answered correctly for a given question.
// Now everyone got a chance to play the money board game.
// Where i-th player standing at i-th index position of the top, 
// and value of 'i' is 0 <= i < n.

// The money board is of size M*N, and N players has coins to drop from
// top of the money board. The money board is opened at top and bottom.

// Each cell in the board has a diagonal bar connecting two corners of the cell,
// that can redirect the coin to the rightside or to the leftside.

// - The bar that redirects the coin to the right, 
// connected from the top-left corner to the bottom-right corner, indicated by 1.
// - The bar that redirects the coin to the left, 
// connected from the top-right corner to the bottom-left corner, indicated by -1.

// The players drop their coins at the top of board. Each coin can get stuck 
// in the board or fall out of the bottom. A coin gets stuck if it hits a "V" 
// shaped pattern between two bars or if a bar redirects the coin into 
// either wall of the board.

// Your task is to find and return an array result[] of size N,
// where result[i] is the index that the coin falls out of at the bottom 
// after dropping the coin from the i-th index at the top, 
// or -1 if the coin gets stuck in the board.

// Input Format:
// -------------
// Line-1: Two space separated integer M and N, size of the board.
// Next M lines: N space separated integers

// Output Format:
// --------------
// Print an array result. 


// Sample Input-1:
// ---------------
// 5 5
// 1 1 1 -1 -1
// -1 -1 -1 1 -1
// 1 1 1 1 -1
// -1 -1 -1 -1 1
// -1 -1 -1 1 -1

// Sample Output-1:
// ----------------
// [-1, 0, -1, -1, -1]


// Sample Input-2:
// ---------------
// 5 5
// 1 1 1 1 1
// -1 -1 -1 -1 -1
// 1 1 1 1 1
// -1 -1 -1 -1 -1
// 1 1 1 1 1

// Sample Output-2:
// ----------------
// [1, 2, 3, 4, -1]

#include<bits/stdc++.h>
using namespace std;

int main(){
        int m,n;
    cin>>m>>n;
    vector<vector<int>> grid(m,vector<int> (n,0));
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            cin>>grid[i][j];
        }
    }
    vector<int> res;
    int rows = grid.size(),cols=grid[0].size();
    for(int ball=0;ball<cols;++ball){
        int currrow=0,currcol=ball;
        while(currrow<rows){
            int currval = grid[currrow][currcol];
            if(currval==1){
                int possible = 1;
                if(currcol!=cols-1){
                    if(grid[currrow][currcol+1]!=1){
                        possible=0;
                        break;
                    }
                }
                if(currcol==cols-1){
                    break;
                }
                currrow+=1;
                currcol+=1;
            }
            else{
                int possible = 1;
                if(currcol!=0){
                    if(grid[currrow][currcol-1]!=-1){
                        possible=0;
                        break;
                    }
                }
                if(currcol==0){
                    break;
                }
                currrow+=1;
                currcol-=1;
            }
        }
        if(currrow==rows){
            res.push_back(currcol);
        }
        else{
            res.push_back(-1);
        }
    }
    for(auto it:res){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}