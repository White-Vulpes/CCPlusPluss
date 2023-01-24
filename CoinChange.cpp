#include <bits/stdc++.h>
#include <iostream>
#include <conio.h>

/*
For N = 10 and S = {6,5,3,2}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5.
*/
using namespace std;

int count(int S[], int m, int n) {

    // If n is 0 then there is 1 solution
    // (do not include any coin)
    if (n == 0)
        return 1;

    // If n is less than 0 then no
    // solution exists
    if (n < 0)
        return 0;

    // If there are no coins and n
    // is greater than 0, then no
    // solution exist
    if (m <= 0 && n >= 1)
        return 0;

    // count is sum of solutions (i)
    // including S[m-1] (ii) excluding S[m-1]
    return count(S, m - 1, n) +
           count(S, m, n - S[m - 1]);
}

int main() {
    int n, m;
    cout << "Enter total amount to be changed : ";
    cin >> n;
    cout << "Enter no. of cents available : ";
    cin >> m;
    int *arr = new int(m);
    for (int i = 0; i < m; i++) {
        cout << "Enter element " << i + 1 << " : ";
        cin >> arr[i];
    }
    sort(arr, arr + m, greater<int>());
    for (int i = 0; i < m; i++) {
        cout << "[" << i + 1 << "]" << arr[i] << " ";
    }
    int ans = count(arr, m, n);
    cout << "\nAnswer : " << ans;
    return 0;
}