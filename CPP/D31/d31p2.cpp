/*

Given a classic mobile phone, and the key pad of the phone looks like below.
	1		2		3
		   abc	   def
		 
	4		5		6
   ghi     jkl     mno
  
	7		8		9
  pqrs     tuv    wxyz
	
	*		0		#


You are given a string S contains digits between [2-9] only, 
For example: S = "2", then the possible words are "a", "b", "c".

Now your task is to find all possible words that the string S could represent.
and print them in a lexicographical order. 

Input Format:
-------------
A string S, consist of digits [2-9]

Output Format:
--------------
Print the list of words in lexicographical order.


Sample Input-1:
---------------
2

Sample Output-1:
----------------
[a, b, c]


Sample Input-2:
---------------
24

Sample Output-2:
----------------
[ag, ah, ai, bg, bh, bi, cg, ch, ci]

*/

#include<bits/stdc++.h>
using namespace std;

vector<string>s={".",".","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};


void help(vector<string>&ans,string digits,string&res,int i){
        
       
        if(i==digits.size()){ans.push_back(res);return;}
        
        int num=(digits[i]-'0');
        for(auto id:s[num]){
          res.push_back(id);
          help(ans,digits,res,i+1);
            res.pop_back();
        }
        
   
}


int main(){
    
    string s;cin>>s;
    
    string cur="";
    vector<string>p;
    
    help(p,s,cur,0);
    
    for(auto i:p){
        cout<<i<<" ";
    }cout<<endl;
    
    
}