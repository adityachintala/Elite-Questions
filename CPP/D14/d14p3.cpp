// Ganesh is working on numbers, He is given a list of integers 1,2,3,...,N 
// the list is indexed from 1 to N.

// Now he can shuffle the list in whatever way he want.
// Shuffled list is said to be valid, if one of the following is true for 
// i-th position in the list.
// 	- The integer at the i-th position is divisible by i.
// 	- 'i' is divisible by the integer at the i-th position.

// Now your task is to find out, How many valid shuffles can Ganesh do?

// Input Format:
// -------------
// An integer N, where N<=20.

// Output Format:
// --------------
// Print an integer, number of ways ganesh can shuffle.


// Sample Input-1:
// ------------------
// 1

// Sample Output-1:
// --------------------
// 1

// Explanation:
// ---------------
// The list contains only value 1, so the valid shuffles are 1 only.


// Sample Input:
// ---------------
// 2

// Sample Output:
// ----------------
// 2

// Explanation:
// ------------
// The first shuffled list is [1, 2]:
// Integer at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).
// Integer at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).

// The second shuffled list is [2, 1]:
// Integer at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).
// Integer at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.


// Sample Input-3:
// ---------------
// 3

// Sample Output-3:
// ----------------
// 3

// Explanation:
// ------------
// The valid shuffled lists are: [1,2,3], [3,2,1],[2,1,3]


// Sample Input-4:
// ---------------
// 4

// Sample Output-4:
// ----------------
// 8

// Explanation:
// ------------
// The valid shuffled lists are: [1,2,3,4], [3,2,1,4],[2,1,3,4],[4,2,3,1],[1,4,3,2],[3,4,1,2],[2,4,3,1],[4,1,3,2]


#include<bits/stdc++.h>
using namespace std;

void backtrack(vector<int> &visited,int &val,int n,int& count){
    if(val==n){
        count += 1;
        return;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            if(val==0 || (i+1)%(val+1)==0 || (val+1)%(i+1)==0){
                val += 1;
                visited[i] = true;
                backtrack(visited,val,n,count);
                visited[i] = false;
                val -= 1;
            }
        }
    }
}

int main(){
    int n;
    cin>>n;
    set<set<int>> ans;
    vector<int> visited(n,0);
    int val=0,count=0;
    backtrack(visited,val,n,count);
    cout<<count;
    return 0;
}