// Subodh is interested in playing with Strings,
// For a given String 'S', Subodh applies some rules to find the value of 'S'.
// The rules are as follows:
// 	- If it is a balanced [] has value 1
// 	- XY has value X + Y , where X and Y are balanced [] strings.
// 	- [Z] has score 2 * Z , where Z is a balanced parentheses string.
	
// Find out the value of given String and print it.

// Note: All the given strings are balanced

// Input Format:
// ----------------
// A String contains only '[', ']'


// Output Format:
// ------------------
// Print an integer as result.


// Sample Input-1:
// -------------------
// []

// Sample Output-1:
// ---------------------
// 1

// Sample Input-2:
// -------------------
// [[]]

// Sample Output-2:
// ---------------------
// 2

// Sample Input-3:
// -------------------
// [[][[]]]

// Sample Output-3:
// ---------------------
// 6


#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    stack<int> st;
    for(int i=0;i<s.length();++i){
        if(st.empty() || s[i]=='['){
            st.push(0);
        }
        else{
            int res=0;
            while(!st.empty() && st.top()!=0){
                int t = st.top();
                st.pop();
                res+=t;
            }
            st.pop();
            st.push(max(res*2,1));
        }
    }
    int res=0;
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    cout<<res;
    return 0;
}
