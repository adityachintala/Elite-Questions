/*
Yamaha Pvt Ltd has N number of stores in Hyderabad, each showroom has 
allotted few vehicles. The sales of each showroom are given as an array, 
sales[], where sales[i]={S, T} indiactes, i-th showroom sold S number of 
vehicles out of T vehicles allotted to that showroom.

Yamaha introduced a new vehicle in the market and the sales of that 
vehicle are at peak(i.e., these vehicles will definitely sold ). Now, 
Yamaha Pvt Ltd, decided to send P vehicles to Hyderabad. Now, each of 
the P vehicles have to be alloted to a showroom in a way that increases 
the avarage sales ratio across all the showrooms. 
The sales ratio of a showroom is calaculated as the number of vehicles 
sold divided by the total number of vehicles given to that showroom.

Your task is to return the maximum possible average sales ratio 
after P number of new vehicles allotted.

Input Format:
-------------
Line-1: Two space separated integers N and P, no.of showrooms, no.of new vehicles
Next N lines: Two space separated integers S and T, sold count, allotted count.

Output Format:
--------------
Print a double result (rounded to 5 decimals), 
Max avg sales ratio of all showrooms.


Sample Input-1:
---------------
4 3
3 5
4 9
6 8
3 10

Sample Output-1:
----------------
0.57008


Sample Input-2:
---------------
6 4
4 8
3 5
7 9
2 7
3 11
4 13

Sample Output-2:
----------------
0.50499






*/

#include<bits/stdc++.h>
using namespace std;

class Compare {
public:
    bool operator()(pair<int,int> below, pair<int,int> above)
    {
        if (double(double(below.first+1)/double(below.second+1)) - double((below.first)/double(below.second)) > double(double(above.first+1)/double(above.second+1)) - double((above.first)/double(above.second))) {
            return false;
        }
        return true;
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<double>> nums;
    for(int i=0;i<n;++i){
        double s,e;
        cin>>s>>e;
        nums.push_back({s,e});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> pq;
    for(auto it:nums){
        pq.push({it[0],it[1]});
    }
    while(m--){
        pair<int,int> tp = pq.top();
        tp.first += 1;
        tp.second+=1;
        pq.pop();
        pq.push(tp);
    }
    double ans = 0;
    while(!pq.empty()){
        ans += double(double(pq.top().first)/double(pq.top().second));
        pq.pop();
    }
    ans = ans/n;
    ans = roundf(ans*100000)/100000;
    cout<<ans;
    return 0;
}