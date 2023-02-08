// Malika taught a new fun time program practice for Engineering Students.
// As a part of this she has given set of N numbers, and asked the students 
// to perform the operations listed below:
// First, build the Binary Indexed Tree and then do the following,
//     1. sumRange(s1, s2) - return the sum of numbers between the indices 
//        s1 and s2, both are inclusive and 0<=s1<=s2<N.
//     2. update(ind, val) - update the value at the index 'ind' to 'val'.

// Your task is to solve this problem using Binary Indexed Tree concept.

// Input Format:
// -------------
// Line-1: Two integers N and Q, size of the array(set of numbers) and query count.
// Line-2: N space separated integers.
// Next Q lines: Three integers option, start/ind and end/val.

// Output Format:
// --------------
// An integer result, for every sumRange query.


// Sample Input:
// -------------
// 8 5
// 1 2 13 4 25 16 17 8
// 1 2 6		//sumRange
// 1 0 7		//sumRange
// 2 2 18	    //update
// 2 4 17	    //update
// 1 2 7		//sumRange

// Sample Output:
// --------------
// 75
// 86
// 80


import java.util.*;

public class Solution {
    int n;
    int arr[],ele[];
    public Solution(int nums[]){
        n = nums.length;
        ele = new int[n];
        arr = new int[n+1];
        for(int i=0;i<n;i++){
            updateHelper(i,nums[i]);
            ele[i] = nums[i];
        }
    }
    public void updateHelper(int i,int val){
        int ind = i+1;
        while(ind <= n){
            arr[ind] += val;
            ind += ind & (-ind);
        }
    }
    public void update(int i, int val) {
        int diff = val - ele[i];
        updateHelper(i,diff);
        ele[i] = val;
    }
    public int getSum(int i){
        int sum = 0;
        int ind = i;
        while(ind > 0){
            sum += arr[ind];
            ind -= ind & (-ind);
        }
        return sum;
    }
    public int sumRange(int i, int j) {
        return getSum(j+1) - getSum(i);
    }
}