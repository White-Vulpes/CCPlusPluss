#include<bits/stdc++.h>

using namespace std;

string longestCommonPrefix(vector<string> &strs) {
    string ans = "";
    bool flag = true;
    for(int i = 0;i < strs[0].size();i++){
        char s = strs[0][i];
        for(int j = 1;j < strs.size();j++){
            if(strs[j][i] == s){
                flag = true;
            }
            else{
                flag = false;
                break;
            }
        }
        if(!flag){
            return ans;
        }else{
            ans.push_back(s);
        }
    }
    return ans;
}
int main(){
    vector<string> s = {{"dog"}, {"dog"}, {"dog"}};
    cout << longestCommonPrefix(s);
}