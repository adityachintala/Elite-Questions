// There are some cubes, and each cube has an alphabet (from A to Z) 
// printed on it. You can construct different, non-empty words using these 
// cubes and each of the word length should be 0 < length <= number of cubes.

// You are given a string of alphabets S, 
// Your task is to findout number of possible non-empty distinct words

// Input Format:
// -------------
// A string S, consist of A-Z letters only.

// Output Format:
// --------------
// Print an integer, number of possible non-empty distinct words.


// Sample Input-1:
// ---------------
// EGG

// Sample Output-1:
// ----------------
// 8

// Explanation:
// --------------
// The possible distinct words are "E", "G", "EG", "GG", "GE", "EGG", "GEG", "GGE".


// Sample Input-2:
// ---------------
// MADAM

// Sample Output-2:
// ----------------
// 89



#include<bits/stdc++.h>
using namespace std;

int factorial(int x){
    int mul=1;
    if(x<=0) return 1;
    while(x>0){
        //cout<<x<<" ";
        mul*=x;
        x--;
    }
    return mul;
}
int solve(int ht[]){
    int sum=0;
    for(int i=0;i<26;i++){
        if(ht[i]!=0){
            ht[i]--;
            sum++;
            sum+=solve(ht);
            ht[i]++;
        }
        else{
            sum+=0;
        }
    }
    return sum;
}

int main(){
    string s;
    cin>>s;
    int ht[26]={0};
    for(int i=0;i<s.size();i++){
        ht[s[i]-'A']++;
        //cout<<ht[s[i]]<<endl;   
    }
    cout<<solve(ht)<<endl;
}