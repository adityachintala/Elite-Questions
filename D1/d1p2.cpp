#include<bits/stdc++.h>
using namespace std;

int main(){
    int m,n;
    cin>>m>>n;
    queue<pair<int,int>> q;
    set<pair<int,int>> st;
    vector<int> xdir = {-2,-2,+2,+2,-1,+1,-1,+1};
    vector<int> ydir = {-1,+1,-1,+1,+2,+2,-2,-2};
    m+=205;
    n+=205;
    q.push({205,205});
    int count = 0;
    int flag = 0;
    while(!q.empty()){
        if(flag==1){
            break;
        }
        int sz = q.size();
        for(int i=0;i<sz;++i){
            auto top = q.front();q.pop();
            if(top.first<0 || top.second<0 || top.first>410 || top.second>410){
                continue;
            }
            if(top.first==m && top.second==n){
                flag=1;
                break;
            }
            for(int j=0;j<8;++j){
                int x1 = top.first + xdir[j];
                int y1 = top.second + ydir[j];
                if(x1<0 || y1<0 || x1>410 || y1>410 || st.find({x1,y1})!=st.end()){
                    continue;
                }
                q.push({x1,y1});
                st.insert({x1,y1});
            }
        }
        if(flag==1){
            break;
        }
        count++;
    }
    cout<<count<<endl;
}