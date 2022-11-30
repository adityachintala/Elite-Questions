// Prabhath is working on words.  He used to take out every letter that was repeated 
// in the word. 
// A word W is given to Prabhath. His objective is to eliminate every duplicate 
// letter from W such that the resultant word R contains every unique letter from W
// and did not contain any duplicate letters. 
// And R should be at the top of the dictionary order.

// NOTE:
// -----
// He is not allowed to shuffle the relative order of the letters of the word W to
// form the word R.

// Input Format:
// -------------
// A String, the word W.

// Output Format:
// --------------
// Print a String, resultant word R.


// Sample Input-1:
// ---------------
// cbadccb
// c

// Sample Output-1:
// ----------------
// adcb


// Sample Input-2:
// ---------------
// silicosis

// Sample Output-2:
// ----------------
// ilcos


#include<bits/stdc++.h>
using namespace std;

int main(){    
    string s;
    cin>>s;
    vector<unsigned int> cnt(26,0);
    vector<bool> inRes(26, false);
    for(char ch:s) cnt[ ch-'a' ]++;
    string res = ""; //use res as a stack
    for(char ch:s){
       cnt[ ch-'a' ]--;
       if(res.empty()){ 
           res.push_back(ch);
           inRes[ ch-'a' ] = true;
           continue;
       }
       if(inRes[ch-'a']) continue;
       while(ch<res.back() && !res.empty() && cnt[ res.back()-'a' ]>0){
           inRes[ res.back()-'a' ] = false;
           res.pop_back();
           
       }
       res.push_back(ch);
       inRes[ ch-'a' ] = true;
    }
    cout<<res<<endl;
}