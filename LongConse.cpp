#include<bits/stdc++.h>

using namespace std;

/*
Given an array of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.
 

Example 1:

Input:
N = 7
a[] = {2,6,1,9,4,5,3}
Output:
6
Explanation:
The consecutive numbers here
are 1, 2, 3, 4, 5, 6. These 6 
numbers form the longest consecutive
subsquence.
Example 2:

Input:
N = 7
a[] = {1,9,3,10,4,20,2}
Output:
4
Explanation:
1, 2, 3, 4 is the longest
consecutive subsequence.

Your Task:
You don't need to read input or print anything. Your task is to complete the function findLongestConseqSubseq() which takes the array arr[] and the size of the array as inputs and returns the length of the longest subsequence of consecutive integers. 


Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).


Constraints:
1 <= N <= 105
0 <= a[i] <= 105
*/

int findLongestConseqSubseq(int arr[], int n) {
    sort(arr,arr + n);
    int temp = 0,max = 0;
    for(int i = 0;i < n;i++){
        if(arr[i] == arr[i+1]){
        }
        else if(arr[i] == arr[i + 1] - 1){
            temp++;
        }
        else if(max < temp){
            max = temp;
            temp = 0;
        }else{
            temp = 0;
        }
    }
    return max + 1;
}

int main(){
    int arr[] = {6, 6, 2, 3, 1, 4, 1, 5, 6, 2, 8, 7, 4, 2, 1, 3, 4, 5, 9, 6};
    int n = 20;
    cout << findLongestConseqSubseq(arr,n);
}