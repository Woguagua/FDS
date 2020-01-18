//The function required
ElementType Pop( Deque D ){
    if(D->Front == D->Rear)     return ERROR;
    ElementType val;
    val = D->Front->Next->Element;
    if(D->Front->Next == D->Rear){
        D->Front->Next = NULL;
        D->Rear = D->Front;
    }
    else{
        D->Front->Next = D->Front->Next->Next;
        D->Front->Next->Last = D->Front;
    }
    return val;
}