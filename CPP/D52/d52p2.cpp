/*
Kiran is playing with strings and its subsequences.
A subsequence can be formed from a string by deleting some characters
(may be string itself)

Kiran has given two strings S and T, your task to form T by concatenating 
the subsequences of S  

Return the minimum number of subsequences required to form T.
If the task is impossible, return -1 .


Input Format:
-------------
Line-1 -> Two strings S and T

Output Format:
--------------
Print an integer as result.


Sample Input-1:
---------------
abc abcbc

Sample Output-1:
----------------
2

Explanation: 
------------
T = "abcbc" can be formed by "abc" and "bc",
which are subsequences of S = "abc".


Sample Input-2:
---------------
abc acdbc

Sample Output-2:
----------------
-1

Explanation: 
------------
string T cannot be constructed from the
subsequences of string S due to the character "d" in string T.





*/


#include<bits/stdc++.h>
using namespace std;

int shortestWay(string source, string target) {
        int m = source.size(), n = target.size();
        int ans = 0, j = 0;
        while (j < n) {
            int i = 0;
            bool ok = false;
            while (i < m && j < n) {
                if (source[i] == target[j]) {
                    ok = true;
                    ++j;
                }
                ++i;
            }
            if (!ok) {
                return -1;
            }
            ++ans;
        }
        return ans;
}

int main(){
    string a,b;
    cin>>a>>b;
    cout<<shortestWay(a,b);
    return 0;
}