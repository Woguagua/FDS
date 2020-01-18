//The function required
Polynomial Add( Polynomial a, Polynomial b );
Polynomial Add(Polynomial a, Polynomial b){
    if(a->Next == NULL)         return b;
    else if(b->Next == NULL)    return a;
    Polynomial HEAD = NULL;
    Polynomial node = NULL;
    if(a->Next->Exponent >= b->Next->Exponent){
        HEAD = a;
    }
    else{
        HEAD = b;
    }
    node = HEAD;
    a = a->Next;
    b = b->Next;
    while(a != NULL && b != NULL){
        while(a->Exponent > b->Exponent){
            node->Next = a;
            node = node->Next;
            a = a->Next;
        }
        while(a->Exponent < b->Exponent){
            node->Next = b;
            node = node->Next;
            b = b->Next;
        }
        if(a->Exponent == b->Exponent){
            a->Coefficient += b->Coefficient;
            if(a->Coefficient != 0){
                node->Next = a;
                node = node->Next;
            }
            a = a->Next;
            b = b->Next; 
        }
    }
    if(a == NULL)     node->Next = b;
    else if(b ==NULL) node->Next = a;
    return HEAD;
}
