/*
Chhota Bheem is fond of Laddus, there are N boxes in a row, each box contains 
some laddus, where k-th box conatins box[k]-number of laddus.

In one go, Choota Bheem can choose any box and eat floor(box[i]/2) laddus 
from it. He has do the above step, exactly K times. He is allowed to eat 
from the same box any number of times.

 
You are given an list of N integers, number of laddus in each box.
Your task is to return the minimum nu  mber of laddus left in all the boxes 
together, after K times.

NOTE: floor(I) is the greatest integer that is smaller than or equal to I.
 
Input Format:
-------------
Line -1: Two space separated integers N and K,number of boxes and value of K.
Line -2: N space separated integers, number of laddus in each box.
 
Output Format:
--------------
Print an integer result.
 
Sample Input-1:
---------------
3 2
3 5 9
 
Sample Output-1:
----------------
11
 
Explanation:
------------
Steps of a possible scenario are:
- Chota bheem selected box-2. The resulting boxes are [3,5,5].
- Chota bheem selected box-2. The resulting boxes are [3,5,3].
The total number of laddus in all the boxes [3,5,3] is 11.

 
Sample Input-2:
---------------
5 3
4 3 8 6 7
 
Sample Output-2:
----------------
18




*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;cin>>n>>k;
    vector<int> v(n);
    priority_queue<int> pq;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        pq.push(x);
    }
    
    while(k--){
        auto x = pq.top();pq.pop();
        x = ceil((float)x/2);
        pq.push(x);
    }
    int sum=0;
    while(!pq.empty()){
        auto x =pq.top();pq.pop();
        sum += x;
    }
    cout<<sum<<endl;
}