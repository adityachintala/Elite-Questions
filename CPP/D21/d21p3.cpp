// Mr Toronto working with operators in programming language.
// He is given statement S, which is a valid statement and consist of digits [0-9] 
// and characters '?', ':', 'Y', 'N', where Y indiactes true and N indicates false.
// And the statement conatins only numbers with single digits.
// (>=10 value is not allowed)

// The operator '?' works as follows:
// 	- if S="Y?1:2" - as Y means true, it will return 1.
// 	- if S="N?1:2" - as N means false, it will return 2.

// Your task is to help Mr Toronto to execute the statement S and return the result.
// The result must be either a digit [0-9] or "Y" or "N".

// Input Format:
// -------------
// A string S, a valid statement.

// Output Format:
// --------------
// Print a string, the result of the statement S.


// Sample Input-1:
// ---------------
// Y?N?3:4:2

// Sample Output-1:
// ----------------
// 4

// Explanation:
// ------------
// Given statement is Y?N?3:4:2 -> Y?(N?3:4):2 
// Y means "true", So you have to execute N?3:4
// N means "false", So the answer is 4.


// Sample Input-2:
// ---------------
// N?Y?N?N:Y:N:Y

// Sample Output-2:
// ----------------
// Y

// Explanation:
// ------------
// Given statement is N?Y?N?N:Y:N:Y -> N?(Y?(N?N:Y):N):Y
// N means "false", So the answer is Y.


#include <bits/stdc++.h>

using namespace std;

string solve(string s) {
    int n = s.length();
    if (n == 1) {
        return s;
    }
    int ind = -1, cnt = 0;
    for (int i = 3; i < n; i++) {
        char ch = s[i];
        if (ch == ':') {
            if (cnt == 0) {
                ind = i;
                break;
            } else {
                cnt--;
            }
        }
        if (ch == '?') {
            cnt++;
        }
    }
    if (s[0] == 'Y') {
        return solve(s.substr(2, ind - 2));
    }
    return solve(s.substr(ind + 1));
}

int main() {
    string s;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}




