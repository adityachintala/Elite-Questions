/*
There are M students in a class, N students assigned with some tasks,
and the other M-N students have no tasks to do.
The task count of N students is given as an array, workload[], where N < M and
workload[i] is the number of tasks assigned to Student-I. and Also given 
an integer P, the maximum number of distribution opertions can be performed.

A distribution operation is defined as follows:
- Pick any student (Student_I), and distribute his/her workload with other 
student (Student_J) who doesn't assigned any tasks yet in that class. 
- e.g., if the student_I assigned 5 tasks, can be distributed as 1 task to 
Student_I and 4 tasks to Student_J [ OR ] can be distributed as 2 tasks to 
Student_I and 3 tasks to Student_J.

Your task is to help the students of the class, to minimize their workload,
by distributing their tasks with thier classmates, and 
return the minimum possible workload after performing the operations.

NOTE: You can assume that the number of students required to 
distibute the workload are sufficient.

Input Format:
-------------
Line-1: Two space separated integers, N and P
Line-2: N space separated integers, workload[].

Output Format:
--------------
Print an integer result.


Sample Input-1:
---------------
4 4
3 6 12 3

Sample Output-1:
----------------
3

Explanation:
------------
- Distribute the workload of 12 tasks like, One Student with 6 tasks
  and Other Student with 6 tasks. Workload[]=[3,6,12,3] -> [3,6,6,6,3].
- Distribute the workload of 6 tasks like, One Student with 3 tasks
  and Other Student with 6 tasks. Workload[]=[3,6,6,6,3] -> [3,3,3,6,6,3].
- Distribute the workload of 6 tasks like, One Student with 3 tasks
  and Other Student with 6 tasks. Workload[]=[3,3,3,6,6,3] -> [3,3,3,3,3,6,3].
- Distribute the workload of 6 tasks like, One Student with 3 tasks
  and Other Student with 6 tasks. Workload[]=[3,3,3,3,3,6,3] -> [3,3,3,3,3,3,3,3].
So, the minimized workload is 3 tasks.


Sample Input-2:
---------------
3 4
6 15 24

Sample Output-2:
----------------
8

Explanation:
------------
- Distribute the workload of 24 tasks like, One Student with 8 tasks
  and Other Student with 16 tasks. Workload[]=[6,15,24] -> [6,15,8,16].
- Distribute the workload of 16 tasks like, One Student with 8 tasks
  and Other Student with 8 tasks. Workload[]=[6,15,8,16] -> [6,15,8,8,8].
- Distribute the workload of 15 tasks like, One Student with 7 tasks
  and Other Student with 7 tasks. Workload[]=[6,15,8,8,8] -> [6,7,8,8,8,8].
- Distribute the workload of 8 tasks like, One Student with 4 tasks
  and Other Student with 4 tasks. Workload[]=[6,7,8,8,8,8] -> [6,7,4,4,8,8,8].
So, the minimized workload is 8 tasks.

*/

import java.util.*;

public class d8p1 {

  static int goldsmansachs(int workload[], int p) {
    int low = Integer.MAX_VALUE, high = 0;
    for (int i : workload) {
      low = Math.min(low, i);
      high = Math.max(high, i);
    }
    while (low < high) {
      int mid = (low) + (high - low) / 2;
      int count = 0;
      for (int i : workload) {
        count += (i - 1) / mid;
      }
      if (count <= p) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }
    return low;
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int p = sc.nextInt();
    int workload[] = new int[n];
    for (int i = 0; i < n; i++) {
      workload[i] = sc.nextInt();
    }
    sc.close();
    System.out.println(goldsmansachs(workload, p));
  }

}