/*

Students are given T-shirt numbers either 0 or 1 and standing in a line.
The line become circular. We have to group all students with T-shirt No with 1's
together at any location by swapping their locations. 

Your task is to return the minimum number of swaps required to group all 
students with T-shirt number 1's

A swap is taking two distinct positions in the line and swapping their values.

A line is said to be circular if the first student and last student are adjacent.

Input Format
------------
Line1:An integer N represents no of students
Line2:Space separated 0's or 1's represents T-shirt numbers

Output Format
-------------
An integer represents no of swaps

 

Sample Input-1:
---------------
7
0 1 0 1 1 0 0

Sample Output-1:
----------------
1

Explanation:
------------
Here are a few of the ways to group all the 1's together:
  0 0 1 1 1 0 0 using 1 swap.
  0 1 1 1 0 0 0 using 1 swap.
  1 1 1 0 0 0 1 using 2 swaps (using the circular property of the array).
  There is no way to group all 1's together with 0 swaps.
  Thus, the minimum number of swaps required is 1.


Sample Input-2:
---------------
9
0 1 1 1 0 0 1 1 0

Sample Output-2:
----------------
2

Explanation:
------------
Here are a few of the ways to group all the 1's together:
 1 1 1 0  0 0 0 1 1 using 2 swaps (using the circular property of the array).
 1 1 1 1 1 0 0 0 0 using 2 swaps.
 There is no way to group all 1's together with 0 or 1 swaps.
 Thus, the minimum number of swaps required is 2.



Sample Input-3:
---------------
5
1 1 0 0 1 

Sample Output-3:
----------------
0

Explanation:
------------
All the 1's are already grouped together due to the circular property of the array.
Thus, the minimum number of swaps required is 0.


*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<int> v(n);
    int cnt=0;
    for(int i=0;i<n;i++){
        cin>>v[i];if(v[i]==1)cnt++;
    }
    int temp = 0;
    for(int k=0;k<cnt;k++){
        if(v[k]==1){
            temp++;
        }
    }
    int j=cnt,i=0,fincnt=temp;
    for(int i=0;i<n;i++){
        v.push_back(v[i]);
    }
    int x=cnt-1;
    n = v.size();
    while(j<n){
        if(v[j]==1){
            temp++;
        }
        if(v[i]==1){
            temp--;
        }
        fincnt= max(fincnt,temp);
        j++;i++;
    }
    cout<<cnt-fincnt<<endl;
}