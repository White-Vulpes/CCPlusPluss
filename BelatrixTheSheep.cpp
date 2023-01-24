#include<stdio.h>
#include<math.h>
#include<string>
#include<stdlib.h>

using namespace std;

/*

Bleatrix Trotter the sheep has devised a strategy that helps her fall asleep faster. First, she picks a number N. Then she starts naming N, 2 × N, 3 × N, and so on. Whenever she names a number, she thinks about all of the digits in that number. She keeps track of which digits (0, 1, 2, 3, 4, 5, 6, 7, 8, and 9) she has seen at least once so far as part of any number she has named. Once she has seen each of the ten digits at least once, she will fall asleep.

Bleatrix must start with N and must always name (i + 1) × N directly after i × N. For example, suppose that Bleatrix picks N = 1692. She would count as follows:

N = 1692. Now she has seen the digits 1, 2, 6, and 9.
2N = 3384. Now she has seen the digits 1, 2, 3, 4, 6, 8, and 9.
3N = 5076. Now she has seen all ten digits, and falls asleep.
What is the last number that she will name before falling asleep? If she will count forever, print INSOMNIA instead.

Input
The first line of the input gives the number of test cases, T. T test cases follow. Each consists of one line with a single integer N, the number Bleatrix has chosen.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the last number that Bleatrix will name before falling asleep, according to the rules described in the statement.

Limits
Time limit: 20 seconds per test set.
Memory limit: 1 GB.
1 ≤ T ≤ 100.
Small dataset (Test Set 1 - Visible)
0 ≤ N ≤ 200.
Large dataset (Test Set 2 - Hidden)
0 ≤ N ≤ 106.
Sample

Input
 	
Output
 
5
0
1
2
11
1692

  
Case #1: INSOMNIA
Case #2: 10
Case #3: 90
Case #4: 110
Case #5: 5076

*/

int check(int ans[]){
    int flag = 1;
    for(int i = 0; i < 10;i++){
        if(ans[i] != 1){
            flag = 0;
            break;
        }
    }
    return flag;
}

int main(){
    int t = 0;
    scanf("%d",&t);
    for(int a = 0;a < t;a++){
        int ans[10] = {0};
        int n = 2,maxi = 0;
        scanf("%d",&n);
        for(int i = 1;i <= 6;i++){
            maxi = pow(10,i);
            if(maxi > n){
                break;
            }
        }
        maxi = 9 * maxi;
        for(int i = 1;i <= maxi;i++){
            string num = to_string(i * n);
            int l = num.length();
            for(int j = 0;j < l;j++){
                ans[num[j] - '0'] = 1; 
            }
            if(check(ans)){
                printf("case #%d: %d\n",a+1,i * n);
                maxi = 1;
                break;
            }
        }
        if(maxi != 1){
            printf("case #%d: INSOMNIA\n",a+1);
        }
    }
}