#include<iostream>

using namespace std;

void targetSum(int arr[], int target, int n){
    int i,j,sum = 0;
    for(i = n-1,j = n-1;i >= 0;i--){
        if(sum > target){
            sum -= arr[j];
            j--;
        }
        else if(sum == target){
            cout << i << " " << j;
            return;
        }
        else{
            sum += arr[i];
        }
    }
}
int main(){
    int arr[] = {1, 2, 3, 7, 5};
    int n = 5, t = 12;
    targetSum(arr, t, n);
}