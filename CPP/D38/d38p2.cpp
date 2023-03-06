/*

Clavius, the person who suggested grouping of data using brackets.
He has suggested that the group of brackets should be Well-Formed.

A string is said to be Well-Formed, if:
    - The string is empty.
    - The string can be written as MN, (M is appended to N), 
      where M and N are Well-Formed Strings, or
    - The string can be written as {M}, where M is Well-Formed string.

You will be given an integer N. Your task is to return the list of all 
Well-Formed strings of length 2*N.

Input Format:
-------------
An integer N.

Output Format:
--------------
Print the list of well-formed strings.


Sample Input-1:
---------------
3

Sample Output-1:
----------------
[{{{}}},{{}{}},{{}}{},{}{{}},{}{}{}]


Sample Input-2:
---------------
1

Sample Output-2:
----------------
[{}]


*/

#include<bits/stdc++.h>
using namespace std;

void help(int o,int c,vector<string>&v,string cur){
    
    if(o==0 && c==0){
        v.push_back(cur);
        return;
    }
   
    
    if(o>0){
        cur.push_back('{');
        help(o-1,c,v,cur);
        cur.pop_back();
    }
    if(c>o){
        cur.push_back('}');
        help(o,c-1,v,cur);
        cur.pop_back();
    }
}

int main(){
    
    int n;cin>>n;
    string cur="{";
    int open=n-1;
    int close=n;
    
    vector<string>v;
    
    help(open,close,v,cur);
    
    for(auto i:v){
        cout<<i<<" ";
    }
}