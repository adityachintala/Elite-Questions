/*

Given a nokia phone,with the following dialpad.
		1 2 3
		4 5 6
		7 8 9
		* 0 #
And You are given an L band to dial the number,  
Using the L band you can dial the number as follows, 
You can start with any digit,
	if you are at digit 1, next digit you can choose {6,8}
	if you are at digit 2, next digit you can choose {7,9}
	if you are at digit 3, next digit you can choose {4,8}
	and so on..

Now your task is to find how many distinct numbers of length N you can dial.

Note: Numbers should contain only digits, no {* , #}.
Answer is modulo 1000000007.

Input Format:
-----------------
An integer N, length of numbers
 
Output Format:
------------------
Print an integer, number of distinct numbers you can dial.


Sample Input-1:
---------------
1

Sample Output-1:
----------------
10

Explanation:
-------------
To dial a number of length 1, you can dial all digits.


Sample Input-2:
---------------
2

Sample Output-2:
----------------
20

Explanation:
------------
To dial a number of length 2, the possible numbers are
{04, 06, 16, 18, 27, 29, 34, 38, 40, 43, 49, 60, 61, 67, 72, 76, 81, 83, 92, 94}

Sample Input-3:
---------------
5

Sample Output-3:
----------------
240




*/


int knightDialer(int n)
{
    vector<vector<int>> a = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};
    int mod = 1e9 + 7;
    long long int ans = 0;
    vector<vector<long long int>> dp(n + 1, vector<long long int>(10, 0));
    for (int i = 0; i < 10; i++)
        dp[1][i] = 1;

    for (int i = 2; i < n + 1; i++)
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < a[j].size(); k++)
                dp[i][j] += dp[i - 1][a[j][k]];
            dp[i][j] %= mod;
        }

    for (auto x : dp[n])
        ans += x;

    return ans % mod;
}
