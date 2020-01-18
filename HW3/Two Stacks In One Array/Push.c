//The function required
int Push( ElementType X, Stack S, int Stacknum ){
    int i = 0;
    if( IsFull(S) )     return 0;
    if(Stacknum ==1){
        i = S->Top2;
        while(i != S->Top1){
            S->Array[i+1] = S->Array[i];
            i--;
        }
        S->Top1 = S->Top1 + 1;
        S->Array[S->Top1] = X;
        S->Top2 = S->Top2 + 1;
    }
    else if(Stacknum == 2){
        S->Top2 = S->Top2 + 1;
        S->Array[S->Top2] = X;
    }
//    printf("Top1:%d Top2:%d",S->Top1,S->Top2);
    
    return 1;
}