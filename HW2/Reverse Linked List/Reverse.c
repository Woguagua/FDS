//The function required
List Reverse( List L ){
    if(L->Next == NULL)     return L;
    Position nodego , node1 , node2;
    nodego = L->Next;
    node1 = nodego;
    nodego = nodego->Next;
    node2 = nodego;
    int a = 0;
    while(nodego != NULL){
        nodego = nodego->Next;
        node2->Next = node1;
        if(a++ == 0)    node1->Next =NULL;
        node1 = node2;
        node2 = nodego;
    }
    L->Next = node1;
    return L;
}


