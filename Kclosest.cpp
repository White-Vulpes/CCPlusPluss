#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
    vector<vector<int>> ans;
    int x = 0, y = 0, index = 0;
    float distance[points.size()] = {0}, dist = 0;
    memset(distance, 0, points.size() * sizeof(float));
    for (int i = 0; i < points.size(); i++) {
        x = points[i][0];
        y = points[i][1];
        distance[i] = sqrt((x * x) + (y * y));
        cout << distance[i] << " ";
    }
    for (int i = 0; i < k; i++) {
        dist = INT_MAX;
        for (int j = 0; j < points.size(); j++) {
            if (dist > distance[j]) {
                index = j;
                dist = distance[j];
            }
        }
        distance[index] = INT_MAX;
        ans.push_back(points[index]);
    }
    return ans;
}

int main() {
    vector<vector<int>> points = {{3, 3}, {5, -1}, {-2, 4}};
    int k = 2;
    vector<vector<int>> point = kClosest(points, k);
    for(int i = 0;i < k;i++){ 
        cout << "\n" << point[i][0] << "," << point[i][1] << endl;
    }
}