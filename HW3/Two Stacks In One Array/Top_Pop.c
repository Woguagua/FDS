//The function required
ElementType Top_Pop( Stack S, int Stacknum ){
    int num;
    int i;
    if(Stacknum == 1){
        if( IsEmpty(S,1) )      return ERROR;
        num = S->Array[S->Top1];
        i = S->Top1;
        S->Top1 = S->Top1 - 1;
        while(i != S->Top2){
            S->Array[i] = S->Array[i+1];
            i++;
        }
        S->Top2 = S->Top2 - 1;
        
//        printf("Top1:%d Top2:%d",S->Top1,S->Top2);
        
		return num;
    }
    else if(Stacknum == 2){
        if( IsEmpty(S,2) )      return ERROR;
        num = S->Array[S->Top2];
        S->Top2 = S->Top2 - 1;
        
//        printf("Top1:%d Top2:%d",S->Top1,S->Top2);
        
        return num;
    }
}