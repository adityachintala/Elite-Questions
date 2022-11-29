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