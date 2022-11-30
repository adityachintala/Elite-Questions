/*Mr Suleman is given a checkerboard of size 400*400,where the indices starts from(-200,-200)and ends at(199,199).In one step,he can move the box from position(p,q)to one of the following positions in L shape like as follows:-(p-2,q-1),(p-2,q+1),(p+2,q-1),(p+2,q+1)-(p-1,q+2),(p+1,q+2),(p-1,q-2),(p+1,q-2)
Initially the box is at(0,0)position,and need to move the box to position(m,n).You will be given two integers m and n indicates the position(m,n).
Now your task is to help by Mr Suleman to find the minimum number of steps required to move the box from(0,0)to(m,n).
Note:It is allowed to move out of the board also.
Input Format:-----------------Two space separated integers,m and n,position.
Output Format:------------------Print an integer,minimum number of steps to reach(m,n).
Sample Input-1:---------------2 4
Sample Output-1:----------------2
Explanation:-------------Initially,you are at(0,0)position,you can reach(2,4)as follows:(0,0)->(1,2)->(2,4)
Sample Input-2:---------------4 7
Sample Output-2:----------------5
Explanation:------------Initially,you are at(0,0)position,you can reach(4,7)as follows:(0,0)->(1,2)->(2,4)->(1,6)->(3,5)->(4,7)
*/

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
