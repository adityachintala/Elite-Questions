/*

Pramod is working on Strings consist of digits only. He wants to findout, 
whether the given string can form Fibonacci sequence or not.

A String can form a Fibonacci Sequence, if it contains at least 
three numbers, and numbers are in the following order:
first, second, third  = first + second, fourth = third + second, .. so on.

Return true, if the given string can form fibonacci sequence,
otherwise, return false.

Note: Numbers in the fibonacci sequence contains no leading 0's.
for example, 2, 03,5 or 2,3,05 or 02,3,5 are not valid.

Input Format:
-------------
A String consist of digits only

Output Format:
--------------
Print a boolean value as result.


Sample Input-1:
---------------
23581321

Sample Output-1:
----------------
true

Explanation: 
------------
Fibonacci Sequence is : 2, 3, 5, 8, 13, 21
2, 3, 2+3=5, 3+5=8, 5+8=13, 8+13=21.

Sample Input-2:
---------------
199100199

Sample Output-2:
----------------
true

Explanation: 
------------
Fibonacci Sequence is : 1 99 100 199
1, 99, 1+99=100, 99+100=199.


*/

#include<bits/stdc++.h>
using namespace std;

bool flag = false;

void backtrack(int ind, vector<int>& l, string s){
    if(ind == s.length()){
        if(l.size() >= 3) flag = true;
        return;
    }
    string sb = "";
    for(int i=ind;i<s.length();i++){
        sb += s[i];
        if(sb.length() >= 9) return;
        if(sb.length() > 1 && sb[0] == '0') continue;
        int val = stoi(sb);
        if(l.size() <= 1){
            l.push_back(val);
            backtrack(i+1,l,s);
            l.pop_back();
        }
        else{
            if(val == (l[l.size()-1] + l[l.size()-2])){
                l.push_back(val);
                backtrack(i+1,l,s);
                l.pop_back();
            }
        }
    }
}


int main(){
    string s;
    cin>>s;
    vector<int> temp;
    backtrack(0,temp,s);
    if(flag){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;
}