//The function required
Deque CreateDeque(){
    Deque newdeque;
    PtrToNode head;
    head = malloc(sizeof(struct Node));
    head->Next = NULL;
    head->Last = NULL;
    newdeque = malloc(sizeof(struct DequeRecord));
    newdeque->Front = head;
    newdeque->Rear = head;
    return newdeque;
}