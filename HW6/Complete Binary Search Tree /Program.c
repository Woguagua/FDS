//The program required
#include<stdio.h>
#include<stdlib.h>
void sort(int * num,int N);
void change(int * num,int N,int i);
int level[1000];
int index = 1;
int main(){
    int N;
    int i;
    scanf("%d",&N);
    int num[N+1];
    int output[N+1];
    for(i = 1;i <= N;i++){
        scanf("%d",&num[i]);
    }
    sort(num,N);
    change(num,N,1);
    for(i = 1;i < N;i++){
        printf("%d ",level[i]);
    }
    printf("%d",level[i]);
}
void sort(int*num,int N){
    int i,j;
    int temp;
    for(i = 1;i <=N;i++){
        for(j = i+1;j <= N;j++){
            if(num[j] < num[i]){
                temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }
}
void change(int * num,int N,int i){
    if(i > N)   return;
    change(num,N,2 * i);
    level[i] = num[index++];
    change(num,N,2 * i + 1);
}
