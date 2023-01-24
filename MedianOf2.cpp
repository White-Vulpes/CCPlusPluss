#include<bits/stdc++.h>

using namespace std;

/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    
    vector<int> a;
    int i = 0, j = 0;
    for (; i < nums1.size() && j < nums2.size();) {
        if (nums1[i] > nums2[j]){
            a.push_back(nums2[j]);
            j++;
        } else {
            a.push_back(nums1[i]);
            i++;
        }
    }
    for (; i < nums1.size(); i++) {
        a.push_back(nums1[i]);
    }
    for (; j < nums2.size(); j++) {
        a.push_back(nums2[j]);
    }
    //for (int x : a)
    //    cout << x << " ";
    if(a.size() % 2 == 0)
        return (double)(a[(int)(a.size() / 2)] + a[(int)(a.size() / 2) - 1]) / 2;
    else 
        return a[a.size() / 2];
}

int main(){
    vector<int> nums1 = {};
    vector<int> nums2 = {1};
    cout << findMedianSortedArrays(nums1, nums2);
}