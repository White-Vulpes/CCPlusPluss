#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums) {
    if (nums.size() < 3)
        return {};
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; i++) {
        for (int j = i + 1, k = nums.size() - 1; j < k;) {
            cout << j << "  " << k << "  " << i << endl
                 << nums[j] << "  " << nums[k] << "  " << nums[i] << endl;
            if (nums[i] + nums[j] + nums[k] == 0) {
                cout << "adding to ans " << endl;
                ans.push_back({nums[i], nums[j], nums[k]});
                while(nums[j] == nums[j + 1] && j + 1 < k)
                    j++;
                while(nums[k] == nums[k - 1] && k - 1 > j)
                    k--;
                j++;
                k--;
            } else if (nums[i] + nums[j] + nums[k] < 0) {
                while(nums[j] == nums[j + 1] && j + 1 < k)
                    j++;
                j++;
            } else {
                while (nums[k] == nums[k - 1] && k - 1 > j)
                    k--;
                k--;
            }
        }
        while(nums[i] == nums[i + 1] && i + 1 < nums.size() - 2) {
            cout << "found same i" << endl;
            i++;
        }
    }
    return ans;
}
int main() {
    vector<int> a = {2, 0, -2, -5, -5, -3, 2, -4};
    vector<vector<int>> vec = threeSum(a);
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
} //-4 -1 -1 0 1 2