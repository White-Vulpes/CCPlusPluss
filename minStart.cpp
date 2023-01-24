#include<iostream>

using namespace std;

long int minStart(long int arr[], long int n){
    long int ans = 0;
    if(arr[0] >= 0) ans = 1;
    else ans = arr[0] * -1 + 1;
    while(1){
        for(int i = 0;i < n;i++){
            ans = ans + arr[i];
        }
    }
    return ans;
}

int main(){
    long int n = 10;
    long int arr[10] = {-5, 4, -2, 3, 1, -1, -6, -1, 0, 5};
    cout << minStart(arr, n);
    return 0;
}

