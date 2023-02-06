// There is a party happening in Novotel. There are N guests in the party.
// There is a detective in the party and he/she is among one of the guests.
// The guests are identified with unique ID's starts from 1 to N.

// The rules to identify the detective are:
// 	- Every guest in the party knows the detective.
// 	- The detective knows no one in the party.
// 	- There is only one guest who satisfy both rule-1 and rule-2

// You are given two integers N and R and the relations as an array, relations[], where relation[i]={guest-i, guest-j}, indicates guest-i knows h=guest-j.
// Your task is to find the detective among the guests in the party and print the ID of the detective, Otherwise print -1.

// Input Format:
// -------------
// Line-1: Two integers N and R, the number of guests and relations in the party.
// Next R lines: contains 2 space-separated integers, relation[i]

// Output Format:
// --------------
// Print an integer, the id of the detective.


// Sample Input-1:
// ---------------
// 3 2		// N and R values
// 1 3
// 2 3

// Sample Output-1:
// ----------------
// 3


// Sample Input-2:
// ---------------
// 3 3
// 1 2
// 2 3
// 3 1

// Sample Output-2:
// ----------------
// -1



#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,r;
    cin>>n>>r;
    unordered_map<int,int> knowsme,iknow;
    for(int i=0;i<r;i++){
        int a,b;
        cin>>a>>b;
        knowsme[b]++;
        iknow[a]++;
    }
    for(int i=1;i<=n;++i){
        if(knowsme[i]==n-1 && iknow[i]==0){
            cout<<i;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}

