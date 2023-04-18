/*


Somesh is working on Number Strings.
He got an idea to find the smallest possible number by 
deleting some digits from the number without changing 
the relative order of digits in it.

You will be given a integer String 'num', and an integer n.
Find the smallest number possible after deleting n digits from 'num'.

Note: If the number string 'num' turns to empty, print 0.

Input Format:
-------------
Line-1 : A string num, consist of digits only.
Line-2 : An integer n, number of digits to delete.

Output Format:
--------------
Print the smallest possible number.


Sample Input-1:
---------------
1432219
3

Sample Output-1:
----------------
1219

Explanation: 
------------
Delete the three digits 4, 3, and 2 to form the smallest number 1219.


Sample Input-2:
---------------
10200
1

Sample Output-2:
----------------
200

Explanation:
------------
Delete the leading 1 and the smallest number is 200. 
Note that the output must not contain leading zeroes.



*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    stack<char> st;
    for(auto it:s){
        if(k==0){
            st.push(it);
            continue;
        }
        while(!st.empty() && st.top() > it){
            st.pop();
            k--;
            if(k==0){
                break;
            }
        }
        st.push(it);
    }
    string ans = "";
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    while(ans[0]=='0'){
        ans = ans.substr(1);
    }
    cout<<ans;
    return 0;
}