/*

You are given a phrase and a paper of size m*n.
So you can type exactly m * n characters on that paper.
i.e,. there are 'm' rows and in each row you can type 'n' characters
You need to type the phrase on the paper with some rules.

The rules are as follows:
    - A word in the phrase cannot be split into two lines.
    - The order of words in the phrase shuld not change.
    - Two consecutive words in a line must be separated by a single space.

Your task is to find out how many times the phrase can be typed on the paper.


Constraint:
-----------
Length of each word is <=10.

Input Format:
-------------
Line-1: Three space separated integers m, n, and s, grid size m*n, number of words.
Line-2: 's' space separated strings, set of words

Output Format:
--------------
Print an integer, no.of times set of words fit into the grid.


Sample Input-1:
---------------
2 8 2
socail distance

Sample Output-1:
----------------
1

Explanation:
------------
social__
distance


Sample Input-2:
---------------
3 6 3
a bc def

Sample Output-2:
----------------
2

Explanation:
------------
a_bc__
def_a_
bc_def

    

*/
// Time:  O(r + n * c)
// Space: O(n)

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        vector<int> wc(sentence.size());
        for (int i = 0; i < sentence.size(); ++i) {
            wc[i] = wordsFit(sentence, i, cols);
        }

        int words = 0, start = 0;
        for (int i = 0; i < rows; ++i) {
            words += wc[start];
            start = (start + wc[start]) % sentence.size();
        }
        return words / sentence.size();
    }

private:
    int wordsFit(const vector<string>& sentence, int start, int cols) {
        if (sentence[start].length() > cols) {
            return 0;
        }

        int sum = sentence[start].length(), count = 1;
        for (int i = (start + 1) % sentence.size();
             sum + 1 + sentence[i].length() <= cols;
             i = (i + 1) % sentence.size()) {
            sum += 1 + sentence[i].length();
            ++count;
        }
        return count;
    }
};