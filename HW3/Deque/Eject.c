//The function required
ElementType Eject( Deque D ){
    if(D->Front == D->Rear)     return ERROR;
    ElementType val;
    val = D->Rear->Element;
    D->Rear = D->Rear->Last;
    D->Rear->Next = NULL;
    return val;
}