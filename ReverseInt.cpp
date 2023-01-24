#include<bits/stdc++.h>

using namespace std;

int reverse(int x) {
    int num = x,reverse = 0;
    while(x != 0){
        int p = x % 10;
        x = x / 10;
        reverse = (reverse * 10) + p;
        if(reverse > INT32_MAX || reverse < INT32_MIN) return 0;
    }
    return reverse;
}

int main(){
    cout << reverse(INT32_MAX);
}