//The required program
#include<stdio.h>
#include<stdlib.h>
int Inorder(int *sequence,int length,int M );
int main(){
    int M,N,K;
    int i;
    scanf("%d %d %d",&M,&N,&K);
    int sequence[N];
    int times = 0;
    while(times++<K){
        for(i = 0;i < N;i++){
            scanf("%d",&sequence[i]);
        }
        if(Inorder(sequence,N,M))   printf("YES");
        else            printf("NO");
        if(times != K)  printf("\n");
    }
}

int Inorder(int *sequence,int length,int M ){
    int newstack[M+1];
    int top = 0;
    int i = 0;
    int j = 0;
    int max = sequence[0];
    for(i = 1;i <= max;i++){
        newstack[top] = i;
        top++;
        if(top > M)     return 0;
    }
    top--;
    while(j < length){
        if(sequence[j] <= max){
            if(sequence[j] == newstack[top]){
                top--;
                j++;
            }
            else    return 0;
        }
        else if(sequence[j] > max){
            for(i = max+1;i <= sequence[j];i++){
                top++;
                if(top > (M-1))     return 0;
                newstack[top] = i;
            }
            max = sequence[j];
        }
        if(top > (M-1)) return 0;
    }
    return 1;
}