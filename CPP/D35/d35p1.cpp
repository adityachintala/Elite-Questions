/*

Kohinoor diamond is robbed by Hrithik, He kept the diamond in a suitcase, 
the suitcase has a lock with 4 circular wheels, and each wheel consist of
0-9 digits in the order 0,1,2,3,4,5,6,7,8,9 only.
You can rotate a wheel from 0 to 9 or 9 to 0.

As the diamond is most valuable, the lock has some traps,
if anybody try to unlock the suitcase and reached any one of the traps,
the suitcase will be blasted. And you will be dead.

Initially, the suitcase lock is set to 0000.
and you will be given the unlock key, your task to find and print
the minimum number of rotations required to unlock the suitcase.
If it is not possible to unlock the suitcase without blasting, print -1.

NOTE:
In one rotation you can choose any one wheel and 
rotate to its next or previous digit.


Input Format:
-------------
Line-1: space separated strings, each string of length 4 and contains only digits [0-9]
Line-2: A string, key to unlock.

Output Format:
--------------
Print an integer, the minimum number of rotations required to unlock.


Sample Input-1:
---------------
0302 0202 0203 2323 3003
0303 

Sample Output-1:
----------------
8

Explanation:
------------
To unlock the suitcase the valid rotations are as follows:
0000 > 1000 > 1100 > 1200 > 1201 > 1202 > 1302 > 1303 > 0303.


Sample Input-2:
---------------
6656 6676 6766 6566 5666 7666 6665 6667
6666 

Sample Output-2:
----------------
-1

Explanation:
------------
You can't unlock the suitcase.



*/



#include<bits/stdc++.h>
using namespace std;

vector<string> neighbors(string str){
    vector<string> neighs;
    for(int i=0;i<=3;++i){
        for(int j=-1;j<=1;j+=2){
            string temp = str;
            temp[i] = (temp[i]-'0'+j+10)%10+'0';
            neighs.push_back(temp);
        }
    }
    return neighs;
}

int main(){
    string num;
    getline(cin,num);
    unordered_set<string> days;
    string x;
    istringstream obj(num);
    while(obj>>x){
        days.insert(x);
    }
    string dest;
    cin>>dest;
    if(days.count(dest) || days.count("0000")){
        cout<<-1;
    }
    else{
        queue<string> q({"0000"});
        bool flag = false;
        for (int steps = 0; !q.empty(); ++steps) {
            if(flag){break;}
            for (int i = q.size(); i > 0; --i) {
                auto curr = q.front(); q.pop();
                if (curr == dest){
                    cout<<steps;
                    flag=true;
                    break;
                }
                if(flag){break;}
                for (auto nei : neighbors(curr)) {
                    if (days.count(nei)) continue;
                    days.insert(nei);
                    q.push(nei);
                }
                if(flag){break;}
            }
        }
        if(!flag){
            cout<<-1;
        }
    }
    return 0;
}