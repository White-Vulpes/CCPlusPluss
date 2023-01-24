#include <bits/stdc++.h>

using namespace std;

vector<string> data = {{""}, {""}, {"abc"}, {"def"}, {"ghi"}, {"jkl"}, {"mno"}, {"pqrs"}, {"tuv"}, {"wxyz"}};

void backtracking(vector<string> &ans, string d, int index, int i, string &temp) {
    if(temp.length() == d.length()){
        ans.push_back(temp);
        return ;
    }
    if(i == data[d[index] - '0'].length()){
        //temp.pop_back();
        return;
    }

    temp.push_back(data[d[index] - '0'][i]);
    backtracking(ans, d, index + 1, 0, temp);
    temp.pop_back();
    backtracking(ans, d, index, i + 1, temp);
}

vector<string> letterCombinations(string digits) {
    vector<string> ans;
    if (digits.length() == 0)
        return {};
    else if (digits.length() == 1) {
        for (int i = 0; i < data[digits[0] - '0'].length(); i++)
            ans.push_back(string(1, data[digits[0] - '0'][i]));
        return ans;
    }
    string temp;
    int len = digits.length();
    backtracking(ans, digits, 0, 0, temp);
    return ans;
}

int main() {
    string dig = "234";
    vector<string> a = letterCombinations(dig);
    for(int i = 0;i < a.size();i++){
        cout << a[i] << ", ";
          }
}