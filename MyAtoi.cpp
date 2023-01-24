#include <bits/stdc++.h>

using namespace std;

int myAtoi(string s) {
    string ans;
    signed long long a = 0;
    int i = 0;
    bool isPositive = true;
    for (i = 0; i < s.length(); i++) {
        if (s[i] == ' ')
            continue;
        if (s[i] == '-') {
            isPositive = false;
            i++;
            break;
        } else if (s[i] == '+') {
            i++;
            break;
        } else {
            break;
        }
    }
    cout << isPositive << endl;
    for (; i < s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            ans.append(1, s[i]);
        } else {
            break;
        }
    }
    for (i = 0; i < ans.length(); i++) {
        int p = ans[i] - '0';
        if (!isPositive) {
            a = (a * 10) - p;
        } else {
            a = (a * 10) + p;
        }
        if (a > INT32_MAX || a < INT32_MIN) {
            if (!isPositive)
                return INT32_MIN;
            return INT32_MAX;
        }
    }
    return a;
}
int main() {
    cout << myAtoi("2147483648");
}