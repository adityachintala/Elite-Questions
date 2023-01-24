// In a school Students are given four integers which defines minimumLength, 
// maximumLength, oneGroup and zeroGroup related to strings

// A binary string is good if it satisfies the following conditions:
//     -- The length of the string is in the range [minimumLength, maximumLength].
//     -- The size of each block of consecutive 1's is a multiple of oneGroup.
//        For example in a binary string 00110111100 sizes of each block of 
//        consecutive ones are [2,4].
//     -- The size of each block of consecutive 0's is a multiple of zeroGroup.
//        For example, in a binary string 00110111100 sizes of each block of 
//        consecutive zeros are [2,1,2].

// Return the number of good binary strings. Since the answer may be too large, 
// return it modulo 10^9 + 7.
// Note that 0 is considered a multiple of all the numbers.

// Input Format
// ------------
// read min, max, onegroup, zerogroup four integers

// output Format
// ------------
// An integer which is no of good strings


// Sample Input-1:
// ---------------
// 2 3 1 2

// Sample Output-1:
// ----------------
// 5

// Explanation:
// ------------
// There are 5 good binary strings in this example: "00", "11", "001", "100", and "111".
// It can be proven that there are only 5 good strings satisfying all conditions.


// Sample Input-2:
// ---------------
// 4 4 4 3

// Sample Output-2:
// ----------------
// 1

// Explanation:
// ------------
// There is only 1 good binary string in this example: "1111".
// It can be proven that there is only 1 good string satisfying all conditions.


#include<bits/stdc++.h>
using namespace std;

long long mod  = 1000000007;

int main(){
    int l,h,z,o;
    cin>>l>>h>>z>>o;
    vector<long long>arr(200005);
    long long res = 0;
    arr[0] = 1;
    for(int i = 0; i < 100005; i++){
        arr[i + z]= arr[i + z]%mod;
        arr[i + z] += arr[i];
        arr[i + o]=arr[i + o]%mod;
        arr[i + o] += arr[i];
    }
    for(int i = l; i <= h; i++){
        res = (res + arr[i])%mod;
    }
    cout<<res;
    return 0;
}