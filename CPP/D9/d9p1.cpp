// A game-zone is represented as an infinite 2D grid. At every integer coordinate 
// (x,y) there is a bag, and the bag contains |x| + |y| number of chocolates in it.

// You want grab N chocolates for your kid. You have to select some square area in 
// the game-zone such a way that the selected area is an axis-aligned square plot 
// that is centered at (0, 0).

// Your task is to find the minimum perimeter of the square area such that 
// at least it conains N chocolates are inside or on the perimeter of that area.

// NOTE: 
// The value of |x| is defined as: x if x >= 0 -x if x < 0

// Constarint:
// -----------
// 1 <= N <= 10^14

// Input Format:
// -------------
// An integer N, number of chocolates.

// Output Format:
// --------------
// Print an integer result.


// Sample Input-1:
// ---------------
// 5

// Sample Output-1:
// ----------------
// 8

// Explanation:
// ------------


// Sample Input-2:
// ---------------
// 56

// Sample Output-2:
// ----------------
// 16

// Explanation:
// ------------


// Sample Input-3:
// ---------------
// 62

// Sample Output-3:
// ----------------
// 24


#include<bits/stdc++.h>
using namespace std;

long long int func(long long int x){
    return 4*(x*x*x)+6*(x*x)+2*x;
}

int main(){
    long long int n;cin>>n;
    long long int st = 1,ed = 10e5;
    long long int ans = INT_MAX;
    while(st<=ed){
        long long int mid = (st+ed)/2;
        long long int val = func(mid);
        if(val>=n){
            ed = mid-1;
        }
        else{
            st = mid+1;
        }
    }
    cout<<st*8<<endl;
    return 0;
}