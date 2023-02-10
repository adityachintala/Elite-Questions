// Ananth interested in creating the acronyms for any word. The definition
// of acronym is another word with a concatenation of its first letter,
// the number of letters between the first and last letter, and its last letter. 
 
// If a word has only two characters, then it is an acronym of itself.

// Examples:
//     - Acronym of 'fog' is f1g'.
//     - Acronym of 'another' is 'a5r'.
//     - Acronym of 'ab' is 'ab'.

// You are given a list of vocabulary, and another list of words.
// Your task is to check,each word with the vocabulary and
// return "true" if atleast one of the following rules satisfied:
// 1. acronym of the word should not match with any of the acronyms of vocabulary
// 2. if acronym of the word matches with any of the acronyms of vocabulary
// 'the word' and matching words in vocabulary should be same.

// Otherwise, return 'false'.

// Input Format:
// -------------
// Line-1: Space separated strings, vocabulary[] 
// Line-2: Space separated strings, words[] 

// Output Format:
// --------------
// Print N boolean values, where N = words.length 


// Sample Input-1:
// ---------------
// cool bell cool coir move more mike
// cool char move 

// Sample Output-1:
// ----------------
// true false false


#include<bits/stdc++.h>
using namespace std;

string solve(string s,vector<string> voc){
    int n=s.size()-1;
    for(string x:voc){
        int m=x.size()-1;
        if(s.size()==x.size() && (s[0]==x[0]) && (s[n]==x[m]) && !(s==x)) return "false";
    }
    return "true";  
}

int main(){
    vector<string> voc;
    vector<string> words;
    string s;
    getline(cin,s);
    string x="";
    istringstream obj(s);
    while(obj>>x){
        voc.push_back(x);
    }
    //cin.ignore();
    getline(cin,s);
    istringstream obj1(s);
    while(obj1>>x){
        words.push_back(x);
    }

    for(int i=0;i<words.size();i++){
        cout<<solve(words[i],voc)<<" ";
    }
}