//The function required
int IsEmpty( Stack S, int Stacknum ){
    if(Stacknum == 1){
        if(S->Top1 == 0)    return 1;
    }
    else if(Stacknum == 2){
        if(S->Top2 == S->Top1)    return 1;
    }
    return 0;
}//empty:return 1,not empty:return 0