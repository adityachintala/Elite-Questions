// Mansood Ali participated in a treasure-hunt conatins N boxes in it.
// Each box is numbered from 0,1,2,3,...,N-1. 
// All the boxes are intially locked with the passcodes, except Box-0.
// The passcode is written in a envolope and marked with its concern box number.

// Each box in the treasure hunt contains a list of envelopes, which has 
// passcodes to open the other boxes. He can open the boxes in any order, 
// but he has to start from box-0 intially.

// The rule to win the treasure-hunt is to open all the boxes.
// Your task is to find out, whether Mansood Ali win the treasure hunt or not.
// If he win, print "Win", Otherwise, print "Lost"


// Input Format:
// -------------
// Line-1: An integer, number of boxes.
// Next N lines: space separated integers, box numbers.

// Output Format:
// --------------
// Print a string value, Win or Lost


// Sample Input-1:
// ---------------
// 5
// 1
// 2
// 3
// 4
// 3

// Sample Output-1:
// ----------------
// Win


// Sample Input-2:
// ---------------
// 4
// 1 3
// 3 0 1
// 2
// 0

// Sample Output-2:
// ----------------
// Lost


#include<bits/stdc++.h>
using namespace std;

void dfs(int i,vector<vector<int>>&adj,int n,vector<bool>&vis,int& cnt){
    if(vis[i]){
        return ;
    }
    vis[i] = true;
    cnt-=i;
    for(auto x: adj[i]){ 
        dfs(x,adj,n,vis,cnt); 
    }
}

int main(){
    int n;cin>>n;
    vector<vector<int>> adj(n,vector<int>());
    cin.ignore();
    for(int i=0;i<n;i++){
        string s;getline(cin,s);
        istringstream obj(s);
        int ch;
        while(obj>>ch){
            adj[i].push_back(ch);
        }
    } 
    vector<bool> vis(n,false);
    int cnt = n*(n-1)/2;
    dfs(0,adj,n,vis,cnt);
    if( cnt==0){
        cout<<"Win"<<endl;
    }else{
        cout<<"Lost"<<endl;
    }
}