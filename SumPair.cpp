#include<bits/stdc++.h>

using namespace std;

/*
Given a sorted array arr[] of size N and a number X, find a pair in array whose sum is closest to X.

Example 1:

Input:
N = 6, X = 54
arr[] = {10, 22, 28, 29, 30, 40}
Output: 22 30
Explanation: As 22 + 30 = 52 is closest to 54.

Example 2:

Input:
N = 5, X = 10
arr[] = {1, 2, 3, 4, 5}
Output: 4 5
Explanation: As 4 + 5 = 9 is closest to 10.

Your Task:
You don't need to read input or print anything. Your task is to complete the function sumClosest() which takes arr[] of size n and x as input parameters and returns a list containing 2 integers denoting the required pair. If multiple pairs are possible return the largest sum pair.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
*/


vector<int> sumClosest(vector<int> arr, int x) {
    int i = 0, j = arr.size() - 1;
    int max = arr[i] + arr[j];
    vector<int> ans;
    for (;i < arr.size() && j > i;) {
        if (arr[i] + arr[j] <= x) {
            if (arr[i] + arr[j] >= max){
                max = arr[i] + arr[j];
                ans.assign(0, 0);
                ans.push_back(arr[i]);
                ans.push_back(arr[j]);
            }
            i++;
        } else {
            j--;
        }
    }
    return {ans[0],ans[1]};
}

int main(){
    vector<int> arr = {4, 4, 9, 20, 21, 25, 28, 29, 33, 39, 59, 62, 66, 74, 79, 80, 81, 82, 91, 92, 93, 97, 98, 100};
    int n = arr.size();
    int x = 108;
    vector<int> a = sumClosest(arr,x);
    for(int i = 0;i < a.size();i++){
        cout << a[i] << " ";
    }
}