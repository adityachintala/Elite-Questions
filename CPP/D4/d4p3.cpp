// Murali playing a mobile game, Blast the letters.

// In the game he is given a word W and value R.
// Murali has to perform the blasting operation as follows:
// 	- He has to blast the mimeograph M of length R in W, 
// 	  a mimeograph is a string such that each letter in it should be same.
// 	- After blasting the mimeograph, the rest of the string on its
// 	  left side and right side, concatenated together.

// Murali has to perform the blasting operation repeatedly, 
// until no more blasting is possible. Your task is to return 
// the final string after all the blast operations have been done.

// Input Format:
// -------------
// Line-1: A string and an integer, W and R.

// Output Format:
// --------------
// Print a string, the final string after all the blast operations have been done.


// Sample Input-1:
// --------------- 
// ababbaaab 3

// Sample Output-1:
// ----------------
// aba


// Sample Input-2:
// --------------- 
// caaabbbaacdddd 2

// Sample Output-2:
// ----------------
// cabc


#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int r;
    cin>>r;
    stack<pair<char,int>> st;
    for(int start=0;start<s.length();start++){
        if(st.empty() || st.top().first!=s[start]){
            st.push({s[start],1});
            continue;
        }
        if(st.top().first==s[start]){
            int count = st.top().second;
            st.pop();
            st.push({s[start],count+1});
        }
        if(st.top().second>=r){
            st.pop();
            continue;
        }
    }

    string res;
    while(!st.empty()){
        int count = st.top().second;
        while(count--){
            res += st.top().first;
        }
        st.pop();
    }
    reverse(res.begin(),res.end());
    cout<<res<<endl;
    return 0;
}