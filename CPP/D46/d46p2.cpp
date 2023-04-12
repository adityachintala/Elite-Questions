/*
Basanthi interested playing with digits.
He wants create a set of integers of length N, using the digits[0-9].
The rules to create the integers are as follows:
	- digits in each integer are like d0,d1,d2...dn-1
	- and |d0-d1| = |d1-d2| = |d2-d3| ... |dn-2 - dn-1|= D

Basanthi is given two integers N and D, where N is length of the integer and 
D is the difference. Can you help Basanthi, to create such list of integers 
and print all the possible integers in ascending order


Note:
-----
Integers with leading 0's are not allowed


Input Format:
-------------
Two space separated integers N and K.

Output Format:
--------------
Print all the possible integers in ascending order.


Sample Input-1:
---------------
3 6

Sample Output-1:
----------------
[171, 282, 393, 606, 717, 828, 939]


Sample Input-2:
---------------
2 3

Sample Output-2:
----------------
[14, 25, 30, 36, 41, 47, 52, 58, 63, 69, 74, 85, 96]





*/

#include<bits/stdc++.h>
using namespace std;

void f(vector<string>& res,int n,int d,string curr,char prev){
    if(n==0){
        res.push_back(curr);
        return;
    }
    if(curr.size()==0){
        for(auto it='1';it<='9';++it){
            f(res,n-1,d,curr+it,it);
        }
    }
    else{
        for(auto it='0';it<='9';++it){
            if(abs(it-prev)==d){
                f(res,n-1,d,curr+it,it);
            }
        }
    }
}

int main(){
    int n,d;
    cin>>n>>d;
    vector<string> res;
    string temp="";
    char prev='0';
    f(res,n,d,temp,prev);
    for(auto it:res){
        cout<<it<<' ';
    }
}