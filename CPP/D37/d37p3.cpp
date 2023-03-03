/*

KCR Chief Minister of Telangana Government has passed a new G.O to Telangana 
police for safety of Telangana people. In this regard he announced new Vehicles 
to be released for all the stations working for this mission especially.

Here we have a 2D mesh, there are P police officers and V vehicles, with P<=V.
Each police officer and vehicle is a 2D coordinate on this mesh.
Here the government has assigned a unique vehicle to each police officer.

Now create a method which prints the minimum possible sum of distances between 
each police officer and their assigned vehicle.

Here the distance is between police officer Pi and vehicle Vi assigned to him.
And distance between Pi, Vi is calculated as follows: |Pi.x - Vi.x| + |Pi.y - Vi.y|


Input Format:
-------------
Line-1: Two integers P and V, number of police officers and vehicles.
Next P lines: Two space separated integers co-ordinates of Police officers.
Next V lines: Two space separated integers co-ordinates of Vehicles.

Output Format:
--------------
Print an integer, the minimum possible sum of distances.


Sample Input-1:
---------------
3 3
0 1		// co-ordinates of police
1 2
1 3
4 5		// co-ordinates of vehicles
2 5
3 6

Sample Output-1:
----------------
17


Sample Input-2:
---------------
2 2
0 0		// co-ordinates of police
2 1
1 2		// co-ordinates of vehicles
3 3

Sample Output-2:
----------------
6


*/

#include <bits/stdc++.h>
using namespace std;

int res = INT_MAX;

void backtrack(int ind, vector<vector<int>>& parr, vector<vector<int>>& varr, vector<bool>& vis, int sum, int count){
    if(ind == parr.size()){
        res = min(res, sum);
        return;
    }
    for(int i=0;i<vis.size();i++){
        if(!vis[i]){
            vis[i] = true;
            int dis = abs(parr[ind][0] - varr[i][0]) + abs(parr[ind][1] - varr[i][1]);
            backtrack(ind+1, parr, varr, vis, sum + dis, count + 1);
            vis[i] = false;
        }
    }
}

int main() {
    int p, v;
    cin >> p >> v;
    vector<vector<int>> parr(p, vector<int>(2));
    vector<vector<int>> varr(v, vector<int>(2));
    for(int i=0;i<p;i++){
        cin >> parr[i][0] >> parr[i][1];
    }
    for(int i=0;i<v;i++){
        cin >> varr[i][0] >> varr[i][1];
    }
    vector<bool> vis(v, false);
    backtrack(0, parr, varr, vis, 0, 0);
    cout << res << endl;
    return 0;
}