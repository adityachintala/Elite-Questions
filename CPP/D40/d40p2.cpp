/*

There are some Special Numbers between 0 to 10^N.
A number is called special, if all the digits in that number should be different.
i.e., No two digits are same in that number.

You are given an integer N,
Your task is to find the count of special numbers (X) between 0<= X < 10^N.

NOTE: Leading 0's are allowed.

Input Format:
-------------
An integer N

Output Format:
--------------
Print an integer, Count of special numbers.

Sample Input-1:
---------------
1

Sample Output-1:
----------------
10


Sample Input-1:
---------------
2

Sample Output-1:
----------------
91

Explanation:
--------------
Special Number between 0<= X < 10^2.
Exclude 11, 22, 33, 44, 55, 66, 77, 88, 99, => count is 9
Total Count is 100=> Special Numbers count is 100-9 = 91.



*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1);
    dp[0] = 1;
    dp[1] = 10;
    for(int i = 2;i<=n;i++){
        dp[i] = 9;
        int k = 9;
        int count = 1;
        while( count <i){
            dp[i] *= k;
            k--;
            count++;
        }
        dp[i] +=dp[i-1];
    }
    cout<<dp[n];
    return 0;
}