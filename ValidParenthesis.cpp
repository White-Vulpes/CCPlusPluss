#include<iostream>

using namespace std;

int i = 0;
string lookingFor = "";

bool isValid(string s){
    if(s.length() < i){
        if(lookingFor.length() == 0 && s[i] == '{' && s[i] == '(' && s[i] == '['){
            lookingFor.push_back(s.at(i));
        }
        
    }
}

int main(){
    string s = "()";
    isValid(s);
    return 0;
}