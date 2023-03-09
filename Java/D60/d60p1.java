// Kohinoor diamond is robbed by Hrithik, He kept the diamond in a suitcase, 
// the suitcase has a lock with 4 circular wheels, and each wheel consist of
// 0-9 digits in the order 0,1,2,3,4,5,6,7,8,9 only.
// You can rotate a wheel from 0 to 9 or 9 to 0.

// As the diamond is most valuable, the lock has some traps,
// if anybody try to unlock the suitcase and reached any one of the traps,
// the suitcase will be blasted. And you will be dead.

// Initially, the suitcase lock is set to 0000.
// and you will be given the unlock key, your task to find and print
// the minimum number of rotations required to unlock the suitcase.
// If it is not possible to unlock the suitcase without blasting, print -1.

// NOTE:
// In one rotation you can choose any one wheel and 
// rotate to its next or previous digit.


// Input Format:
// -------------
// Line-1: space separated strings, each string of length 4 and contains only digits [0-9]
// Line-2: A string, key to unlock.

// Output Format:
// --------------
// Print an integer, the minimum number of rotations required to unlock.


// Sample Input-1:
// ---------------
//  0302 0202 0203 2323 3003
//  0303 

// Sample Output-1:
// ----------------
// 8

// Explanation:
// ------------
// To unlock the suitcase the valid rotations are as follows:
// 0000 > 1000 > 1100 > 1200 > 1201 > 1202 > 1302 > 1303 > 0303.


// Sample Input-2:
// ---------------
// 6656 6676 6766 6566 5666 7666 6665 6667
// 6666 

// Sample Output-2:
// ----------------
// -1

// Explanation:
// ------------
// You can't unlock the suitcase.

import java.util.*;

/**
 * d60p1
 */
public class d60p1 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] days = sc.nextLine().split(" ");
        String dest = sc.nextLine();
        if(Arrays.asList(days).contains(dest) || Arrays.asList(days).contains("0000")){
            System.out.println(-1);
        }
        else{
            Queue<String> q = new LinkedList<String>();
            q.add("0000");
            boolean flag = false;
            for (int steps = 0; !q.isEmpty(); ++steps) {
                if(flag){break;}
                for (int i = q.size(); i > 0; --i) {
                    String curr = q.poll();
                    if (curr.equals(dest)){
                        System.out.println(steps);
                        flag=true;
                        break;
                    }
                    if(flag){break;}
                    for (String nei : neighbors(curr)) {
                        if (Arrays.asList(days).contains(nei)) continue;
                        q.add(nei);
                    }
                    if(flag){break;}
                }
            }
            if(!flag){
                System.out.println(-1);
            }
        }
        sc.close();
    }
    
    public static List<String> neighbors(String str){
        List<String> neighs = new ArrayList<String>();
        for(int i=0;i<=3;++i){
            for(int j=-1;j<=1;j+=2){
                String temp = str;
                temp = temp.substring(0,i) + ((temp.charAt(i)-'0'+j+10)%10) + temp.substring(i+1);
                neighs.add(temp);
            }
        }
        return neighs;
    }

}