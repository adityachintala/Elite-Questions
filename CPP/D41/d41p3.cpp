/*

In a forest, There are N redwoord trees in a row.
You are given the heights of the trees as heights[],

You are task is to find the longest tree arrangement as follows:
	- Minimum size of the tree arrangement is 3.
	- And there exist a Tree-'i' with heights[i], where 0 < i < N-1.
		- heights[0] < heights[1] < heights[2] <...< heights[i] and
		-  heights[i] > heights[i+1] > heights[i+2] >...>heights[N-1] 

And return the length of the longest tree arrangement.
If there is no such arrangement, return 0.

Input Format:
-------------
Line-1: An integer N, number of elements.
Line-2: N space separated integers, value of the elements.

Output Format:
--------------
Print an integer result.


Sample Input-1:
---------------
8
4 2 5 7 4 2 3 6

Sample Output-1:
----------------
5

Explanation:
------------
The longest tree arrangement is : 2 5 7 4 2


Sample Input-2:
---------------
4
2 4 5 7

Sample Output-2:
----------------
0




*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    vector<int> lis(n,0);
    for(int i=1;i<n;++i){
            if(arr[i]>arr[i-1]){
                lis[i]=lis[i-1]+1;
        }
    }
    vector<int> lds(n,0);
    for(int i=n-2;i>=0;--i){
            if(arr[i]>arr[i+1]){
                lds[i]=lds[i+1]+1;
        }
    }
    int maxi=0;
    for(int i=0;i<n;++i){
        if(lis[i]>0 && lds[i]>0){
            maxi=max(maxi,lis[i]+lds[i]+1);
        }
    }
    cout<<maxi;
    return 0;
}