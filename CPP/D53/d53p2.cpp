/*
Bunny is playing with binary strings. He wants to break
a binary string B into 3 parts, of length atleast '1',
when we merge the 3 parts will result the string B.

Your task is to find the count the various forms to break 
the Binary String B into 3 parts, where each part should 
contain equal number of 1's.


Input Format:
-------------
A string S.

Output Format:
--------------
Print an integer, count the various forms to break.


Sample Input-1:
---------------
01010010

Sample Output-1:
----------------
6

Explanation:
------------
There are six forms to break S into 3 parts 
where each part contain the equal number of  1's.
01 | 01 | 0010
01 | 010 | 010
01 | 0100 | 10
010 | 1 | 0010
010 | 10 | 010
010 | 100 | 10


Sample Input-2:
---------------
010010

Sample Output-2:
----------------
0


*/


#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    long long int i,n=s.size();
    int one=0;
    long long mod=1000000007;
    long long ans;
    for(i=0;i<n;i++)
        if(s[i]=='1')
            one++;
    if(one%3!=0){
        ans = 0;
    }
    else if(one==0)
    {
       ans =((n-1)*(n-2)/2)%mod;
    }
    else
    {
        long long countOfone=one/3;
        long long index1=-1,index1end=-1;
        long long  index2=-1,index2end=-1;
        long long count=0;
        for(i=0;i<n;i++)
        {   
            if(s[i]=='1')
                count++;
            if(count==countOfone&&index1==-1)
                index1=i;
            if(count==countOfone+1&&index2==-1)
                index2=i;
            if(count==countOfone*2&&index1end==-1)
                index1end=i;
            if(count==countOfone*2+1&&index2end==-1)
                index2end=i;
        
        }
        ans=((index2-index1)%mod)*((index2end-index1end)%mod)%mod;
    }
    cout<<(int)ans;
    return 0;
}