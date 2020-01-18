//The program required
#include <stdio.h>
#include <stdlib.h>
struct TNode{
    int Key;
    struct TNode * Left;
    struct TNode * Right;
};
typedef struct TNode *BinTree;
BinTree BuildTree(int N);//Build a tree by enter the numbers one by one,
                    //it will build a binary search tree.
BinTree Insert(int NewData,BinTree T);//Insert the newdata into the tree
int * Preorder(BinTree T,int N);
int Compare(int *Out1,int *Out2);
int main(){
    int N,L;
    int i;
    int first = 1;
    int over = 0;
    BinTree Origin,New;
    int * stout;
    int * nout;
    while(!over){
        scanf("%d %d",&N,&L);
        Origin = BuildTree(N);
        stout = Preorder(Origin,N);
//        printf("[%d %d %d %d]",stout[1],stout[2],stout[3],stout[4]);
        for(i = 1;i <=L;i++){
            New = BuildTree(N);
            if(New->Key == 0){
                over = 1;
                break;
            }
            if(!first)      printf("\n");
            first = 0;
            nout = Preorder(New,N);
//            printf("[%d %d %d %d]",nout[1],nout[2],nout[3],nout[4]);
            if(Compare(stout,nout))     printf("Yes");
            else                        printf("No");
        }
    }
}

BinTree BuildTree(int N){
    BinTree T;
    int i;
    int NewData;
    T = (BinTree)malloc(sizeof(struct TNode));
    scanf("%d",&T->Key);
    T->Left = NULL;
    T->Right = NULL;
    if(T->Key == 0)     return T;
    for(i = 2;i <= N;i++){
        scanf("%d",&NewData);
        if(NewData == 0)    break;
        T = Insert(NewData,T);
    }
    return T;
}

BinTree Insert(int NewData,BinTree T){
    if(T == NULL){
        T = (BinTree)malloc(sizeof(struct TNode));
        T->Key = NewData;
        T->Left = NULL;
        T->Right = NULL;
    }
    else{
        if(NewData < T->Key){
            T->Left = Insert(NewData,T->Left);
        }
        else if(NewData > T->Key){
            T->Right = Insert(NewData,T->Right);
        }
    }
    return T;
}

int * Preorder(BinTree BT,int N){
    BinTree S[N+1];
    int top = 1;
    BinTree T = BT;
    int *out;
    out = malloc((N+2)*sizeof(int));
    out[0] = 2019;
    int i = 1;
    S[top++] = T;
    while(top > 1){
        T = S[--top];
        out[i++] = T->Key;
        if(T->Right)     S[top++] = T->Right;
        if(T->Left)    S[top++] = T->Left;
    }
    out[i] = 0;
    return out;
}


int Compare(int *Out1,int *Out2){
    int i = 1;
    while(Out1[i] || Out2[i]){
        if(Out1[i] != Out2[i])  return 0;
        i++;
    }
    return 1;
}
