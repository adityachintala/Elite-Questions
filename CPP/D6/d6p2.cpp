// In an International school 9th standard students have been assigned a task.

// Given a list of numbers nums[] and three values p, q and r.
// They have to solve the equation function(x)=p(x^2)+q(x)+r, 
// for each number(x) in the given list nums[],
// and print the resultant values in the sorted order.

// Input Format:
// -------------
// Line-1: An integer N, size of list nums[].
// Next N lines: space separated integers, nums[]
// Last Line: 3 space separated integers, P, Q and R.

// Output Format:
// --------------
// Print a list of numbers[].


// Sample Input-1:
// ---------------
// 4
// -3 -2 2 4
// 2 3 5

// Sample Output-1:
// ----------------
// 7 14 19 49



// Sample Input-2:
// ---------------
// 4
// -3 -2 1 2
// -2 3 5

// Sample Output-2:
// ----------------
// -22 -9 3 6


#include<bits/stdc++.h>
using namespace std;

int maths(int p,int q,int r,int x){
    return p*x*x + q*x + r;
}

int main(){
    int n;
    cin>>n;
    vector<int> xvalues(n,0);
    for(int i=0;i<n;++i){
        cin>>xvalues[i];
    }
    int p,q,r;
    cin>>p>>q>>r;
    int i=0,j=n-1;
    vector<int> res;
    if(p>0){
        while(i<=j){
            if(i==j){
                res.push_back(maths(p,q,r,xvalues[i]));
                break;
            }
            int val1 = maths(p,q,r,xvalues[i]), val2 = maths(p,q,r,xvalues[j]);
            if(val1 >= val2){
                res.push_back(val1);
                i++;
            }
            else{
                res.push_back(val2);
                j--;
            }
        }
        
        // cout<<endl;
        // debug(res);
        reverse(res.begin(),res.end());
        for(auto it:res){
            cout<<it<<' ';
        }
        cout<<endl;
    }
    else{
        while(i<=j){
            if(i==j){
                res.push_back(maths(p,q,r,xvalues[i]));
                break;
            }
            int val1 = maths(p,q,r,xvalues[i]), val2 = maths(p,q,r,xvalues[j]);
            if(val1 >= val2){
                res.push_back(val2);
                j--;
            }
            else{
                res.push_back(val1);
                i++;
            }
        }
        
        for(auto it:res){
            cout<<it<<' ';
        }
        cout<<endl;
    }
    return 0;
}