#include<bits/stdc++.h>

using namespace std;

/*
The cost of stock on each day is given in an array A[] of size N. Find all the days on which you buy and sell the stock so that in between those days your profit is maximum.
Note: There may be multiple possible solutions. Return any one of them. Any correct solution will result in an output of 1, whereas wrong solutions will result in an output of 0.

Example 1:

Input:
N = 7
A[] = {100,180,260,310,40,535,695}
Output:
1
Explanation:
One possible solution is (0 3) (4 6)
We can buy stock on day 0,
and sell it on 3rd day, which will 
give us maximum profit. Now, we buy 
stock on day 4 and sell it on day 6.
Example 2:

Input:
N = 5
A[] = {4,2,2,2,4}
Output:
1
Explanation:
There are multiple possible solutions.
one of them is (3 4)
We can buy stock on day 3,
and sell it on 4th day, which will 
give us maximum profit.

Your Task:
The task is to complete the function stockBuySell() which takes an array A[] and N as input parameters and finds the days of buying and selling stock. The function must return a 2D list of integers containing all the buy-sell pairs. If there is No Profit, return an empty list.

 

Note: Since there can be multiple solutions, the driver code will return 1 if your answer is correct, otherwise, it will return 0. In case there's no profit the driver code will return the string "No Profit" for a correct solution.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


Constraints:
2 ≤ N ≤ 106
0 ≤ A[i] ≤ 106
*/

vector<vector<int>> stockBuySell(vector<int> A, int n) {
    vector<vector<int>> ans;
    int num = A[0];
    vector<int> b;
    b.push_back(0);
    for (int i = 1; i < n; i++) {
        if (A[i-1] < A[i]) {
        }
        else{
            b.push_back(i - 1);
            num = A[i];
            if(b[0] != b[1]){
                ans.push_back(b);
            }
            b.assign(0, 0);
            b.push_back(i);
        }
        if(i == n-1){
            b.push_back(i);
            num = A[i];
            if (b[0] != b[1])
                ans.push_back(b);
        }
    }
    return ans;
}
int main(){
    vector<int> arr = {81,69};
    int n = 2;
    vector<vector<int>> v = stockBuySell(arr,n);
    for (int i = 0; i < v.size(); i++) { // printing the 2D vector.
        for (int j = 0; j < v[i].size(); j++)
            cout << v[i][j] << " ";
        cout << endl;
    }
}