/*
In a class of XII, computer teacher asked one of the student 
to perform a task as practical session .

There is a box contains N balls in it, each ball is printed 
with a positive integer. The teacher ask the student to split 
all the balls in the box into ball-groups,
each group should contain exatly S balls.

The student has to pick the ball-groups as follows:
	- the balls should be numbered consecutively.
	e.g., 1,2 3, 4 or 4,5,6,7 etc.

Finally, the student should say whether it is possible to 
split all the balls in the box, into ball-groups accordingly.

Now, its your task to help the student to find whether it is possible or not.
if possible, print "true".
otherwise, print "false".


Input Format:
-------------
Line-1: Two integers N and S, number of balls and size of ball-group.
Line-2: N space separated integers, integers printed on each ball.

Output Format:
--------------
Print a boolean value, whether it is possible to split all the balls into groups.


Sample Input-1:
---------------
8 4
2 6 3 4 3 5 4 5

Sample Output-1:
----------------
true

Explanation:
-------------
Ball-groups are [2,3,4,5] and [3,4,5,6]


Sample Input-2:
---------------
12 3
12 2 9 5 3 4 13 7 6 8 11 7

Sample Output-2:
----------------
true

Explanation:
-------------
Ball-groups are [2,3,4], [5,6,7], [7,8,9] and [11,12,13]


Sample Input-3:
---------------
6 3
2 5 7 3 4 8

Sample Output-3:
----------------
false

Explanation:
-------------
you cannot form ball groups.



*/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    int arr[n];
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        mp[arr[i]]++;
    }
    vector<int> l;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        l.push_back(it->first);
    }
    sort(l.begin(), l.end());
    int i = 0;
    bool flag = true;
    while (i < l.size()) {
        int count = 0;
        int val = l[i];
        while (count < s && mp.count(val) && mp[val] > 0) {
            count++;
            mp[val]--;
            val++;
        }
        if (count < s) {
            flag = false;
            break;
        }
        while (i < l.size() && mp[l[i]] == 0) {
            i++;
        }
    }
    if(flag){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;
}
