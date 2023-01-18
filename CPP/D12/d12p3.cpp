// There are n boxes of balls in a row, every i-th box contains balls[i] balls.

// A series of boxes is called Arithmetic, if it consists of at least three boxes
// and if the difference between the number of balls in any two consecutive boxes 
// is same.

// A subset of boxes is called Arithmetic Subset,
// if subset[i], subset[i+1], subset[i+2], ..., subset[j] is Arithmetic.

// Your task is to findout the number of Arithmetic Subsets in the row of boxes.

// Input Format:
// -------------
// Line-1 : An integer N, number of boxes.
// Line-2 : N space separated integers balls[i], i-th box contains balls[i] balls. 

// Output Format:
// --------------
// Print an integer, number of Arithmetic Subsets.


// Sample Input:
// ---------------
// 4
// 1 2 3 4

// Sample Output:
// ----------------
// 3

// Explanation:
// ------------
// Arithmetic Subsets are: [1,2,3], [2,3,4], [1,2,3,4].


// Sample Input:
// ---------------
// 5
// 1 3 5 7 9

// Sample Output:
// ----------------
// 6

// Explanation:
// ------------
// Arithmetic Subsets are: [1,3,5], [3,5,7], [5,7,9], [1,3,5,7], [3,5,7,9], [1,3,5,7,9].


#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> nums(n,0);
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }
    vector<int> dp(n,0);
    for(int i=2;i<n;++i){
        if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
            dp[i]+=dp[i-1]+1;
        }
    }
    int ans = 0;
    for(int i=0;i<n;++i){
        ans += dp[i];
    }
    cout<<ans;
}