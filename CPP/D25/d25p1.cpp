// At university of Chicago a Computer Science programing faculty as a part of 
// teaching passion, in order to make newly joined students more enthusiastic 
// in learning the subject he will be giving a problem at the first day of semester.

// The student who tops they will be awarded with cash prize. In regard to this 
// he asked the students to work on concept related to strings, he gave a task to
// read a word and find the count of all the turn of phrases of the word, and 
// the phrases should be distinct.

// Now it’s time for you to create a method which satisfies the above program.
// A turn of phrases of a word is obtained by deleting 
// any number of characters (possibly zero) from the front of the word and
// any number of characters (possibly zero) from the back of the word.

// Input Format:
// -------------
// A single string, the word.

// Output Format:
// --------------
// Print an integer, number of distinct phrases possible.


// Sample Input-1:
// ---------------
// aabbaba

// Sample Output-1:
// ----------------
// 21

// Explanation:
// -------------
// The turn of phrases of the word, which are distinct as follows:
// a, b, aa, bb, ab, ba, aab, abb, bab, bba, aba, aabb, abba, bbab, baba, 
// aabba, abbab, bbaba, aabbab, abbaba, aabbaba


// Sample Input-2:
// ---------------
// kmithyd

// Sample Output-2:
// ----------------
// 28


#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        node* children[26];
        bool endword;
        node(){
            endword=false;
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
        }

};

class Trie{
    public:
        node* head=new node();
        int insert(string key){
            node* temp=head;
            for(int i=0;i<key.size();i++){
                int index=key[i]-'a';
                if(!temp->children[index]){
                    temp->children[index]=new node();
                }
                temp=temp->children[index];
            }
            if(temp->endword==true){
                return 0;
            }
            temp->endword=true;
            return 1;
        }

        int search(string key){
            node* temp=head;
            for(int i=0;i<26;i++){
                int index=key[i]-'a';
                if(!temp->children[index]){
                    return 0;
                }
                temp=temp->children[index];
            }
            return 1;
        }
};

int main(){
    string s;
    cin>>s;
    int ans=0;
    Trie t;
    //cout<<ans<<endl;
    for(int i=0;i<s.size();i++){
        //cout<<i<<endl;
        for(int j=i;j<s.size();j++){
            //cout<<j<<endl;
           ans+=t.insert(s.substr(i,j-i+1));
           //ans+=t.search(s.substr(i,j-i+1));
        }
    }
    cout<<ans<<endl;
}

