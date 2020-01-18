//The function required
int Push( ElementType X, Deque D ){
    PtrToNode node;
    node = malloc(sizeof(struct Node));
    node->Element = X;
    if(D->Front == D->Rear){
        D->Rear = node;
        D->Front->Next = D->Rear;
        D->Rear->Last = D->Front;
        D->Rear->Next = NULL;
    }
    else{
        node->Next = D->Front->Next;
        D->Front->Next->Last = node;
        node->Last = D->Front;
        D->Front->Next = node;
    }
    return 1;
}