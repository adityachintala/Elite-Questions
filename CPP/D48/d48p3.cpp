/*

Venkat wants to create a unique name for his child, to do that he is referring 
two names, one is traditonal name(TN) and other is modern name(MN).

He is planning to create unique name(UN), using the following ways:
    - if traditional name TN is non empty, then add the first letter L of TN 
    to unique name UN and remove the letter L from traditional name TN
	e.g., if TN = "havi" and UN="anvika", then after adding L to UN and remove L 
	from TN, the names updated as UN="hanvika", TN="avi".
   
   - if modern name MN is non empty, then add the first letter L of MN 
    to unique name UN and remove the letter L from modern name MN
    e.g., if MN = "ram" and UN="ao", then after adding L to UN and remove L 
	from MN, the names updated as UN="rao", MN="am".
	
You are given two names, TN and MN, 
Your task is to help venkat to generate the unique name for his child,
and the name should be largest in the dictionary order.

For example, "kmit" is larger than "kmec", as third letter is greater in "kmit".

Input Format:
-------------
Two space separated names, TN and MN.

Output Format:
--------------
Print a string, the laregst unique name possible.


Sample Input-1:
---------------
sudha vivid

Sample Output-1:
----------------
vsuividhda


Sample Input-2:
---------------
appa banana

Sample Output-2:
----------------
bappananaa





*/


#include<bits/stdc++.h>
using namespace std;

string ans = "";

void func(int idx1,int idx2,int n,int m,string a,string b,string temp){
    if(idx1==n or idx2==m){
        while(idx1<n){
            temp+=a[idx1];idx1++;
        }
        while(idx2<m){
            temp += b[idx2];idx2++;
        }
        ans = max(ans,temp); 
        return;
    }
    if(a[idx1]>b[idx2]){
        func(idx1+1,idx2,n,m,a,b,temp+a[idx1]);
    }else if(a[idx1]<b[idx2]){
        func(idx1,idx2+1,n,m,a,b,temp+b[idx2]);
    }else{
        func(idx1+1,idx2,n,m,a,b,temp+a[idx1]);
        func(idx1,idx2+1,n,m,a,b,temp+b[idx2]);
    }
}

int main(){
    string a,b;cin>>a>>b;
    int n = a.length(),m=b.length(); 
    func(0,0,n,m,a,b,"");
    cout<<ans<<endl;
}