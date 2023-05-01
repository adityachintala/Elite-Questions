/*

You will be given the matrix of size R*C,

You have to return the matrix in special order as shown in the sample tescases.
 

Input Format:
-------------
Line-1 -> Two integers R and C, size of matrix.
Next R-Lines -> C space separated integers

Output Format:
--------------
Print R-Lines -> C space separated integers, in special order.


Sample Input-1:
---------------
3 3
1 2 3
4 5 6
7 8 9

Sample Output-1:
----------------
1 2 3
6 9 8
7 4 5


Sample Input-2:
---------------
3 4
1 2 3 4
5 6 7 8
9 10 11 12

Sample Output-2:
----------------
1 2 3 4
8 12 11 10
9 5 6 7




*/




#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int left=0,right=m-1,topup=0,topdown=n-1;
    vector<vector<int>>v(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    int d=0;
    int lel=0;
    vector<int>ans;
    while(left<=right || topup<=topdown){
        if(d==0){
            for(int u=left;u<=right;u++){
                ans.push_back(v[topup][u]);
            }
            topup++;
            
        }
        else if(d==1){
            for(int u=topup;u<=topdown;u++){
                ans.push_back(v[u][right]);
            }
            right--;
            
        }
        else if(d==2){
            for(int u=right;u>=left;u--){
                ans.push_back(v[topdown][u]);
            }
            topdown--;
            
            
        }
        else{
            for(int u=topdown;u>=topup;u--){
                ans.push_back(v[u][left]);
            }
            left++;
            
        }
        d++;
        if(d==4){
            d=0;
        }
        
    }
    for(int i=0;i<ans.size();i++){
        if(i%3==0 && i!=0){
            cout<<endl;
        }
        cout<<ans[i]<<" ";
        
    }
}