#include <bits/stdc++.h>

using namespace std;

int lengthOfLongestSubstring(string s) { //dvdf
    int temp = 0, max = 0, start = 0;
    bool flag = true;
    if(s.length() == 0)return 0;
    for (int i = 0; i < (s.length()); i++){
        cout << "For : " << i << "\n";
        for(int j = start;j < i; j++){
            cout << s[j] << " : " << s[i] << " : " << i << " : " << j << "\n";
            if(s[j] == s[i]){
                if(temp + 1 > max){
                    max = temp;
                }
                start = j + 1;
                temp = 0;
                flag = false;
                break;
            }else{
                flag = true;
            }
        }
        //cout << "Temp : " << temp << "\n";
        if(flag){
            temp++;
            flag = false;
        }
        cout << "Temp : " << temp << "\n";
        if(i == s.length() - 1 && temp + 1 > max){
            max = temp + 1;
            break;
        }
    }
    return max;
}

int main() {
                         
    string a = "qwwkew";


    cout << lengthOfLongestSubstring(a);
}