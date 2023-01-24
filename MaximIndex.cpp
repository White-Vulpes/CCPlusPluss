#include <iostream>

using namespace std;

/*
Given an array A[] of N positive integers. The task is to find the maximum of j - i subjected to the constraint of A[i] < A[j] and i < j.

Your Task:
The task is to complete the function maxIndexDiff() which finds and returns maximum index difference. Printing the output will be handled by driver code. Return -1 in case no such index is found.

Expected Time Complexity: O(N) ** Most Important **
Expected Auxiliary Space: O(N)
*/

int maxIndexDiff(int A[], int N) {
    int ans = 0,i = 0, j = N-1;
    while(i < N - ans - 1){
        if (A[i] <= A[j] && ans < j - i) {
            ans = j - i;
        }
        if (j - i == 0) {
            i++;
            j = N;
        }
        j--;
    }
    return ans;
}
int main() {
    int A[] = {65, 6, 74, 94, 56, 89, 9, 63, 75, 25, 34, 68, 93, 48, 16};
    int N = 15;
    cout << maxIndexDiff(A, N);
}
