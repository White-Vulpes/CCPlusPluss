#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target) {
    vector<vector<int>> ans;
    int a, b, c, d;
    for(a = 0;)
}

int main(){
    vector<int> a = {};
    int t = 0;
    vector<vector<int>> ans = fourSum(a, t);
    for(int i = 0;i < ans.size();i++){
        for(int j = 0;j < ans[i].size();i++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}