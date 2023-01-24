#include<bits/stdc++.h>

using namespace std;

string convert(string s, int numRows) {
    string a[numRows];
    int i = 0;
    while(i < s.length()){
        for(int j = 0;j < numRows;j++){
            if(i < s.length()){ 
                a[j].append(1, s[i]);
                i++;
            }
            else{
                break;
            }
        }
        for(int k = numRows - 2;k > 0;k--){
            if (i < s.length()) {
                a[k].append(1, s[i]);
                i++;
            }
            else{ 
                break;
            }
        }
    }
    for(i = 1;i < numRows;i++){
        a[0].append(a[i]);
    }
    return a[0];
}

int main(){
    cout << convert("PAYPALISHIRING", 4);
}