//The function required
int IsFull( Stack S ){
    if(S->Top2 == S->Capacity)    return 1;
    return 0;
}//full:return1,not full:return 0