#include<stdio.h>
#include<string.h>

int main(){
    int t = 0;
    scanf("%d",&t);
    for(int a = 1; a <= t;a++){
        char stack[100];
        int ans = 0;
        scanf("%s",stack);
        int l = strlen(stack);
        for(int i = 0;i < l; i++){
            char st = stack[0];
            if(st != stack[i]){
                for(int j = 0;j < i;j++){
                    stack[j] = stack[i];
                }
                ans++;
                i = 0;
            }
        }
        if(stack[0] == '-'){
            ans++;
        }
        printf("case #%d: %d\n",a,ans);
    }
}