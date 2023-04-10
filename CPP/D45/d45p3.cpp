/*
Gnanesh is working on Machine Learning domain. He wants train the machine 
in such a way that, if he provided an image printed with a string on it,
the machine has to extract the text as a string and verify that, 
after shuffling  the letters in the string, 'the shuffled string should be 
like no two adjacent letters should be same' 

You will be given extracted string, and
Can you help Gnanesh to train the machine with the given constraint 
The machine has to print "true", if the constarint is met, 
Otherwise, print "false".

Input Format:
-------------
A String S

Output Format:
--------------
Print a boolean value.


Sample Input-1:
---------------
aaabd

Sample Output-1:
----------------
true

Sample Input-2:
---------------
aaab

Sample Output-2:
----------------
false




*/


#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;cin>>s;
    map<char,int> mp;
    int n = s.length();
    int cnt=0;
    for(int i=0;i<s.length();i++){
        mp[s[i]]++;
        cnt = max(cnt,mp[s[i]]);
    }
    if(n%2==0 and cnt>(n/2)){
        cout<<"false"<<endl;
    }else if(n%2 and cnt>((n/2)+1)){
        cout<<"false"<<endl;
    }else{
        cout<<"true"<<endl;
    }
}