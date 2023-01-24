#include <stdio.h>

int bt[5] = {6, 2, 8, 3, 4};
int at[5] = {2, 5, 1, 0, 4};
int wt[5] = {0, 0, 0, 0, 0};
int rq[5] = {0, 0, 0, 0 , 0};
int tim = 0,a = 0;
int p = 0;
float sum1 = 0;

int check(){

  int sum = 0;

  for (int i = 0; i < 5; i++){
      sum = sum + bt[i];
    }
  if (sum == 0){
      return 1;
    }
  return 0;
}

void processfinder(){
  int min = 100;
   for(int i = 0;i < a; i++){
      if(bt[rq[i]] < min && bt[rq[i]] != 0){
        min = bt[rq[i]];
        p = rq[i];
      }
   }
   
}

void waittime(){
    for(int i = 0;i < 5;i++){
        if(i != p){
            if(bt[i] != 0 && at[i] < tim){
              wt[i]++;
            }
        }
    }
}

int main(){
    int i = 0;
    while(!check()){
      if(bt[p] == 0){
        processfinder();
      }
      else{
        int flag = 0;
        for(int i = 0;i < 5;i++){
         if(tim == at[i]){
           rq[a] = i;
           a++;
           flag = 1;
         }
        }
        if(flag == 1){
          processfinder();
        }
      }
      bt[p]--;
      tim++;
      waittime();
       
    }
    for (int i = 0; i < 5; i++){
      sum1 = sum1 + wt[i];
    }
    printf("Average Waiting Time = %.2f\n",sum1/5);
    return 0;
}