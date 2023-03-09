/*

Ms ALEENA is working on numbers; she is fascinated by number factors.
She is given a number N, she wants to find out all possible ways of 
obtaining N as multiple of its factors.
For example given N =12
can be written as multiple of 2,3 and 4.
and the ways to obtains 12 from ots factors are: 2*2*3, 2*6, 3*4

Your task is to help Ms ALEENA to find the all possible ways of obtaining N 
from its factors and return all the possible ways as shown in the samples.

Input Format:
-------------
An integer N, value of N.

Output Format:
--------------
Print the list of possiblilties.


Sample Input-1:
---------------
12

Sample Output-1:
----------------
[[2, 2, 3], [2, 6], [3, 4]]


Sample Input-2:
---------------
16

Sample Output-2:
----------------
[[2, 2, 2, 2], [2, 2, 4], [2, 8], [4, 4]]


Sample Input-3:
---------------
32

Sample Output-3:
----------------
[[2, 2, 2, 2, 2], [2, 2, 2, 4], [2, 2, 8], [2, 4, 4], [2, 16], [4, 8]]



*/

#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> solve(int n) {
    vector<int> t;
    vector<vector<int>> ans;
    function<void(int, int)> dfs = [&](int n, int i) {
        if (t.size()) {
            vector<int> cp = t;
            cp.emplace_back(n);
            ans.emplace_back(cp);
        }
        for (int j = i; j <= n / j; ++j) {
            if (n % j == 0) {
                t.emplace_back(j);
                dfs(n / j, j);
                t.pop_back();
            }
        }
    };
    dfs(n, 2);
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> res{solve(n)};
    // cout<<res.size()<<endl;
    sort(res.begin(),res.end());
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }

}