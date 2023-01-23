// AlphaCipher is a string formed from another string by rearranging its letters

// You are given a string S.
// Your task is to check, can any one of the AlphaCipher is a palindrome or not.

// Input Format:
// -------------
// A string S

// Output Format:
// --------------
// Print a boolean value.


// Sample Input-1:
// ---------------
// carrace

// Sample Output-1:
// ----------------
// true


// Sample Input-2:
// ---------------
// code

// Sample Output-2:
// ----------------
// false

#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int n=0;
    cin>>s;
    for(auto it:s){
        n = n^(1<<(it-'a'+1));
    }
    int steps=0;
    while(n){
        n = n&(n-1);
        steps++;
    }
    if(steps<=1){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}