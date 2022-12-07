// There are M students in a class, N students assigned with some tasks,
// and the other M-N students have no tasks to do.
// The task count of N students is given as an array, workload[], where N < M and
// workload[i] is the number of tasks assigned to Student-I. and Also given 
// an integer P, the maximum number of distribution opertions can be performed.

// A distribution operation is defined as follows:
// - Pick any student (Student_I), and distribute his/her workload with other 
// student (Student_J) who doesn't assigned any tasks yet in that class. 
// - e.g., if the student_I assigned 5 tasks, can be distributed as 1 task to 
// Student_I and 4 tasks to Student_J [ OR ] can be distributed as 2 tasks to 
// Student_I and 3 tasks to Student_J.

// Your task is to help the students of the class, to minimize their workload,
// by distributing their tasks with thier classmates, and 
// return the minimum possible workload after performing the operations.

// NOTE: You can assume that the number of students required to 
// distibute the workload are sufficient.

// Input Format:
// -------------
// Line-1: Two space separated integers, N and P
// Line-2: N space separated integers, workload[].

// Output Format:
// --------------
// Print an integer result.


// Sample Input-1:
// ---------------
// 4 4
// 3 6 12 3

// Sample Output-1:
// ----------------
// 3

// Explanation:
// ------------
// - Distribute the workload of 12 tasks like, One Student with 6 tasks
//   and Other Student with 6 tasks. Workload[]=[3,6,12,3] -> [3,6,6,6,3].
// - Distribute the workload of 6 tasks like, One Student with 3 tasks
//   and Other Student with 6 tasks. Workload[]=[3,6,6,6,3] -> [3,3,3,6,6,3].
// - Distribute the workload of 6 tasks like, One Student with 3 tasks
//   and Other Student with 6 tasks. Workload[]=[3,3,3,6,6,3] -> [3,3,3,3,3,6,3].
// - Distribute the workload of 6 tasks like, One Student with 3 tasks
//   and Other Student with 6 tasks. Workload[]=[3,3,3,3,3,6,3] -> [3,3,3,3,3,3,3,3].
// So, the minimized workload is 3 tasks.


// Sample Input-2:
// ---------------
// 3 4
// 6 15 24

// Sample Output-2:
// ----------------
// 8

// Explanation:
// ------------
// - Distribute the workload of 24 tasks like, One Student with 8 tasks
//   and Other Student with 16 tasks. Workload[]=[6,15,24] -> [6,15,8,16].
// - Distribute the workload of 16 tasks like, One Student with 8 tasks
//   and Other Student with 8 tasks. Workload[]=[6,15,8,16] -> [6,15,8,8,8].
// - Distribute the workload of 15 tasks like, One Student with 7 tasks
//   and Other Student with 7 tasks. Workload[]=[6,15,8,8,8] -> [6,7,8,8,8,8].
// - Distribute the workload of 8 tasks like, One Student with 4 tasks
//   and Other Student with 4 tasks. Workload[]=[6,7,8,8,8,8] -> [6,7,4,4,8,8,8].
// So, the minimized workload is 8 tasks.


#include<bits/stdc++.h>
using namespace std;

bool possible(int mid,vector<int> nums,int p){
    int c = 0;
    for(auto it:nums){
        if(it > mid){
            c+= (it/mid);
            if(it%mid==0){
                c--;
            }
        }
    }
    return c <= p;
}


int main(){
    int n,p;
    cin>>n>>p;
    vector<int> nums(n,0);
    int i = 0,j = -1e9;
    for(int i1=0;i1<n;++i1){
        cin>>nums[i1];
        j = max(j,nums[i1]);
    }
    int ans = 0;
    while(i<=j){
        int mid = i + (j-i)/2;
        if(possible(mid,nums,p)){
            ans = mid;
            j = mid-1;
        }
        else{
            i = mid+1;
        }
    }
    cout<<ans<<endl;
}