/*

Gachibowli Diwakar is a tremendous bowler in Indian Cricket Team.
Diwakar has played in N Series of Games, and in each series he has taken some 
number of wickets. Now, Gachibowli Diwakar's wickets count is arranged in 
ascending order which is a non-negative integer. Create a method to generate 
the Gachibowli Diwakar's Wicket-index as W-index

According to the definition of W-index, Gachibowli Diwakar has index W,
if W of his 'N' series have at least W wickets each, 
and the other 'N-W' series have 
no more than W wickets each.

Note:
-----
If there are several possible values for W, the maximum one is taken as the W-index.

Input Format:
-------------
Line-1: An integer N, number of series played by Diwakar.
Line-2: N space separated integers, number of wickets in ascending order.

Output Format:
--------------
Print an integer, value of index -W.


Sample Input-1:
---------------
6
0 1 3 4 5 6

Sample Output-1:
----------------
3

Explanation:
------------
[0, 1, 3, 4, 5, 6] means the Gachibowli Diwakar has 6 series in total and
in each series he had taken 0, 1, 3, 4, 5, 6 wickets respectively.
Since Gachibowli Diwakar has 3 series with at least 3 wickets each and the
remaining three with no more than 3 wickets each, his W index is 3.


Sample Input-2:
---------------
10
1 3 7 10 12 20 21 24 26 32

Sample Output-2:
----------------
7



*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int res = 0, l = 0, r = n - 2;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        int count = n - (mid + 1);
        if (arr[mid + 1] >= count) {
            if (arr[mid] <= count) {
                res = max(res, count);
            }
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << res << endl;
    return 0;
}
