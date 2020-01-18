//The function required
int Inject( ElementType X, Deque D ){
    PtrToNode node;
    node = malloc(sizeof(struct Node));
    node->Element = X;
    node->Last = D->Rear;
    D->Rear->Next = node;
    node->Next = NULL;
    D->Rear = node;
    return 1;
}