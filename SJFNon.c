#include <stdio.h>
int bt[4] = {7, 4, 1, 4};
int at[4] = {0, 2, 4, 5};
int wt[4] = {0, 0, 0, 0};
int tim = 0;
int p = 0;
float sum1 = 0;
int processfinder() {
    int min = bt[0];
    int pro = 0;
    for (int i = 0; i < 4; i++) {
        if (at[i] <= tim) {
            if (bt[i] < min) {
                min = bt[i];
                pro = i;
            }
        }
    }
    return pro;
}
int main() {
    int i = 0;
    while (i != 4) {
        p = processfinder();
        wt[p] = tim - at[p];
        at[p] = 17;
        tim = tim + bt[p];
        //printf("process %d\n",p);
        i++;
    }
    for (int i = 0; i < 4; i++) {
        sum1 = sum1 + wt[i];
    }
    printf("Average Waiting Time = %.2f\n", sum1 / 4);
    return 0;
}