#include<stdio.h>

int bt[5] = {5, 24, 16, 10, 3};
float wt = 0;
float tt = 0;
float turn = 0;

int main(){
    for(int i = 0;i < 5;i++){
        wt = wt + bt[i] * (4 - i);
        tt = tt + bt[i];
        bt[i] = 0;
    }
    turn = turn + tt + wt;
    printf("Waiting Time %.2f \nThroughput Time %.2f \nTurnaround Time %.2f",wt/5,tt/5,turn/5);
}