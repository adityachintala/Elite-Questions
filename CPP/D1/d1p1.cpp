/*There are N rooms in a row, and all the rooms are locked initially.
You will be provided the master key. You can use the master key only once, and
you can unlock any one room and find a key in it of some other room. 
You have to repeat this process until you can find the keys of the locked rooms. 
You have to stop this process once you find the key of a room 
which is already unlocked.
You are given an array of keys[], where i-th room contains the key of key[i]-th
room and values of keys[] are range from [0..N-1] without duplicates. Your task 
is to find the maximum number of rooms can be unlocked including the first room.
Input Format:
-------------
Line-1: An integer N, number of rooms.
Line-2: N space separated integers, keys of rooms.
Output Format:
--------------
Print an integer result.
Sample Input-1:
---------------
8
7 4 6 2 1 0 3 5
Sample Output-1:
----------------
3
Explanation:
-----------
keys[0] = 7, keys[1] = 4, keys[2] = 6, keys[3] = 2, keys[4] = 1, keys[5] = 0, 
keys[6] = 3, keys[7]=5.
You can start with Room-0 using the master key, you can open the following rooms:
key[0]=7 =>  key[7]=5  =>  key[5]=0
      or
key[2]=6 =>  key[6]=3  =>  key[3]=2
You can unlock maximum 3 rooms.
Sample Input-2:
---------------
6
3 2 4 0 5 1
Sample Output-2:
----------------
4
Sample Input-3:
---------------
5
0 1 2 3 4
Sample Output-3:
----------------
1
*/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> vec,int n,int st){
    queue<int> que;
    que.push(vec[st]);
    vec[st]=-1;
    int count=0;
    while(!que.empty()){
        int x=que.front();
        que.pop();
        if(x==-1){
            return count;
        }
        que.push(vec[x]);
        count++;
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    vector<int> vec;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        vec.push_back(x);
    }
    int m=0;
    for(int i=0;i<n;i++){
        m=max(m,solve(vec,n,i));
    }
    cout<<m<<endl;
}
