#include <stdio.h>
int all[5][3] = {{ 0, 1, 0},
 { 2, 0, 0},
 { 3, 0, 2},
 { 2, 1, 1},
 { 0, 0, 2}};
int max[5][3] = {{ 7, 5, 3},
 { 3, 2, 2},
 { 9, 0, 2},
 { 2, 2, 2},
 { 4, 3, 3}};
int avail[3] = { 3, 3, 2};
int need[5][3] = {0}, flag = 0;
int ans[3] = { 10, 6, 7};
int safeseq[5] = {0},a = 0;
int main(){
 for(int i = 0;i < 5;i++){
 for(int j = 0;j < 3;j++){
 need[i][j] = max[i][j] - all[i][j];
 }
 }
 printf("Available Queue\n");
 while(flag == 0){
 flag = 1;
 for(int i = 0;i < 5;i++){
 int f = 1;
 for(int j = 0;j < 3;j++){
 if(!(need[i][j] <= avail[j] && all[i][j] != -1)){
 f = 0;
 break;
 }
 }
 if(f == 1){
 for(int p = 0;p < 3;p++){
 avail[p] += all[i][p];
 all[i][p] = -1;
 printf("%d ",avail[p]);
 }
 printf("\n");
 safeseq[a] = i;
 a++;
 flag = 0;
 }
 }
 }
 printf("\nNeed Queue\n");
 for(int i = 0;i < 5;i++){
 for(int j = 0;j < 3;j++){
 printf("%d ", need[i][j]); //Prints Need Array
 }
 printf("\n");
 }
 printf("\nSafe Sequence \n");
 for(int j = 0;j < 5;j++){
 printf("%d ", safeseq[j]); //Prints safesequence Array
 }
 for(int i = 0;i < 3; i++){
 if(avail[i] != ans[i]){
 flag = 0;
 break;
 }
 }
 if(flag = 1){
 printf("\n\nSystem is Safe");
 }
 else
 printf("\n\nSystem is not safe");
}