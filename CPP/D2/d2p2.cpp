/**
 * There are N cities, the cities are connected through one way routes and 
there is no cycle between the routes. Each city is numbered from 0 to N-1.
The map of the cities is given as follows: 
map[i] is a list of all the cities you can travel from city[i].
(i.e., there is a one-way route from city[i] to node[map[i][j]]).
Your task is to findout all the possible travel routes between city-[0] to 
city-[N-1]. 
 
Input Format:
-------------
Line-1: An integer N , number of cities.
Line-2: N space separated integers, number of outgoing routes from city[i], 0<=i<N.
Next N lines: "out[i]" space separated integers, routes from city[i] where 0<=i<N
 
Output Format:
--------------
Print the list of travel routes.
Hint: find the routes in the input order.
 
Sample Input-1:
---------------
4
2 1 1 0
1 2
3
3
Sample Output-1:
----------------
[[0, 1, 3], [0, 2, 3]]
 
Sample Input-2:
---------------
5
3 3 1 1 0
4 3 1
3 2 4
3
4
 
Sample Output-2:
----------------
[[0, 4], [0, 3, 4], [0, 1, 3, 4], [0, 1, 2, 3, 4], [0, 1, 4]]
*/

#include<bits/stdc++.h>
using namespace std;

void f(int city,int end,vector<int> temp,vector<vector<int>>& res,vector<vector<int>> graph){
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
