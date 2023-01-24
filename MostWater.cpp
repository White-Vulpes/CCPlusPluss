#include <bits/stdc++.h>

using namespace std;

int maxArea(vector<int> &height) {
    int max = 0, area = 0, maxele;
    maxele = max_element(height.begin(), height.end()) - height.begin();
    for (int i = 0,j = height.size(); i < j;) {
        if(height[i] > height[j]){
            area = height[j] * (j - i);
        }
        else{
            area = height[i] * (j - i);
        }
        if(area > max){
            max = area;
        }
        if(height[i + 1] > height[j - 1]){
            i++;
        }
        else{
            j--;
        }
    }

    return max;
}

int main() {
    vector<int> h = {1, 2, 1};
    cout << maxArea(h);
}

//TODO Complete
