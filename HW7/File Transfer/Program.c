//The program required
#include<stdio.h>
#include<stdlib.h>
int N;
int numbers[300000];
void Initial();
int Find(int num);
void Connect(int num1,int num2);
int CalClasses();
int main(){
    int num1,num2;
    int classes;
    scanf("%d",&N);
    char operation;
    Initial();
    scanf("%c%c",&operation,&operation);
    while(operation != 'S'){
        scanf(" %d %d",&num1,&num2);
        if(operation == 'C'){
            if(Find(num1) == Find(num2))    printf("yes\n");
            else                            printf("no\n");
        }
        if(operation == 'I'){
            Connect(num1,num2);
        }
        scanf("%c%c",&operation,&operation);
    }
    classes = CalClasses();
    if(classes == 1)        printf("The network is connected.");
    else                    printf("There are %d components.",classes);
}

void Initial(){
    int i;
    for(i = 1;i <= N;i++){
        numbers[i] = -1;
    }
}

int Find(int num){
    if(numbers[num] < 0)    return num;
    int root = numbers[num];
    while(numbers[root] > 0){
        root = numbers[root];
    }
    return root;
}
void Connect(int num1,int num2){
    int root1,root2;
    root1 = Find(num1);
    root2 = Find(num2);
    if(abs(numbers[root1]) >= abs(numbers[root2])){
        numbers[root1] += numbers[root2];
        numbers[root2] = root1;
    }
    else{
        numbers[root2] += numbers[root1];
        numbers[root1] = root2;
    }
}
int CalClasses(){
    int i;
    int class = 0;
    for(i = 1;i <= N;i++){
        if(numbers[i] < 0)  class++;
    }
    return class;
}
