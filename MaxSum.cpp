#include <iostream>

using namespace std;

/*
Given two sorted arrays A and B of size M and N respectively. Each array contains only distinct elements but may have some elements in common with the other array. Find the maximum sum of a path from the beginning of any array to the end of any of the two arrays. We can switch from one array to another array only at the common elements.
Note: Only one repeated value is considered in the valid path sum.

Expected Time Complexity: O(M + N)
Expected Auxiliary Space: O(1)
*/

int max_path_sum(int A[], int B[], int m, int n) {
    int sum1 = 0;
    int sum2 = 0,i = 0, j = 0;

    for (i = 0, j = 0; j < n && i < m;) {
        if (A[i] < B[j]) {
            sum1 += A[i];
            i++;
        } else if (A[i] > B[j]) {
            sum2 += B[j];
            j++;
        } else if (A[i] == B[j]) {
            sum1 += A[i];
            sum2 += B[j];
            i++;
            j++;
            if (sum1 > sum2) {
                sum2 = sum1;
            } else {
                sum1 = sum2;
            }
        }
    }
    for (; i < m; i++) {
        sum1 += A[i];
    }
    for (; j < n; j++) {
        sum2 += B[j];
    }
    if (sum1 > sum2) {
        return sum1;
    } else {
        return sum2;
    }
}
int main() {
    int A[] = {1,2,4};
    int B[] = {1,2,7};
    int n = 3;
    int m = 3;
    cout << max_path_sum(A, B, n, m);
}