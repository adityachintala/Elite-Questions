// There is a set of 'N' bags contains apples.
// Each bag carries few number of apples.
// You need to pick 'K' bags everytime from left to right.
// and find the bag which contains max number of apples 'M'.
// You need to return the value fo M each time.

// Bags array indicates the apples count in each bag.

// NOTE:
// -----
// Can you solve it in linear time?

// Input Format:
// -------------
// Line-1: Two space separated integers, N and K
// Line-2: N space separated integers, 

// Output Format:
// --------------
// Print the (N-K+1) integer output.


// Sample Input-1:
// ---------------
// 8 3
// 1 2 3 5 4 6 8 7

// Sample Output-1:
// ----------------
// 3 5 5 6 8 8

// Explanation:
// ------------

// K Bags		Max
// -----------    -----
// 1 2 3			3
// 2 3 5			5
// 3 5 4			5
// 5 4 6			6
// 4 6 8			8
// 6 8 7			8



#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> vec;
    int x=0;
    for(int i=0;i<n;i++){
        cin>>x;
        vec.push_back(x);
    }
    for(int i=0;i<=n-k;i++){
        int m=0;
        for(int j=0;j<k;j++){
            m=max(vec[j+i],m);
        }
        cout<<m<<" ";
    }
}