/*

Given two strings S1 and S2, find if S2 can match S1 or not.

A match that is both one-to-one (an injection) and onto (a surjection), 
i.e. a function which relates each letter in string S1 to a separate and 
distinct non-empty substring in S2, where each non-empty substring in S2
also has a corresponding letter in S1.

Return true,if S2 can match S1.
Otherwise false.

Input Format:
-------------
Line-1 -> Two strings S1 and S2

Output Format:
--------------
Print a boolean value as result.


Sample Input-1:
---------------
abab kmitngitkmitngit

Sample Output-1:
----------------
true


Sample Input-2:
---------------
aaaa kmjckmjckmjckmjc

Sample Output-2:
----------------
true

Sample Input-3:
---------------
mmnn pqrxyzpqrxyz

Sample Output-3:
----------------
false





*/

#include<bits/stdc++.h>
using namespace std;
string s,g;
int n,m;
map<char,string> mpp;
set<string> st;
bool backtrack(int i,int j){
    if(i==n && j==m) return true;
    if(i==n || j==m) return false;
    if(mpp.count(s[i])==1){
        string req=mpp[s[i]];
        int len=req.length();
        if(req==g.substr(j,len)){
          if(backtrack(i+1,j+len)) return true;  
        } 
    }
    else{
        string temp="";
        for(;j<m;j++){
            temp.push_back(g[j]);
            if(st.count(temp)==0){
                mpp[s[i]]=temp;
                st.insert(temp);
                if(backtrack(i+1,j+1)) return true;
                st.erase(temp);
                mpp.erase(s[i]);
            }
        }
    }
    return false;
}
int main(){
    cin>>s>>g;
    n=s.length();
    m=g.length();
    bool ans=backtrack(0,0);
    if(ans==true){
        cout<<"true\n";
    }
    else{
        cout<<"false\n";
    }
    
}
