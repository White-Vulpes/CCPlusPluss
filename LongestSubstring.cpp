#include<iostream>

using namespace std;

int longestSubstring(string s){
    int start = (int)(s[0]),count = (int)(s[0] + 1), max = 0;
    for(int i = 1;i < s.length(); i++){
        if(s[i] == count){
            count++;
        }
        else if(max < count - start){
            max = count - start;
            count = (int)(s[i] + 1);
            start = (int)(s[i]);
        }
        else{
            count = (int)(s[i] + 1);
            start = (int)(s[i]);
        }
    }
    if(count - start > max) return count - start;
    return max;
}

int main(){
    string s = "abacaba";
    cout << longestSubstring(s);
    return 0;
}