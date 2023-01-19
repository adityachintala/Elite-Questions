// There is a String given as input, it is a sequence of integer-values and 
// arithmetic-operators. Your task is to print the resultant values after 
// evaluating all the different possible ways to group integer-values 
// and arithmetic-operators. 

// Note: Print the evaluated values in sorted order.

// Input Format:
// -------------
// Read a string

// Output Format:
// --------------
// Print the evaluated values in sorted order

// Sample input-1
// ------------
// 4-2-1

// Sample output-1
// ---------------
// 1 3

// Explanation
// -----------
// ((4-2)-1)=1
// (4-(2-1))=3


// Sample input-2
// ------------
// 3*5-2*6

// Sample output-2
// ---------------
// -21 3 54 54 78

// Explanation
// ------------
// (3*(5-(2*6))) = -21
// ((3*5)-(2*6)) = 3
// ((3*(5-2))*6) = 54
// (3*((5-2)*6)) = 54
// (((3*5)-2)*6) = 78

#include<bits/stdc++.h>
using namespace std;

int perform(int x, int y, char op) {
    if(op == '+') return x + y;
    if(op == '-') return x - y;
    if(op == '*') return x * y;
    return 0;
}
    
vector<int> solve1(string exp) {
    vector<int> results;
    bool isNumber = 1;
    for(int i = 0; i < exp.length(); i++) {
        if(!isdigit(exp[i])) {
            isNumber = 0;
            vector<int> left = solve1(exp.substr(0, i));
            vector<int> right = solve1(exp.substr(i + 1));
            for(int x : left) {
                for(int y : right) {
                    int val = perform(x, y, exp[i]);
                    results.push_back(val);
                }
            }
            
        }
    }
    if(isNumber == 1) results.push_back(stoi(exp));
    return results;
}

int main(){
    string exp;
    cin>>exp;
    vector<int> ans = solve1(exp);
    sort(ans.begin(),ans.end());
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}
