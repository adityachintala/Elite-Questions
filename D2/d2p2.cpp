#include<bits/stdc++.h>
using namespace std;

void f(int city,int end,vector<int> temp,vector<vector<int>>& res,vector<vector<int>> graph){
    // debug(city);
    // debug(temp);
    if(city==end){
        res.push_back(temp);
        return;
    }
    for(auto i:graph[city]){
        temp.push_back(i);
        f(i,end,temp,res,graph);
        temp.pop_back();
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> ways(n,0);
    for(int i=0;i<n;++i){
        cin>>ways[i];
    }
    int count = 0;
    vector<vector<int>> graph(n,vector<int>());
    for(int i=0;i<n-1;++i){
        for(int j=0;j<ways[i];++j){
            int zz;
            cin>>zz;
            graph[i].push_back(zz);
        }
    }
    
    // debug(graph);
    vector<vector<int>> res;
    vector<int> temp={0};
    f(0,n-1,temp,res,graph);
    cout<<'[';
    for(int i=0;i<res.size();++i){
        vector<int> it = res[i];
        cout<<'[';
        for(int k=0;k<it.size();++k){
            int j = it[k];
            cout<<j;
            if(k!=it.size()-1){
                cout<<", ";
            }
        }
        cout<<']';
        if(i!=res.size()-1){
            cout<<", ";
        }
    }
    cout<<']';
    return 0;
}