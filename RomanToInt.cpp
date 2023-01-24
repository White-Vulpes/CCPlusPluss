#include <bits/stdc++.h>

using namespace std;

int romanToInt(string s) {
    int ans = 0;
    for (int i = s.size(); i >= 0; i--) {
        if (s[i] == 'I')
            ans++;
        else if (s[i] == 'V') {
            if (i != 0) {
                if (s[i - 1] == 'I') {
                    ans += 4;
                    i--;
                } else
                    ans += 5;
            } else
                ans += 5;
        } else if (s[i] == 'X') {
            if (i != 0) {
                if (s[i - 1] == 'I') {
                    ans += 9;
                    i--;
                } else
                    ans += 10;
            } else
                ans += 10;
        } else if (s[i] == 'L')
            ans += 50;
        else if (s[i] == 'C') {
            if (i != 0) {
                if (s[i - 1] == 'X') {
                    ans += 90;
                    i--;
                } else
                    ans += 100;
            } else
                ans += 100;
        } else if (s[i] == 'D')
            ans += 500;
        else if (s[i] == 'M') {
            if (i != 0) {
                if (s[i - 1] == 'C') {
                    ans += 900;
                    i--;
                } else
                    ans += 1000;
            } else
                ans += 1000;
        }
    }
    return ans;
}

int main() {
    cout << romanToInt("MCDLXXVI");
}