#include<bits/stdc++.h>

using namespace std;

int threeSumClosest(vector<int> &nums, int target) {
    if (nums.size() < 3)
        return 0;
    int ans = INT_MAX,diff = INT_MAX;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; i++) {
        for (int j = i + 1, k = nums.size() - 1; j < k;) {
            int sum = nums[i] + nums[j] + nums[k];
            if(sum >= target){
                if(sum - target < diff){
                    ans = sum;
                    diff = sum - target;
                }
                while (nums[k] == nums[k - 1] && k - 1 > j) {
                    k--;
                }
                k--;
            }
            else{
                if(target - sum < diff){
                    ans = sum;
                    diff = target - sum;
                }
                while (nums[j] == nums[j + 1] && j + 1 < k) {
                    j++;
                }
                j++;
            }
        }
        while (nums[i] == nums[i + 1] && i + 1 < nums.size() - 2) {
            i++;
        }
    }

    return ans;
}
int main(){
    vector<int> a = {0, 0, 0};
    cout << threeSumClosest(a, 1);
}