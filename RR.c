#include <stdio.h>

int bt[4] = { 21, 3, 6, 2};
int btcheck[4] = { 21, 3, 6, 2};

int ts = 5;
int wt[4] = { 0, 0, 0, 0};
int tt[4] = { 0, 0, 0, 0};
int rt[4] = { 500, 500, 500, 500};

int p = -1, tim = 0;
float sum1=0,sum2 = 0,sum3 = 0;

int check(){
  int sum = 0;
  for (int i = 0; i < 4; i++){
      sum = sum + bt[i];
    }
  if (sum == 0){
      return 1;
    }
  return 0;
}

int processfinder(int pro){
        if(pro == 3){
            pro = 0;
        }
        else{
            pro++;
        }
    return pro;    
}

void waittime(int pro){
    for(int i = 0;i < 4;i++){
        if(i != pro){
            if(bt[i] != 0){
              wt[i]++;
            }
        }
    }
}

int main()
{
    while(check() == 0){
      do{
          p = processfinder(p);
      }while(bt[p] == 0);
      for(int i = 0;i < ts;i++){
            if(bt[p] != btcheck[p] && rt[p] == 500){
                rt[p] = tim - 1;
            }
            
            tim++;
            bt[p]--;
            waittime(p);
            if(bt[p] == 0){
                tt[p] = tim ;
                break;
            }
            
      }
    }
    for (int i = 0; i < 4; i++){
      sum1 = sum1 + wt[i];
      sum2 = sum2 + tt[i];
      sum3 = sum3 + rt[i];
    }
    
    printf("Average Waiting Time = %.2f\n",sum1/4);
    printf("Average Turnaround Time = %.2f\n",sum2/4);
    printf("Average Response Time = %.2f\n",sum3/4);
    return 0;
}
