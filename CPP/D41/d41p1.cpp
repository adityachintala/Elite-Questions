/*

Mr Venu working with statements.
Each statement consists of only lowercase alphabets and whitespaces, 
and each statement neither starts nor ends with a whitespace
and each word in the statement separated by a single whitespace only.

Mr Venu's task is to perform the join operation on these statements:
The joining operations is performed as follows:
	- If the last word of a statement-1 and first word of statement-2 are same,
	then you can join the statements-1 & statement-2 and 
	the joining word will appears once in the result statement.
	- It is not allowed to join the statements with itself.
Note that the order of joining the statements matters.

You will be given N statements.
Your task is to help Mr Venu to join the statements, and 
return them as a list of distinct statements in lexicographic order.


Input Format:
-------------
Line-1: An integer N, number of statements.
Next N lines: Single line String, the statement with one or more words.

Output Format:
--------------
Print the list of strings, the joined statements.


Sample Input-1:
---------------
3
write the code
code in java
java code

Sample Output-1:
----------------
[code in java code, java code in java, write the code in java]


Sample Input-2:
---------------
4
programming language
language is java
language is python
java is based on oops concepts

Sample Output-2:
----------------
[language is java is based on oops concepts, 
programming language is java, 
programming language is python]


Sample Input-3:
---------------
3
A B C
B C A
C A B

Sample Output-3:
----------------
[A B C A B, B C A B C, C A B C A]

NOTE: You have to print the list in a single line.



*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    cin.ignore();
    vector<vector<string>> input;
    for(int i=0;i<n;++i){
        string p,k;
        getline(cin,p);
        vector<string> v;
        istringstream obj(p);
        while(obj>>k){
            v.push_back(k);
        }
        input.push_back(v);
    }
    set<string> result;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(i!=j){
                if(input[i].back()==input[j].front()){
                    string res="";
                    for(int k=0;k<input[i].size();++k){
                        res+=input[i][k];
                        res+=" ";
                    }
                    for(int k=1;k<input[j].size();++k){
                        res+=input[j][k];
                        if(k!=input[j].size()-1){
                            res+=" ";
                        }
                    }
                    result.insert(res);
                }
            }
        }
    }
    for(auto it:result){
        cout<<it<<" ";
    }
    return 0;
}