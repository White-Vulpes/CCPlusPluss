#include<bits/stdc++.h>

using namespace std;

string intToRoman(int num) {
    string ans;
    int i = 1;
    while(num > 0){
        int x = num % (int)pow(10, i);
        num -= x;
        i++;
        if(x < 5){
            if(x == 4){
                ans.insert(0, "IV");
            }
            else{
                for(int i = 0;i < x;i++){
                    ans.insert(0, "I");
                }
            }
        }
        else if(x < 10){
            if(x == 9) ans.insert(0, "IX");
            else{
                x -= 5;
                for (int i = 0; i < x; i++) {
                    ans.insert(0, "I");
                }
                ans.insert(0, "V");
            }
        } else if (x < 50) {
            if (x == 40)
                ans.insert(0, "XL");
            else {
                x = x / 10;
                for (int i = 0; i < x; i++) {
                    ans.insert(0, "X");
                }
            }
        } else if (x < 100) {
            if (x == 90)
                ans.insert(0, "XC");
            else {
                x -= 50;
                x = x / 10;
                for (int i = 0; i < x; i++) {
                    ans.insert(0, "X");
                }
                ans.insert(0, "L");
            }
        } else if (x < 500) {
            if (x == 400)
                ans.insert(0, "CD");
            else {
                x = x / 100;
                for (int i = 0; i < x; i++) {
                    ans.insert(0, "C");
                }
            }
        } else if (x < 1000) {
            if (x == 900)
                ans.insert(0, "CM");
            else {
                x -= 500;
                x = x / 100;
                for (int i = 0; i < x; i++) {
                    ans.insert(0, "C");
                }
                ans.insert(0, "D");
            }
        } else {
            x = x / 1000;
            for(int i = 0; i < x; i++){
                ans.insert(0, "M");
            }
        }
    }
    return ans;
}

int main(){
    cout << intToRoman(404);
}