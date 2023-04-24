/*

In Dubai's Burj Khalifa, there is an elevator moves only in upwards direction, 
the elevator can carry N members.

The people are waiting for the elevator at different floors, made P requests, 
request[i] = [ num_people, enter_floor, exit_floor ], each request indicates, 
number of people to enter into elevator, entering floor number, 
exiting floor number.

Initially the elevator is empty.

Your task is to find and return true, iff it is possible to enter the people
into elevator and exit from elevator of all the requests made by the people.


Input Format:
-------------
Line-1 -> Two integers P and N, number of requests and number of members 
          can be carried by elevator.
Next N Lines -> three space separated integers, num_people, enter_floor, exit_floor.

Output Format:
--------------
Print a boolean value.


Sample Input-1:
---------------
2 5
2 1 5
3 3 7

Sample Output-1:
----------------
true



Sample Input-2:
---------------
2 4
2 1 5
3 3 7

Sample Output-2:
----------------
false



Sample Input-3:
---------------
3 11
3 2 7
3 7 9
8 3 9

Sample Output-3:
----------------
true


*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    map<int,int> mp;string flag = "true";
    for(int i=0;i<n;++i){
        int a,b,c;
        cin>>a>>b>>c;
        mp[b]+=a;
        mp[c]-=a;
        if(b>c){
            flag = "false";
        }
    }
    int curr=0;
    for(auto it:mp){
        if(flag=="false"){
            break;
        }
        curr += it.second;
        if(curr > k){
            flag = "false";
            break;
        }
    }
    cout<<flag;
    return 0;
}