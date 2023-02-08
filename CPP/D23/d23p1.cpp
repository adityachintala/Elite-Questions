// To get the admission into 6th standard in a reputed school in Hyderabad, 
// conducted an entrance test. one of the questions in the test was

// There was a sequence of characters(String) given, student has to check 
// in given String how many substrings are same as reverse of it (palindromic).

// Input Format:
// -------------
// Read a String.

// Output Format:
// --------------
// Print number of palindromic substrings of given string.



// Sample Input-1
// pqrs
// Sample Output-1
// 4

// Explanation: 
// "p", "q", "r", "s" are palindromic substrings of given string.


// Sample Input-2
// pppp
// Sample Output-2
// 10

// Explanation: 
// "p", "p", "p", "p", "pp", "ppp", "pppp", "pp", "ppp", "pp"  are 
// palindromic substrings of given string. 


#include<bits/stdc++.h>
using namespace std;

int possiblePalindrome(string& s, int i, int j, vector<vector<int>>& dp) {
    if (i >= j){
        return dp[i][j] = 1;
    }

    if (dp[i][j] != -1){
        return dp[i][j];
    }

    if (s[i] == s[j]){
        return dp[i][j] = possiblePalindrome(s, i + 1, j - 1, dp);
    }
    else{
        return dp[i][j] = 0;
    }
}

int main(){
    string s;
    cin>>s;
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n,-1));
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(possiblePalindrome(s, i, j, dp)){
                count++;
            }
        }
    }
    cout<<count;
    return 0;
}