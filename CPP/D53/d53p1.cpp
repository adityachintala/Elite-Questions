/*

For Siddarth's Birthday his friends planned cake cutting.
On top of the cake there are two lines of candles, 
all the candles with different heights. 
The lines are parallel lines, line-P and line-Q .
Siddarth has to blow all the candles in one go.

So, he can swap one candle at a time, from P and Q and 
the position of the candles in their line should be same.

At the end of the swaps, The candles in set P and set Q, 
should be in ascending order of their heights.

You will be heights of the candles initially in P and Q, after placing in parallel lines.

Your task is to find the minimum number of swaps required
to arrange the candles in P and Q in ascending orer.

Note: It is guaranteed that the answer is always possible.

Input Format:
-------------
Line-1: An integer N, num of candles in P and Q.
Line-2: N space separated integers, heights of the candles in Line-P.
Line-3: N space separated integers, heights of the candles in Line-Q.

Output Format:
--------------
Print an integer, minimum number of swaps required.


Sample Input-1:
---------------
4
1 3 5 4
1 2 3 7

Sample Output-1:
----------------
1

Explanation:
------------
Swap the 4th candle in P and Q. 
Then the heights of the candles in P = [1, 3, 5, 7],  Q = [1, 2, 3, 4]
Both are in ascending order.


Sample Input-2:
---------------
7
1 3 5 8 14 13 14
2 5 7 6 11 15 16

Sample Output-2:
----------------
2

Explanation:
------------
Swap the 4th, 5th candles in P and Q. 
Then the heights of the candles in 
P = [1, 3, 5, 6, 11, 13, 14],  
Q = [2, 5, 7, 8, 14, 15, 16]
Both are in ascending order.

*/




#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> A(N,0),B(N,0);
    for(int i=0;i<N;++i){
        cin>>A[i];
    }
    for(int i=0;i<N;++i){
        cin>>B[i];
    }
    int not_swap[1000] = {0};
    int swap[1000] = {1};
    for (int i = 1; i < N; ++i) {
        not_swap[i] = swap[i] = N;
        if (A[i - 1] < A[i] && B[i - 1] < B[i]) {
            swap[i] = swap[i - 1] + 1;
            not_swap[i] = not_swap[i - 1];
        }
        if (A[i - 1] < B[i] && B[i - 1] < A[i]) {
            swap[i] = min(swap[i], not_swap[i - 1] + 1);
            not_swap[i] = min(not_swap[i], swap[i - 1]);
        }
    }
    cout<<min(swap[N - 1], not_swap[N - 1]);
    return 0;
}