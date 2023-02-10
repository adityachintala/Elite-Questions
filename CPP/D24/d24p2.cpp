// "Emphatic Pronunciation" of a given word is where we take the word and
// replicate some of the letter to emphasize their impact.

// Instead of saying 'oh my god', someone may say "ohhh myyy goddd", 
// We define emphatic pronunciation of a word, which is derived by replicating 
// a group (or single) of letters in the original word. 

// So that the replicated group is atleast 3 characters or more and 
// greater than or equal to size of original group. 
// For example Good -> Goood is an emphatic pronunciation,
// but Goodd is not because in Goodd the 'd' are only occuring twice consecutively.
 
// In the question you are given the "Emphatic pronunciation" word, 
// you have to findout how many words can legal result in the 
// "emphatic pronunciation" word.

// Input Format:
// -------------
// Line-1 -> A String contains a single word, Emphatic Pronunciation word
// Line-2 -> Space seperated word/s

// Output Format:
// --------------
// Print an integer as your result


// Sample Input-1:
// ---------------
// Goood
// Good

// Sample Output-1:
// ----------------
// 1


// Sample Input-2:
// ---------------
// heeelllooo
// hello hi helo

// Sample Output-2:
// ----------------
// 2


#include<bits/stdc++.h>
using namespace std;

void solve(vector<string> words,string s){
    vector<char> ht;
    vector<int> ht1;
    int c=1;
    char temp=s[0];
    for(int i=1;i<s.size();i++){
        if(temp==s[i]){
            c++;
        }
        else{
            ht.push_back(temp);
            ht1.push_back(c);
            c=1;
            temp=s[i];
        }
    }
    ht.push_back(temp);
    ht1.push_back(c);
    int count=0;
    string x;
    int flag=0;
    for(int i=0;i<words.size();i++){
        x=words[i];
        //cout<<x<<endl;
        temp=x[0];
        c=1;
        int o=0;
        flag=1;
        int j;
        //cout<<x<<endl;
        for(j=1;j<x.size();j++){
            if(find(ht.begin(),ht.end(),x[j])==ht.end()){
                flag=0;
                break;
            }
            if(temp==x[j]){
                c++;
            }
            if(temp!=x[j] || j==(x.size()-1)){
                //cout<<flag<<endl;
                if(ht[o]!=temp){
                    flag=0;
                    break;
                }
                else{
                    if(ht1[o]!=c && ht1[o]<3){
                        flag=0;
                        break;
                    }
                    if(ht1[o]<c){
                        flag=0;
                        break;
                    }
                }
                temp=x[j];
                c=1;
                o++;
            }
        }
        //cout<<flag<<endl;
        if(flag==1){
            count++;
        }
    }
    cout<<count<<endl;
}

int main(){
    string s;
    string word;
    cin>>s;
    cin.ignore();
    getline(cin,word);
    vector<string> words;
    string x="";
    istringstream obj(word);
    while(obj>>x){
        words.push_back(x);
    }
    solve(words,s);
}