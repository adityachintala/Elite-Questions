// Jason Statham is a well known transporter.
// He transports goods from one place to other place using his container.
// The container is divided into M*N slots, you can place M*N items in it.
// In the container few slots are closed, you can't use them.
// No other item can move from it.

// When the items are loaded the container looks like an M*N grid, 
// but to unload the items from the container it is turned 90-derees clockwise.
// So, the Items in the container moves through the empty slots and set one on one.
// If there is an closed slot, the items will be fall on the closed slot.

// You will be given a matrix of size M*N, consists of 3 letters [I,O,S]
// Where I indicates item, O indicates closed slot, S indicates empty slot.

// Your task is to help Jason Stathamto know the positions of items, empty slots and 
// closed slots after turning the container 90-degree clockwise.

// Input Format:
// -------------
// Line-1: Two space separated integers M and N, size of the container
// Next M lines: A string of length N, consists only 3 characters [I, O, S]

// Output Format:
// --------------
// Print a charcter matrix of size N*M as described in sample.


// Sample Input-1:
// ---------------
// 2 3
// ISI
// ISO

// Sample Output-1:
// ----------------
// SS
// II
// OI

// Explanation:
// ------------
// Look at hint for explanation.


// Sample Input-2:
// ---------------
// 3 6
// IIOSOS
// IIIOSS
// IIISIS

// Sample Output-2:
// ----------------
// SII
// SII
// IIO
// IOS
// ISO
// ISS

// Explanation:
// ------------
// Look at hint for explanation.


#include<bits/stdc++.h>
using namespace std;

void movedown(vector<vector<char>> & grid){
    for(int i=0;i<grid.size();++i){
        for(int j=0;j<grid[0].size();++j){
            if(grid[i][j]=='S'){
                int temprow = i-1;
                if(temprow>=0 && grid[temprow][j]=='O'){
                    continue;
                }
                while(temprow>=0){
                    if(grid[temprow][j]=='O'){
                        break;
                    }
                    swap(grid[temprow+1][j],grid[temprow][j]);
                    temprow--;
                }
            }
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> words;
    for(int i=0;i<n;++i){
        vector<char> temp;
        for(int j=0;j<m;++j){
            char xx;
            cin>>xx;
            temp.push_back(xx);
        }
        words.push_back(temp);
    }
    vector<vector<char>> newwords;
    for(int j=0;j<m;++j){
        vector<char> temp;
        for(int i=0;i<n;++i){
            temp.push_back(words[i][j]);
        }
        reverse(temp.begin(),temp.end());
        newwords.push_back(temp);
    }
    movedown(newwords);
    for(int i=0;i<newwords.size();++i){
        vector<char> it = newwords[i];
        for(auto j:it){
            cout<<j;
        }
        if(i!=newwords.size()-1){
            cout<<endl;
        }
    }
    return 0;
}