/*

In an online magazine, every day they will ask their readers a puzzle.
The puzzle has to be solved using the following rule set:
	- The puzzle is an 9*9 matrix, and consist of 9 -> 3*3 sub-matrices.
	- Each row in the puzzle should be filled with 1-9digits with out repetition
	- Each column in the puzzle should be filled with 1-9digits with out repetition.
	- Each 3*3 sub-matrix should be filled with 1-9 digits with out repetition.

You will be given the puzzle in the form of 9 strings, each string length is 9.
Your task is check whether the puzzle can be solved or not.
If it is possible to solve, print "true". Otherwise print "false".


Input Format:
-------------
9 Lines: Each line consists of a string  length-9, consist of digits[1-9] and '.' only

Output Format:
--------------
Print a boolean value.


Sample Input-1:
---------------
53..7....
6..195...
.98....6.
8...6...3
4..8.3..2
7...2...6
.6....28.
...419..5
....8..79

Sample Output-1:
----------------
true


Sample Input-2:
---------------
83..7....
6..195...
.98....1.
8...6...3
4..8.3..1
7...2...6
.6....28.
...419..5
....8..79

Sample Output-2:
----------------
false



*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<char>> board;
    for(int i=0;i<9;++i){
        vector<char> temp;
        for(int j=0;j<9;++j){
            char ss;
            cin>>ss;
            temp.push_back(ss);
        }
        board.push_back(temp);
    }
    bool flag = true;
    unordered_map<int, int> row[9];
    unordered_map<int, int> col[9];
    unordered_map<int, int> box[9];
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            char ch = board[i][j];
            if(ch != '.' && (row[i][ch]++>0 || col[j][ch]++>0 || box[i/3+3*(j/3)][ch]++>0)){
                flag = false;
                break;
            }
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