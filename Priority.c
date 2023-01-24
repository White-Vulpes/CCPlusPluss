#include <stdio.h>

//Variable Initialisation
int tim = 0;
int bt[5] = { 6, 12, 1, 3, 4};
int prio[5] = { 2, 4, 5, 1, 3};
int p = 0;
int wt[5] = { 0, 0, 0, 0, 0};
int tt[5] = { 0, 0, 0, 0, 0};
int rt[5] = { 0, 0, 0, 0, 0};
float sum1=0,sum2 = 0,sum3 = 0;

//This method finds the nest process to be executed
int processfinder(){

    int min = prio[0];
    int i = 0;
    int pro = 0;

    for(i = 0; i < 5; i++){
        if(prio[i] < min){
            if(bt[i] != 0){ 
               min = prio[i];
               pro = i;
            }
            else{
                prio[i] = 10;
            }
        }
    }
    return pro;
}

//This method checks whether all process are completed
int check(){

  int sum = 0;

  for (int i = 0; i < 3; i++){
      sum = sum + bt[i];
    }
  if (sum == 0){
      return 1;
    }
  return 0;
}

//This method adds waitime of the process
void waittime(int pro){

    for(int i = 0;i < 5;i++){
        if(i != pro){
            if(bt[i] != 0){
              wt[i] = wt[i] + bt[p];
            }
        }
    }
}

int main(){
    int i = 0;
    while (i != 5){
        p = processfinder();
        prio[p] = 10;
        rt[p] = tim;
        tim = tim + bt[p];
        tt[p] = tim;
        waittime(p);
        bt[p] = 0;
        i++;
    }

    for (int i = 0; i < 5; i++){
      sum1 = sum1 + wt[i];
      sum2 = sum2 + tt[i];
      sum3 = sum3 + rt[i];
    }
    
    //Printing the values
    printf("Average Waiting Time = %.2f\n",sum1/5);
    printf("Average Turnaround Time = %.2f\n",sum2/5);
    printf("Average Response Time = %.2f\n",sum3/5);
    return 0;
}